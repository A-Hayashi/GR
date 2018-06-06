#include "RedMatrixLed32x16.h"

#ifdef USE_DISPLAY_RED_MATRIX_32X16

#define DELAY_TIME 5
/* コンストラクタ */
RedMatrixLed32x16::RedMatrixLed32x16(int ena, int lat, int clk, int sin1, int sin2, int sin3)
{
    _pinEna     = ena;
    _pinLat     = lat;
    _pinClk     = clk;
    _pinSin1    = sin1;
    _pinSin2    = sin2;
    _pinSin3    = sin3;
}

/* 初期化処理 */
void RedMatrixLed32x16::begin(void)
{
    Serial.println("RedMatrixLed32x16.begin()");
}

void RedMatrixLed32x16::_disp(void)
{
    static int line = 0;

    digitalWrite(_pinEna,1);
    digitalWrite(_pinLat,0);

    _setSeriParaData( (1<<line), _dispRam[0][line], _dispRam[1][line]);
    digitalWrite(_pinLat,1);
    
    digitalWrite(_pinEna,0);

    delay(DELAY_TIME);    

    line++;
    if (line>= 16) line = 0;
}

void RedMatrixLed32x16::_setSeriParaData(uint16_t comData, uint16_t aData, uint16_t bData)
{
    int i;
    uint16_t bitData = 0x0001;

    for (i = 0; i<16; i++)
    {
        // クロックを "L" にしてから更新
        digitalWrite(_pinClk,0);

        // データを出力
        digitalWrite(_pinSin1, ( ( ( comData & bitData ) != 0 )? 1 : 0 ));
        digitalWrite(_pinSin2, ( ( ( aData   & bitData ) != 0 )? 1 : 0 ));
        digitalWrite(_pinSin3, ( ( ( bData   & bitData ) != 0 )? 1 : 0 ));

        // 立ち上がりでデータ反映
        digitalWrite(_pinClk,1);
        
        bitData<<=1;
    }
}

void RedMatrixLed32x16::_update(void)
{
    _disp();
}

void RedMatrixLed32x16::setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data)
{
    bool pixOn = (data.rgb8.red!=0x0)? true: false;

    if (x < 0 || x > DISPLAY_WIDTH - 1 || y < 0 || y > DISPLAY_HEIGHT - 1) return;

    if (pixOn) {
        _dispRam[x/16][y] |= (0x8000u>>(x%16));
    }
    else {
        _dispRam[x/16][y] &= ~(0x8000u>>(x%16));
    }
}

/* 周期実行処理 */
#define CYCLIC_INTERVAL 1
void RedMatrixLed32x16::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
    if (cntdown == 0)
    {
        _update();   

        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}
#endif // USE_DISPLAY_RED_MATRIX_32X16

