// 3軸加速度センサ基底クラス
#ifndef ACCELSENSOR3_H
#define ACCELSENSOR3_H

#include "Common.h"

#include <Arduino.h>
#include <Wire.h>

#define NUM_OF_AXIS (3)                          // 加速度センサーの軸数
#define NUM_OF_ANG_VEL (2)                       // 
#define AVERAGE_COUNT (5)                        // 平均化回数
#define GRAVITATIONAL_ACCELERATION  (9.8065f)    // 重力加速度

class AccelSensor3
{
public:
    AccelSensor3(void);
    void begin(void);

    bool readRaw(float value[NUM_OF_AXIS]);
    bool readAngularVelocity(float value[NUM_OF_ANG_VEL]);
    bool readAverage(float value[NUM_OF_AXIS]);

    void cyclicHandler(void);
    virtual bool sampling(void){}

protected:
    float _sensorRawValue[NUM_OF_AXIS];
    float _angularVelocity[NUM_OF_ANG_VEL];
    float _sensorAverage[NUM_OF_AXIS];

private:
    void _calcAngularVelocity(void);
    void _calcAverage(void);
};

#endif /* ACCELSENSOR3_H */
