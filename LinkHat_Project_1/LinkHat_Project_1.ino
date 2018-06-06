
#include "Common.h"

#include <MsTimer2.h>
#include "MotionDetect.h"
#include "AccelAdxl343.h"
#include "Display.h"

#ifdef USE_DISPLAY_RED_MATRIX_32X16
  #include "RedMatrixLed32x16.h"
#endif // USE_DISPLAY_RED_MATRIX_32X16

#ifdef USE_DISPLAY_RED_GREEN_MATRIX_32X16
  #include "RedGreenMatrixLed32x16.h"
#endif // USE_DISPLAY_RED_GREEN_MATRIX_32X16

#ifdef USE_DISPLAY_COLOR_MATRIX_32X32
  #include "RGBMatrixLed32x32.h"
#endif // USE_DISPLAY_COLOR_MATRIX_32X32

#ifdef USE_DISPLAY_SINGLE_RGB_LED
  #include "SerialRgbLed.h"
#endif // USE_DISPLAY_SINGLE_RGB_LED

#include "Wire.h"
#include "AccelAdxl343.h"

#ifdef USE_ACCEL_SENSOR_ADXL343
#if defined(USE_BOARD_GR_CITRUS)
  AccelAdxl343 accelSensor(&Wire1);
#elif defined(USE_BOARD_ESP32)
  AccelAdxl343 accelSensor(&Wire);

#elif defined(USE_BOARD_ARDUINO)
  AccelAdxl343 accelSensor(&Wire);

#else  // defined(USE_BOARD_GR_CITRUS)
  #error "No Board Specified"

#endif  // defined(USE_BOARD_GR_CITRUS)

#endif // USE_ACCEL_SENSOR_ADXL343

#if defined(USE_DISPLAY_RED_MATRIX_32X16)
  RedMatrixLed32x16 dispDev(1,2,3,4,5,6);  //int ena, int lat, int clk, int sig1, int sig2, int sig3
#elif defined(USE_DISPLAY_RED_GREEN_MATRIX_32X16)
 RedGreenMatrixLed32x16 dispDev(10,17,16,15,14,6,9,4,3,18,SE_NOT_USED);  // int pinDg, int pinAle, int pinDr, int pinWe, int pinclk, int pinA0, int pinA1, int pinA2, int pinA3, int pinAB, int pinSe
  //林さんが Arduino でやっていたころのピン配なので、CITRUSのピンになっていない可能性あり。確認お願いします。
#elif defined(USE_DISPLAY_COLOR_MATRIX_32X32)
  RGBMatrixLed32x32 dispDev(14, 15, 16, 13, 10, 9, 6, 4, 3, 2, 19, 18, 1);  //int pinAle, int pinDr, int pinWe, int pinclk, int pinA0, int pinA1, int pinA2, int pinA3, int pinAB, int pinSe
#elif defined(USE_DISPLAY_SINGLE_RGB_LED)
  SerialRgbLed dispDev(16);
#elif defined(USE_NO_DISPLAY)

#else
  #error "No Display Specified"
#endif // USE_DISPLAY_RED_MATRIX_32X16

#define CYCLIC_INTERVAL 10  // 10msec

MotionDetect motionDetect;
Display disp;

void setup() {
  // put your setup code here, to run once:
#ifdef USE_SERIAL_FAST_BAUDRATE
    Serial.begin(115200); 
#else // USE_SERIAL_BAUDRATE_115200
    Serial.begin(9600);
#endif // USE_SERIAL_BAUDRATE_115200
    
    delay(1000);    // GR-CITRUS は起動後にシリアル認識するのに時間かかるので１秒ほど待たせました。

    Serial.println("setup()");
    accelSensor.begin();
    motionDetect.begin(&accelSensor);
#ifndef USE_NO_DISPLAY
    disp.begin(&dispDev);  //  
#else // USE_NO_DISPLAY
    disp.begin(NULL);  //  
#endif // USE_NO_DISPLAY
}

// デバッグ時はいずれかを有効に
//#define DEBUG_ANG_VEL  // 各速度
//#define DEBUG_AVARAGE  // 平均値
//#define DEBUG_RAW      // 生値
void loop() {
    motion_t motion;
    float sensor_data[3];

    // put your main code here, to run repeatedly: 
    accelSensor.cyclicHandler();
    motionDetect.cyclicHandler();
    disp.cyclicHandler();
    
    motion = motionDetect.get();
    if (motion_none != motion)
    {
        disp.showMotion(motion);
    }
  /*
    if (motion == motion_yes) {
        Serial.print("YES");
    }else if (motion == motion_wonder) {
        Serial.print("? ");
    }
*/
  
    
#if defined(DEBUG_ANG_VEL) || defined(DEBUG_AVARAGE) ||  defined(DEBUG_RAW) // for Test!

  #if defined(DEBUG_RAW)
    accelSensor.readRaw(&sensor_data[0]);
  #elif defined(DEBUG_AVARAGE)
    accelSensor.readAverage(&sensor_data[0]);
  #elif defined(DEBUG_ANG_VEL)
    accelSensor.readAngularVelocity(&sensor_data[0]);
  #endif
    // Serial.print("Acc(x,y,z)=");
    Serial.print(sensor_data[0]);
    Serial.print(",");
    Serial.print(sensor_data[1]);
#ifndef DEBUG_ANG_VEL
    Serial.print(",");
    Serial.print(sensor_data[2]);
#endif
    Serial.println("");
#endif // defined(DEBUG_ANG_VEL) || defined(DEBUG_AVARAGE) ||  defined(DEBUG_RAW) // for Test!

    delay(CYCLIC_INTERVAL);  
}


