#ifndef _SerialRgbLed_H
#define _SerialRgbLed_H

#include <Arduino.h>
#if defined(USE_DISPLAY_SINGLE_RGB_LED)
#include <Adafruit_NeoPixel.h>
#endif // defined(USE_DISPLAY_SINGLE_RGB_LED)
#include "Common.h"
#include "DisplayDevice.h"

#ifdef USE_DISPLAY_SINGLE_RGB_LED

class SerialRgbLed : public DisplayDevice
{
public:
    SerialRgbLed(int sigPin);
    void begin(void);
    void setLed(disp_pixel_data_t data); 
    void cyclicHandler(void);
private:

#if defined(USE_DISPLAY_SINGLE_RGB_LED)
    Adafruit_NeoPixel *_strip;
#endif // defined(USE_DISPLAY_SINGLE_RGB_LED)
    int _sigPin;
    disp_pixel_data_t _data;

    void _update(void);

};
#endif // USE_DISPLAY_SINGLE_RGB_LED

#endif /* _SerialRgbLed_H */
