#ifndef DISPLAY_H
#define DISPLAY_H

#include "Common.h"

#include "DisplayDevice.h"
#include "MotionDetect.h"
#include "Charactors.h"

class Display
{
public:
    Display(void);
    void begin(DisplayDevice* dev);
    void update(void);
    void showMotion(motion_t motion);
    void cyclicHandler(void);

private:
    Charactors* _charactors;
    DisplayDevice* _dev;

    void _drawChar(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, char num);
    void _drawString(Charactors::font_t font, int x, int y, DisplayDevice::disp_pixel_data_t pixel, DisplayDevice::disp_pixel_data_t back, char* str);

};

#endif /* DISPLAY_H */
