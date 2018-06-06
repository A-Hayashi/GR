#include "MotionDetect.h"

/* コンストラクタ */
MotionDetect::MotionDetect(void)
{
    _motion = motion_none;
}

/* 初期化処理 */
void MotionDetect::begin(AccelSensor3* accelSensor)
{
    Serial.println("MotionDetect.begin()");
    _accelSensor = accelSensor;
}

motion_t MotionDetect::get(void)
{
    motion_t ret = _motion;  // 現在値を取得して
    _motion = motion_none;   // 取得後は NONE にして次の動作が確定するのを待つ

    return(ret);
}


// ジェスチャー判定基準
#define THRES_YES_Y_MIN 20
#define THRES_YES_Y_MAX 35
#define THRES_YES_X_MIN -10
#define THRES_YES_X_MAX 10

#define THRES_WONDER_X_MIN 20
#define THRES_WONDER_X_MAX 50


//#define deltax ang_vel[0]
//#define deltay ang_vel[1]
void MotionDetect::detectArgorism(void)
{
    static motion_t last_motion = motion_none;
    static motion_t cur_motion;
    float ang_vel[NUM_OF_ANG_VEL];
//Serial.print("@");
    _accelSensor->readAngularVelocity(ang_vel);
    static uint16_t elapsed_time;
    int16_t  deltax, deltay;
 
    for(int i=7; i>0; i--){
      tmpx[i] = tmpx[i-1];
      tmpy[i] = tmpy[i-1];
    }
    tmpx[0] = ang_vel[0];
    tmpy[0] = ang_vel[1];
    deltax = ang_vel[0] - tmpx[7];   //X方向の角度変化
    deltay = ang_vel[1] - tmpy[7];   //Y方向の角度変化

    // YES(首を縦にふる) 検出  
    if (((deltax < THRES_YES_X_MAX) && (deltax > THRES_YES_X_MIN )) &&
        ((deltay < THRES_YES_Y_MAX) && (deltay > THRES_YES_Y_MIN )))  
    {
          cur_motion = motion_yes;
          elapsed_time = millis();
    }
  
    // WONDER(首をかしげる）検出
    else if ((deltax < THRES_WONDER_X_MAX) && (deltax > THRES_WONDER_X_MIN ))   
    {
          cur_motion = motion_wonder;
          elapsed_time = millis();
    } 
    else {
        if(millis() - elapsed_time > 3000){
          cur_motion = motion_idle;
        }
    }

    // 前回値と違う場合だけ設定
    if (cur_motion != last_motion) {
        _motion = cur_motion;  // 未取得時上書き前提
        Serial.println(_motion_debug_str[_motion]); // デバッグ用
    }
    last_motion = cur_motion;
}

/* 定期実行処理 */
#define CYCLIC_INTERVAL 10;
void MotionDetect::cyclicHandler(void)
{
    static uint16_t cntdown = CYCLIC_INTERVAL;
    if (cntdown == 0)
    {
        detectArgorism();

        cntdown = CYCLIC_INTERVAL;
    }
    else cntdown--;
}


