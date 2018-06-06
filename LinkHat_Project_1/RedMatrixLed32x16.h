#ifndef _REDMATRIXLED32X16_H
#define _REDMATRIXLED32X16_H

#include "Common.h"
#include "DisplayDevice.h"

#ifdef USE_DISPLAY_RED_MATRIX_32X16

#define DISPLAY_WIDTH   (32)
#define DISPLAY_HEIGHT  (16)
#define DISPLAY_COLOR   (2)

class RedMatrixLed32x16 : public DisplayDevice
{
public:
    RedMatrixLed32x16(int ena, int lat, int clk, int sin1, int sin2, int sin3);
    void begin(void);
    void setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data);
    void cyclicHandler(void);
private:
    int _pinEna;
    int _pinLat;
    int _pinClk;
    int _pinSin1;
    int _pinSin2;
    int _pinSin3;
    uint16_t _dispRam[2][16];

    void _update(void);
    void _disp(void);
    void _setSeriParaData(uint16_t comData, uint16_t aData, uint16_t bData);

};

#endif // USE_DISPLAY_RED_MATRIX_32X16

#endif /* _REDMATRIXLED32X16_H */
