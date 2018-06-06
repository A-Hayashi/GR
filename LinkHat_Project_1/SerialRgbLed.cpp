#include "SerialRgbLed.h"

#ifdef USE_DISPLAY_SINGLE_RGB_LED

/* コンストラクタ */
SerialRgbLed::SerialRgbLed(int sigPin)
{
    _sigPin     = sigPin;
#if defined(USE_DISPLAY_SINGLE_RGB_LED)
    _strip = new Adafruit_NeoPixel(1,_sigPin, NEO_RGB+NEO_KHZ800);
#endif // defined(USE_DISPLAY_SINGLE_RGB_LED)
}

/* 初期化処理 */
void SerialRgbLed::begin(void)
{
    Serial.println("SerialRgbLed.begin()");

#if defined(USE_DISPLAY_SINGLE_RGB_LED)
    //カラーLED初期化
    _strip->begin();
    _strip->setBrightness(50);
#endif // defined(USE_DISPLAY_SINGLE_RGB_LED)
}

void SerialRgbLed::_update(void)
{
#if defined(USE_DISPLAY_SINGLE_RGB_LED)
    _strip->setPixelColor(0, _data.rgb8.red, _data.rgb8.green, _data.rgb8.blue);
    _strip->show();
#endif // defined(USE_DISPLAY_SINGLE_RGB_LED)
}

void SerialRgbLed::setLed(disp_pixel_data_t data)
{
    _data = data;
}

/* 周期実行処理 */
#define CYCLIC_INTERVAL 1
void SerialRgbLed::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
    if (cntdown == 0)
    {
        _update();   

        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}

#endif // USE_DISPLAY_SINGLE_RGB_LED

