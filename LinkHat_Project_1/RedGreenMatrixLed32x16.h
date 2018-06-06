#ifndef REDGREENMATRIXLED32x16_H
#define REDGREENMATRIXLED32x16_H

#include "Common.h"
#include "DisplayDevice.h"

#ifdef USE_DISPLAY_RED_GREEN_MATRIX_32X16

#define DISPLAY_WIDTH   (32)
#define DISPLAY_HEIGHT  (16)
#define DISPLAY_COLOR   (4)

#define SE_NOT_USED   (0xFF)

class RedGreenMatrixLed32x16 : public DisplayDevice
{
public:
    RedGreenMatrixLed32x16(int pinDg, int pinAle, int pinDr, int pinWe, int pinClk, int pinA0, int pinA1, int pinA2, int pinA3, int pinAB, int pinSe);
    void begin(void);
    void setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data);
    void _sendData(uint8_t iaddr_y, uint32_t *idata_r, uint32_t *idata_g);
    void cyclicHandler(void);

private:
    int _pinDg;
    int _pinAle;
    int _pinDr;
    int _pinWe;
    int _pinClk;
    int _pinA0;
    int _pinA1;
    int _pinA2;
    int _pinA3;
    int _pinAB;
    int _pinSe;
    void _disp(void);
    void _update(void);
    uint32_t _dispRam[2][16];
};
#endif // USE_DISPLAY_RED_GREEN_MATRIX_32X16

#endif /* REDGREENMATRIXLED32x16_H */
