#ifndef RGBMATRIXLED32x32_H
#define RGBMATRIXLED32x32_H

#include "Common.h"
#include "DisplayDevice.h"

#ifdef USE_DISPLAY_COLOR_MATRIX_32X32

#define DISPLAY_WIDTH   (32)
#define DISPLAY_HEIGHT  (32)
#define DISPLAY_COLOR   (16)

class RGBMatrixLed32x32 : public DisplayDevice
{
public:
    RGBMatrixLed32x32(int pinClk,  int pinLat,  int pinOe, int pinR0,  int pinG0,  int pinB0, 
               int pinR1,  int pinG1,  int pinB1, int pinA0,  int pinA1,  int pinA2,  int pinA3);

    void begin(void);
    void setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data);
    void cyclicHandler(void);

private:
  int _pinClk;
  int _pinLat;
  int _pinOe;

  int _pinA0;
  int _pinA1;
  int _pinA2;
  int _pinA3;

  int _pinR0;
  int _pinG0;
  int _pinB0;

  int _pinR1;
  int _pinG1;
  int _pinB1;
  struct 
  {
    uint8_t R;
    uint8_t G;
    uint8_t B;
  } _dispRam[DISPLAY_HEIGHT][DISPLAY_WIDTH];

    void _update(void);
};

#endif // USE_DISPLAY_COLOR_MATRIX_32X32
#endif /* RGBMATRIXLED32x32_H */
