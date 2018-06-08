#include "RedGreenMatrixLed32x16.h"

#ifdef USE_DISPLAY_RED_GREEN_MATRIX_32X16

/* コンストラクタ */
RedGreenMatrixLed32x16::RedGreenMatrixLed32x16(int pinDg, int pinAle, int pinDr, int pinWe, int pinClk, int pinA0, int pinA1, int pinA2, int pinA3, int pinAB, int pinSe)
{
  _pinDg = pinDg;
  _pinAle = pinAle;
  _pinDr = pinDr;
  _pinWe = pinWe;
  _pinClk = pinClk;
  _pinA0 = pinA0;
  _pinA1 = pinA1;
  _pinA2 = pinA2;
  _pinA3 = pinA3;
  _pinAB = pinAB;
  _pinSe = pinSe;
}

/* 初期化処理 */
void RedGreenMatrixLed32x16::begin(void)
{
  Serial.println("RedGreenMatrixLed32x16.begin()");

  pinMode(_pinAB, OUTPUT);
  if(_pinSe!=0xFF){
    pinMode(_pinSe, OUTPUT);
  }
  pinMode(_pinA3, OUTPUT);
  pinMode(_pinA2, OUTPUT);
  pinMode(_pinA1, OUTPUT);
  pinMode(_pinA0, OUTPUT);
  pinMode(_pinWe, OUTPUT);
  pinMode(_pinAle, OUTPUT);
  pinMode(_pinClk, OUTPUT);
  pinMode(_pinDr, OUTPUT);
  pinMode(_pinDg, OUTPUT);

  if(_pinSe!=0xFF){
    digitalWrite(_pinSe, LOW);
  }
}

void RedGreenMatrixLed32x16::_sendData(uint8_t addrY, uint32_t *dataR, uint32_t *dataG)
{
  volatile int j;
  unsigned long red;
  unsigned long green;

  red = *dataR;
  green = *dataG;

  for (j = 0; j < 32; j++) {
    digitalWrite(_pinClk, LOW);
    if ((red & 0x80000000UL) != 0) {    //MSBから送信していく
      digitalWrite(_pinDr, HIGH);
      } else {
      digitalWrite(_pinDr, LOW);
    }

    if ((green & 0x80000000UL) != 0) {  //MSBから送信していく
      digitalWrite(_pinDg, HIGH);
      } else {
      digitalWrite(_pinDg, LOW);
    }
    red = red << 1;       //次の列へ
    green = green << 1;   //次の列へ
    digitalWrite(_pinClk, HIGH);
  }
  //書き込むRAMのアドレスをセットする
  digitalWrite(_pinA0, (addrY >> 0) & 0x01);
  digitalWrite(_pinA1, (addrY >> 1) & 0x01);
  digitalWrite(_pinA2, (addrY >> 2) & 0x01);
  digitalWrite(_pinA3, (addrY >> 3) & 0x01);
  digitalWrite(_pinWe, HIGH);

  //内部バッファRAMへ書き込み
  digitalWrite(_pinAle, HIGH);

  //クリア
  digitalWrite(_pinWe, LOW);
  digitalWrite(_pinAle, LOW);
}

void RedGreenMatrixLed32x16::_disp(void)
{
  int i;
  unsigned long red;
  unsigned long green;

  for (i = 0; i < 16; i++) {
    red = _dispRam[0][i];
    green = _dispRam[1][i];
    _sendData(i, &red, &green);                //1行描画 
  }
}

void RedGreenMatrixLed32x16::_update(void)
{
  _disp();
}

void RedGreenMatrixLed32x16::setPixel(int x, int y, DisplayDevice::disp_pixel_data_t data)
{
  bool redOn = (data.rgb8.red>=0x80)? true: false;
  bool greenOn = (data.rgb8.green>=0x80 || data.rgb8.blue>=0x80)? true: false;

//  Serial.print("redOn: "); Serial.print(redOn);
//  Serial.print("\tgreenOn: "); Serial.print(greenOn);
//  Serial.print("\tx: "); Serial.print(x);
//  Serial.print("\ty: "); Serial.print(y);
//  Serial.println("");
  
  if (x < 0 || x > DISPLAY_WIDTH - 1 || y < 0 || y > DISPLAY_HEIGHT - 1) return;

  if (redOn) {
    _dispRam[0][y] |= (0x80000000u>>x);
  }
  else {
    _dispRam[0][y] &= ~(0x80000000u>>x);
  }

  if (greenOn) {
    _dispRam[1][y] |= (0x80000000u>>x);
  }
  else {
    _dispRam[1][y] &= ~(0x80000000u>>x);
  }
}

/* 周期実行処理 */
#define CYCLIC_INTERVAL 1
void RedGreenMatrixLed32x16::cyclicHandler(void)
{
  static uint16_t cntdown = CYCLIC_INTERVAL;
  if (cntdown == 0)
  {
    _update();
    cntdown = CYCLIC_INTERVAL;
  }
  else cntdown--;
}

#endif // USE_DISPLAY_RED_GREEN_MATRIX_32X16


