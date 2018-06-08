#include "RGBMatrixLed32x32.h"

#ifdef USE_DISPLAY_COLOR_MATRIX_32X32

/* コンストラクタ */
RGBMatrixLed32x32::RGBMatrixLed32x32(int pinClk,  int pinLat,  int pinOe, int pinR0,  int pinG0,  int pinB0, 
               int pinR1,  int pinG1,  int pinB1, int pinA0,  int pinA1,  int pinA2,  int pinA3)
{
    _pinClk = pinClk;
    _pinLat = pinLat;
    _pinOe = pinOe;

    _pinA0 = pinA0;
    _pinA1 = pinA1;
    _pinA2 = pinA2;
    _pinA3 = pinA3;

    _pinR0 = pinR0;
    _pinG0 = pinG0;
    _pinB0 = pinB0;

    _pinR1 = pinR1;
    _pinG1 = pinG1;
    _pinB1 = pinB1;
}

/* 初期化処理 */
void RGBMatrixLed32x32::begin(void)
{
    Serial.println("RGBMatrixLed32x32.begin()");

    pinMode(_pinR0, OUTPUT);
    pinMode(_pinG0, OUTPUT);
    pinMode(_pinB0, OUTPUT);

    pinMode(_pinR1, OUTPUT);
    pinMode(_pinG1, OUTPUT);
    pinMode(_pinB1, OUTPUT);

    pinMode(_pinClk, OUTPUT);
    pinMode(_pinLat, OUTPUT);
    pinMode(_pinOe, OUTPUT);

    pinMode(_pinA0, OUTPUT);
    pinMode(_pinA1, OUTPUT);
    pinMode(_pinA2, OUTPUT);
    pinMode(_pinA3, OUTPUT);

    digitalWrite(_pinClk, LOW);
    digitalWrite(_pinLat, LOW);
    digitalWrite(_pinOe, LOW);

    digitalWrite(_pinA0, LOW);
    digitalWrite(_pinA1, LOW);
    digitalWrite(_pinA2, LOW);
    digitalWrite(_pinA3, LOW);

}

void RGBMatrixLed32x32::_update(void)
{
    static uint8_t line = 0;
    static uint8_t dep = 0;
    uint8_t x;

    for (x = 0; x<32; x++)
    {
        digitalWrite(_pinR0, ((_dispRam[line   ][x].R != 0)? HIGH: LOW));
        digitalWrite(_pinR1, ((_dispRam[line+16][x].R != 0)? HIGH: LOW));
        digitalWrite(_pinG0, ((_dispRam[line   ][x].G != 0)? HIGH: LOW));
        digitalWrite(_pinG1, ((_dispRam[line+16][x].G != 0)? HIGH: LOW));
        digitalWrite(_pinB0, ((_dispRam[line   ][x].B != 0)? HIGH: LOW));
        digitalWrite(_pinB1, ((_dispRam[line+16][x].B != 0)? HIGH: LOW));
        digitalWrite(_pinClk, HIGH);
        digitalWrite(_pinClk, LOW);
    }
    digitalWrite(_pinOe, HIGH);
    digitalWrite(_pinLat, HIGH);
    digitalWrite(_pinLat, LOW);
    digitalWrite(_pinA0, ((line&1)?HIGH : LOW));
    digitalWrite(_pinA1, ((line&2)?HIGH : LOW));
    digitalWrite(_pinA2, ((line&4)?HIGH : LOW));
    digitalWrite(_pinA3, ((line&8)?HIGH : LOW));
    digitalWrite(_pinOe, LOW);
    
    line ++;
    if (line>=16)
    {
    	line = 0;
    	//if (dep>=10) dep=0; else dep++;		
    }
    //Serial.print("u");
}
//#define DEBUG_SET_PIXEL
void RGBMatrixLed32x32::setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data)
{
    //_dispRam

    //if (x < 0 || x > DISPLAY_WIDTH - 1 || y < 0 || y > DISPLAY_HEIGHT - 1) return;
#ifdef DEBUG_SET_PIXEL
  #if 0
    if (x == 0) Serial.println();
    if ((data.rgb8.red  >=0x80) || (data.rgb8.green  >=0x80) || (data.rgb8.blue  >=0x80)) Serial.print("O"); else Serial.print("-");
  #else
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.print(data.rgb8.red,16);
    Serial.print(",");
    Serial.print(data.rgb8.green,16);
    Serial.print(",");
    Serial.print(data.rgb8.blue,16);
    Serial.println("");
  #endif
#endif
    _dispRam[y][x].R = (data.rgb8.red  >=0x80)? 0xFFu: 0x00u;
    _dispRam[y][x].G = (data.rgb8.green>=0x80)? 0xFFu: 0x00u;
    _dispRam[y][x].B = (data.rgb8.blue >=0x80)? 0xFFu: 0x00u;

#ifdef DEBUG_SET_PIXEL
//    if (x == DISPLAY_WIDTH - 1 || y ==  DISPLAY_HEIGHT - 1) Serial.println();
#endif

}

/* 周期実行処理 */
#define CYCLIC_INTERVAL 0
void RGBMatrixLed32x32::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
//Serial.print("'");
    if (cntdown == 0)
    {
        _update();    

        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}
#endif // USE_DISPLAY_COLOR_MATRIX_32X32

