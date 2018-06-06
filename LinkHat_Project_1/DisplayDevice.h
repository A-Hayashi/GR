#ifndef DISPLAYDEVICE_H_
#define DISPLAYDEVICE_H_

#include "Common.h"

class DisplayDevice
{
public:
    typedef union {
        bool on_off;
        enum {
             black,
             red,
             green,
             orange
        } rg;
        struct {
            bool red;
            bool green;
            bool blue;
        } rgb2;
        struct {
            uint8_t red;
            uint8_t green;
            uint8_t blue;
        } rgb8;
    } disp_pixel_data_t;

    DisplayDevice(void){}
    virtual void begin(void){Serial.println("DisplayDevice.begin()");}
//#ifdef USE_FONT
    virtual void setPixel(int x, int y, disp_pixel_data_t data){};
    virtual void drawChar(int x, int y, int width, int height, disp_pixel_data_t pixel, disp_pixel_data_t back, void* data){};
//#else
    virtual void setLed(disp_pixel_data_t data){};
//#endif
    virtual void cyclicHandler(void){Serial.print("v");}

private:
};
#endif /* DISPLAYDEVICE_H_ */
