
#include "Display.h"

/* コンストラクタ */
Display::Display(void)
{
    _dev = NULL;
#ifdef USE_FONT
     _charactors = new Charactors();
     _clearDisp();
#endif // USE_FONT
    _motion = motion_none;
}

/* 初期化処理 */
void Display::begin(DisplayDevice* dev)
{
    Serial.println("Display.begin()");
    _dev = dev;
    
    if (_dev!= NULL) {
      _dev->begin();
    }
    _startIllumination();
}

/* ダイナミック点灯処理 */
void Display::update(void)
{
    if (_dev!= NULL) {
      _dev->cyclicHandler();
      //Serial.print("U");
    }
    //else Serial.print("*");
}

#ifdef USE_FONT

#define DEBUG_DRAW_CHAR
void Display::_clearDisp(void)
{
    memset(_localBuf, 0, sizeof(_localBuf));
}

void Display::_writeDisplay(int x, int y, int width, int height)
{
    int i, j;

    for (j = 0; j < height; j++) {
        for (i = 0; i< width; i++) {
            _dev->setPixel(x + i, y + j, _localBuf[x + i][y + j]);
        }
    }
}

/* キャラクターを描画 */
void Display::_drawChar(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, draw_mode_t mode, char num)
{
    int i,j;
    int width, height;

#ifdef DEBUG_DRAW_CHAR
    Serial.print("_drawChar(");
    Serial.print(font);
    Serial.print(",");
    Serial.print(x);
    Serial.print(",");
    Serial.print(y);
    Serial.print(",");
    Serial.print(num);
    Serial.println(")");
#endif // DEBUG_DRAW_CHAR    

    // ASCIIコード '@' を 0 としたときのキャラクター番号を表示する仕様とする。
    if (num < '@') return;

    _charactors->getSize(font, &width, &height);

    if (     width <=  8){
        uint8_t *pData = (uint8_t*)_charactors->getChar(font, num - '@');
        for (j = 0; j<height; j++)
        {
            for (i = 0; i<width; i++)
            {
                if (mode == draw_mode_layers) {
                    if (pixel.rgb8.red   != 0) {
                        _localBuf[x + i][y + j].rgb8.red   = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.red:   back.rgb8.red;    
                    }
                    if (pixel.rgb8.green != 0) {
                        _localBuf[x + i][y + j].rgb8.green = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.green: back.rgb8.green;    
                    }
                    if (pixel.rgb8.blue  != 0) {
                        _localBuf[x + i][y + j].rgb8.blue  = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.blue:  back.rgb8.blue;    
                    }
                }
                else
                {
                    _localBuf[x + i][y + j] = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel: back;    
                }
#ifdef DEBUG_DRAW_CHAR
                Serial.print(( (pData[j] & (1u << (width - i -1))) != 0)? "O": "_");    
#endif //DEBUG_DRAW_CHAR
            }
#ifdef DEBUG_DRAW_CHAR
            Serial.println();
#endif //DEBUG_DRAW_CHAR
        }
    }
    else if (width <= 16) {
        uint16_t *pData = (uint16_t*)_charactors->getChar(font, num - '@');
        for (j = 0; j<height; j++)
        {
            for (i = 0; i<width; i++)
            {
                if (mode == draw_mode_layers) {
                    if (pixel.rgb8.red   != 0) {
                        _localBuf[x + i][y + j].rgb8.red   = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.red:   back.rgb8.red;    
                    }
                    if (pixel.rgb8.green != 0) {
                        _localBuf[x + i][y + j].rgb8.green = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.green: back.rgb8.green;    
                    }
                    if (pixel.rgb8.blue  != 0) {
                        _localBuf[x + i][y + j].rgb8.blue  = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.blue:  back.rgb8.blue;    
                    }
                }
                else
                {
                    _localBuf[x + i][y + j] = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel: back;    
                }
#ifdef DEBUG_DRAW_CHAR
                Serial.print(( (pData[j] & (1u << (width - i -1))) != 0)? "O": "_");    
#endif //DEBUG_DRAW_CHAR
            }
#ifdef DEBUG_DRAW_CHAR
            Serial.println();
#endif //DEBUG_DRAW_CHAR
        }
    }     
    else if (width <= 32) {
        uint32_t *pData = (uint32_t*)_charactors->getChar(font, num - '@');
        for (j = 0; j<height; j++)
        {
            for (i = 0; i<width; i++)
            {
                if (mode == draw_mode_layers) {
                    if (pixel.rgb8.red   != 0) {
                        _localBuf[x + i][y + j].rgb8.red   = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.red:   back.rgb8.red;    
                    }
                    if (pixel.rgb8.green != 0) {
                        _localBuf[x + i][y + j].rgb8.green = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.green: back.rgb8.green;    
                    }
                    if (pixel.rgb8.blue  != 0) {
                        _localBuf[x + i][y + j].rgb8.blue  = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.blue:  back.rgb8.blue;    
                    }
                }
                else
                {
                    _localBuf[x + i][y + j] = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel: back;    
                }
#ifdef DEBUG_DRAW_CHAR
                Serial.print(( (pData[j] & (1u << (width - i -1))) != 0)? "O": "_");    
#endif //DEBUG_DRAW_CHAR
            }
#ifdef DEBUG_DRAW_CHAR
            Serial.println();
#endif //DEBUG_DRAW_CHAR
        }
    }
    else if (width <= 64) {
        uint64_t *pData = (uint64_t*)_charactors->getChar(font, num - '@');
        for (j = 0; j<height; j++)
        {
            for (i = 0; i<width; i++)
            {
                if (mode == draw_mode_layers) {
                    if (pixel.rgb8.red   != 0) {
                        _localBuf[x + i][y + j].rgb8.red   = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.red:   back.rgb8.red;    
                    }
                    if (pixel.rgb8.green != 0) {
                        _localBuf[x + i][y + j].rgb8.green = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.green: back.rgb8.green;    
                    }
                    if (pixel.rgb8.blue  != 0) {
                        _localBuf[x + i][y + j].rgb8.blue  = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel.rgb8.blue:  back.rgb8.blue;    
                    }
                }
                else
                {
                    _localBuf[x + i][y + j] = ( (pData[j] & (1u << (width - i - 1))) != 0)? pixel: back;    
                }
#ifdef DEBUG_DRAW_CHAR
                Serial.print(( (pData[j] & (1u << (width - i - 1))) != 0)? "O": "_");    
#endif //DEBUG_DRAW_CHAR
            }
#ifdef DEBUG_DRAW_CHAR
            Serial.println();
#endif //DEBUG_DRAW_CHAR
        }
    }
    else {
    }    
#ifdef DEBUG_DRAW_CHAR
    Serial.println();
#endif //DEBUG_DRAW_CHAR
    _writeDisplay(x, y, width, height);
}

/* 文字列を描画 */
void Display::_drawString(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, draw_mode_t mode, char* str)
{
    int width, height;

    _charactors->getSize(font, &width, &height);
    while (*str != '\0') {
        _drawChar( font, x, y, pixel, back, mode, *str);
        x += width;
        str++;
    }
}
#endif // USE_FONT

void Display::_startIllumination(void)
{
    _illuminationWait = 0;
    _illuminationStep = 0;
}

#define ILLUMINATION_WAIT 5
void Display::updateIillumination(void)
{
    DisplayDevice::disp_pixel_data_t pixelData;
    DisplayDevice::disp_pixel_data_t backData;
    
    if ( 0 == _illuminationWait)
    {
        _illuminationWait = ILLUMINATION_WAIT;

        backData.rgb8.red =0;
        backData.rgb8.green = 0;
        backData.rgb8.blue = 0;

        switch(_motion)
        {
            case motion_idle:    /* 待ち受け */
                pixelData.rgb8.red =   0x00u;
                pixelData.rgb8.green = 0x00u;
                pixelData.rgb8.blue =  0xFFu;
#ifdef USE_FONT
                _drawChar(
 #ifdef USE_FONT32X32
                        Charactors::font_type_32x32,
 #else // USE_FONT32X32
                        Charactors::font_type_32x16,
 #endif // USE_FONT32X32
                        0, 0, pixelData, backData, draw_mode_layers, '@');
#else // USE_FONT
#endif // USE_FONT
                break;
            case motion_yes:    /* いいね */
                pixelData.rgb8.red =   0x00u;
                pixelData.rgb8.green = 0x00u;
                pixelData.rgb8.blue =  0xFFu;
    #ifdef USE_FONT
              _drawChar(
     #ifdef USE_FONT32X32
                        Charactors::font_type_32x32,
                        0, 0, pixelData, backData, draw_mode_layers, 'H'+_illuminationStep);
     #else // USE_FONT32X32
                        Charactors::font_type_32x16,
                        0, 0, pixelData, backData, draw_mode_layers, 'H'+_illuminationStep);
     #endif // USE_FONT32X32

    #else // USE_FONT
    #endif // USE_FONT
                break;
            case motion_wonder:  /* ？ */
                pixelData.rgb8.red =   0x00u;
                pixelData.rgb8.green = 0x00u;
                pixelData.rgb8.blue =  0xFFu;
    #ifdef USE_FONT
              _drawChar(
     #ifdef USE_FONT32X32
                        Charactors::font_type_32x32,
                        0, 0, pixelData, backData, draw_mode_layers, 'H'+_illuminationStep);
     #else // USE_FONT32X32
                        Charactors::font_type_32x16,
                        0, 0, pixelData, backData, draw_mode_layers, 'H'+_illuminationStep);
     #endif // USE_FONT32X32

    #else // USE_FONT
    #endif // USE_FONT
                break;
            default:
                break;
        }
        _illuminationStep++;
        if (_illuminationStep>=ILLUMINATION_STEP_COUNT) _illuminationStep = 0;
    }
    else _illuminationWait--;
}

/* 動作を描く */
void Display::showMotion(motion_t motion)
{
    DisplayDevice::disp_pixel_data_t pixelData;
    DisplayDevice::disp_pixel_data_t backData;
    
    backData.rgb8.red =0;
    backData.rgb8.green = 0;
    backData.rgb8.blue = 0;
    _motion = motion;

    switch(_motion)
    {
        case motion_idle:    /* 待ち受け */
          _clearDisp();
          pixelData.rgb8.red =   0xFFu;
          pixelData.rgb8.green = 0xFFu;
          pixelData.rgb8.blue =  0xFFu;
#ifdef USE_FONT
          _drawString(Charactors::font_type_8x16,
 #ifdef USE_FONT32X32
              4, 8,
 #else // USE_FONT32X32
              4, 0,
 #endif // USE_FONT32X32
              pixelData, backData, draw_mode_overwrite, "CDC");
#else // USE_FONT
          if (_dev!= NUL) {
            _dev->setLed(pixelData);
          }
#endif // USE_FONT
          break;
        case motion_yes:    /* いいね */
          _clearDisp();
          pixelData.rgb8.red =   0x00u;
          pixelData.rgb8.green = 0xFFu;
          pixelData.rgb8.blue =  0x00u;
#ifdef USE_FONT
          _drawChar(
 #ifdef USE_FONT32X32
                    Charactors::font_type_32x32,
 #else // USE_FONT32X32
                    Charactors::font_type_32x16,
 #endif // USE_FONT32X32
                    0, 0, pixelData, backData, draw_mode_overwrite, 'A');
#else // USE_FONT
          if (_dev!= NUL) {
            _dev->setLed(pixelData);
          }
#endif // USE_FONT
            break;
        case motion_wonder:  /* ？ */
          _clearDisp();
          pixelData.rgb8.red =   0xFFu;
          pixelData.rgb8.green = 0x00u;
          pixelData.rgb8.blue =  0x00u;
#ifdef USE_FONT
          _drawChar(
 #ifdef USE_FONT32X32
                    Charactors::font_type_32x32,
 #else // USE_FONT32X32
                    Charactors::font_type_32x16,
 #endif // USE_FONT32X32
                    0, 0, pixelData, backData, draw_mode_overwrite, 'B');
#else // USE_FONT
          if (_dev!= NUL) {
            _dev->setLed(pixelData);
          }
#endif // USE_FONT
            break;
        default:
            break;
    }
    _startIllumination();
}

/* 周期実行処理 */
#define CYCLIC_INTERVAL 0
void Display::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
    if (cntdown == 0)
    {
        update();

        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}
