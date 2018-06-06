#ifndef COMMON_H
#define COMMON_H
#include <Arduino.h>

/*==================================*/
/*  ハードウェアコンパイルスイッチ  */
/*==================================*/

/*----------------------------------------*/
/* [[[ Board ]]] いずれか１つ選択 */
//#define USE_BOARD_GR_CITRUS
//#define USE_BOARD_ESP32
//#define USE_BOARD_ARDUINO
//#define USE_DISPLAY_XXXXX // <=

/* [[[ Display ]]] いずれか１つ選択 */
//#define USE_DISPLAY_RED_MATRIX_32X16
//#define USE_DISPLAY_RED_GREEN_MATRIX_32X16
//#define USE_DISPLAY_COLOR_MATRIX_32X32
//#define USE_DISPLAY_SINGLE_RGB_LED

/* [[[ Accel. Sensor ]]]いずれか１つ選択 */
//#define USE_ACCEL_SENSOR_ADXL343
//#define USE_ACCEL_SENSOR_XXXXX // <=
/*----------------------------------------*/

/////////////////////////////////////////////////
#define USE_HW_NO_1  // 32x16 のカラーマトリックス LED + GR-CITRUS のやつ(林さん制作中？)
//#define USE_HW_NO_2  // 32x16 の300円赤色マトリックス LED + GR-CITRUS のやつ(佐野断念！！）
//#define USE_HW_NO_3  // 32x16 の300円赤色マトリックス LED + ARDUINO-NANO? (酒匂君制作中)
//#define USE_HW_NO_4  // シリアル LED + ESP32 のやつ (臼井君制作中？)
//#define USE_HW_NO_5  // 32x32 の巨大カラーマトリックス LED + GR-CITRUS のやつ（佐野制作中） 
//#define USE_HW_NO_6  // 追加はここに
/////////////////////////////////////////////////

#if    defined(USE_HW_NO_1)  // 32x16 のカラーマトリックス LED + GR-CITRUS のやつ(林さん制作中？)
    #define USE_BOARD_GR_CITRUS
    #define USE_DISPLAY_RED_GREEN_MATRIX_32X16
    #define USE_ACCEL_SENSOR_ADXL343
#elif  defined(USE_HW_NO_2)  // 32x16 の300円赤色マトリックス LED + GR-CITRUS のやつ(佐野断念！！）
    #define USE_BOARD_GR_CITRUS
    #define USE_DISPLAY_RED_MATRIX_32X16
    #define USE_ACCEL_SENSOR_ADXL343
#elif  defined(USE_HW_NO_3)  // 32x16 の300円赤色マトリックス LED + ARDUINO-NANO? (さごう君制作中)
    #define USE_BOARD_ARDUINO
    #define USE_DISPLAY_RED_MATRIX_32X16
    #define USE_ACCEL_SENSOR_ADXL343
#elif  defined(USE_HW_NO_4)  // シリアル LED + ESP32 のやつ (臼井君制作中？)
    #define USE_BOARD_ESP32
    //@#define USE_DISPLAY_SINGLE_RGB_LED
    #define USE_NO_DISPLAY
    #define USE_ACCEL_SENSOR_ADXL343
    #define USE_SERIAL_FAST_BAUDRATE
#elif  defined(USE_HW_NO_5)  // 32x32 の巨大カラーマトリックス LED + GR-CITRUS のやつ（佐野制作中）
    #define USE_BOARD_GR_CITRUS
    #define USE_DISPLAY_COLOR_MATRIX_32X32
    #define USE_ACCEL_SENSOR_ADXL343
//@#else
//@    #error "No Target Hardware Defined!!!"
#endif

/* 単一RGB LED を使う場合はキャラクターも使わない */
#ifdef USE_DISPLAY_SINGLE_RGB_LED
  #undef USE_FONT
#else
  #define USE_FONT
#endif

typedef enum 
{
    motion_none = 0,
    motion_idle,    /* 待ち受け */
    motion_yes,     /* いいね */
    motion_wonder,  /* ？ */
    motion_cool,    /* 超いいね */
    motion_borling, /* つまらん */
    motion_sleepy,  /* ねむい */
    motion_stop_it, /* 話長いねん */
} motion_t;

#endif /* COMMON_H */

