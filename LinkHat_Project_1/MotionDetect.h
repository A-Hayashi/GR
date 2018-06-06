#ifndef MOTIONDETECT_H
#define MOTIONDETECT_H

#include "Common.h"

#include "AccelSensor3.h"

class MotionDetect
{
public:
    MotionDetect(void);
    void begin(AccelSensor3* accelSensor);
    motion_t get(void);
    void cyclicHandler(void);
private:
    const char* _motion_debug_str[8] = {"-", "Idle", "Yes", "Wonder", "Cool", "Boring", "Sleepy", "StopIt"};

    motion_t _motion;
    AccelSensor3* _accelSensor;
    void detectArgorism(void);
    
    // sampling data buffer
    int16_t  tmpx[8],tmpy[8];
};

#endif /* MOTIONDETECT_H */

