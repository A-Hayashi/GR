#include "AccelSensor3.h"

AccelSensor3::AccelSensor3(void)
{
}

void AccelSensor3::begin(void){
    Serial.println("AccelSensor3.begin()");
}

// 生値読み出し
bool AccelSensor3::readRaw(float value[NUM_OF_AXIS])
{
    for (int i = 0; i < NUM_OF_AXIS; i++)
    {
        value[i] = _sensorRawValue[i];
    }
    return (true);
}

// 各速度読み出し
bool AccelSensor3::readAngularVelocity(float value[NUM_OF_ANG_VEL])
{
    for (int i = 0; i < NUM_OF_ANG_VEL; i++)
    {
        value[i] = _angularVelocity[i];
    }
    return (true);
}

// 平均値読み出し
bool AccelSensor3::readAverage(float value[NUM_OF_AXIS])
{
    for (int i = 0; i < NUM_OF_AXIS; i++)
    {
        value[i] = _sensorAverage[i];
    }
    return (true);
}

void AccelSensor3::_calcAngularVelocity(void)
{
    _angularVelocity[0] = (float) (atan2( _sensorAverage[0] / (2*GRAVITATIONAL_ACCELERATION),
                                          _sensorAverage[2] / (2*GRAVITATIONAL_ACCELERATION)) / 3.14159f * 180.0);

    _angularVelocity[1] = (float) (atan2( _sensorAverage[1] / (2*GRAVITATIONAL_ACCELERATION),
                                          _sensorAverage[2] / (2*GRAVITATIONAL_ACCELERATION)) / 3.14159f * 180.0);
    //Serial.print("v");
}

void AccelSensor3::_calcAverage(void)
{
    static float averageBuffer[NUM_OF_AXIS][AVERAGE_COUNT];
    static int averagePos = 0;
    static int averageCnt = 0;
    int i, j;

    if (averageCnt < AVERAGE_COUNT) averageCnt++;  // これ忘れると一発目ゼロ除算しちゃうよね

    for (i = 0; i<NUM_OF_AXIS; i++)
    {
        float sum = 0;

        averageBuffer[i][averagePos] = _sensorRawValue[i];

        for (j = 0; j<averageCnt; j++)
        {
            sum += averageBuffer[i][j];
        }
        _sensorAverage[i] = sum / (float)averageCnt;
    }
    averagePos++;
    if (averagePos>=AVERAGE_COUNT) averagePos = 0;
    //Serial.print("a");
}

/* 周期処理 */
#define CYCLIC_INTERVAL 8  // 80ms サイクル = サンプリング周期　12.5Hzに合わせてある
void AccelSensor3::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
    if (cntdown == 0)
    {
        sampling();
        _calcAverage();
        _calcAngularVelocity();
        //Serial.print("-");
        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}

