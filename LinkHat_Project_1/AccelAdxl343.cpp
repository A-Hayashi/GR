#include "AccelAdxl343.h"

/* コンストラクタ */
AccelAdxl343::AccelAdxl343(TwoWire* wire)
{
      _wire = wire;
}

/* 初期化処理 */
void AccelAdxl343::begin(void)
{
      Serial.println("AccelAdxl1343.begin()");
      _wire->begin();

      // check ADXL343
      // Read Device ID reg(0x00)
      _wire->beginTransmission(DEVICE_ADDRESS);
      _wire->write(0x00);
      _wire->endTransmission();
      _wire->beginTransmission(DEVICE_ADDRESS);
      _wire->requestFrom(DEVICE_ADDRESS,1); 
      byte val = _wire->read();
      if (val == 0xE5) {
        Serial.print("ADXL343 response OK\n");  // Device ID
      }else{
        Serial.print("ADXL343 response ERR\n");
      }
      _wire->endTransmission();
     
      _wire->beginTransmission(DEVICE_ADDRESS);
      _wire->write(0x2D);  // POWER_CTL register
      _wire->write(0x08);
      _wire->endTransmission();
      
      _wire->beginTransmission(DEVICE_ADDRESS);
      _wire->write(0x31);  // FORMAT reg
      _wire->write(0x00);
      _wire->endTransmission();

      Serial.println("setup Done!"); 
}
bool AccelAdxl343::sampling(void)
{
    byte val[6];

    //Serial.print(".");
    _wire->beginTransmission(DEVICE_ADDRESS);
    _wire->write(0x32);
    _wire->endTransmission();
        
    _wire->beginTransmission(DEVICE_ADDRESS);
    _wire->requestFrom(DEVICE_ADDRESS,6);
    for (int i=0; i< 6; i++){
        //while (_wire->available() == 0 ){}
        val[i] = _wire->read();
    }
    _sensorRawValue[0] = (float) ((short) ( ( (uint16_t) (val[1]) << 8) | val[0]) * 2) * GRAVITATIONAL_ACCELERATION / 1024.0f;
    _sensorRawValue[1] = (float) ((short) ( ( (uint16_t) (val[3]) << 8) | val[2]) * 2) * GRAVITATIONAL_ACCELERATION / 1024.0f;
    _sensorRawValue[2] = (float) ((short) ( ( (uint16_t) (val[5]) << 8) | val[4]) * 2) * GRAVITATIONAL_ACCELERATION / 1024.0f;  
    _wire->endTransmission();

    return (true);
}

