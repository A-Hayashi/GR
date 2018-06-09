#ifndef DISPLAY_H
#define DISPLAY_H

#include "Common.h"

#include "DisplayDevice.h"
#include "MotionDetect.h"
#include "Charactors.h"

#define ILLUMINATION_STEP_COUNT 3

class Display
{
public:
    typedef enum
    {
        draw_mode_overwrite = 0,  // 常に上書き
        draw_mode_layers          // ＲＧＢ特定のレイヤだけ描画
    } draw_mode_t;

    Display(void);
    void begin(DisplayDevice* dev);
    void update(void);
    void updateIillumination(void);
    void showMotion(motion_t motion);
    void cyclicHandler(void);

private:
    Charactors* _charactors;
    DisplayDevice* _dev;
    DisplayDevice::disp_pixel_data_t _localBuf[32][32];
    motion_t _motion;
    int _illuminationStep;
    int _illuminationWait;
    int _illuminationStepMax;
    int _illuminationChrCode;

    void _clearDisp(void);
    void _writeDisplay(int x, int y, int width, int height);
    void _startIllumination(void);
    void _drawChar(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, draw_mode_t mode, char num);
    void _drawString(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, draw_mode_t mode, char* str);

};

#endif /* DISPLAY_H */
