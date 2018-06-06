#ifndef ACCELADXL343_H
#define ACCELADXL343_H

#include "Common.h"
#include "AccelSensor3.h"
#include "Wire.h"

//#define _wire Wire4

class AccelAdxl343 : public AccelSensor3
{
public:
    AccelAdxl343(TwoWire* wire);

    void begin(void);
//    bool readRaw(float value[3]);
    bool sampling(void);
    //void cyclicHandler(void);

private:
    TwoWire* _wire;
    const static byte DEVICE_ADDRESS = 0x53;
    const static int _numOfChannels = 3;
};

#endif /* ACCELADXL343_H */
