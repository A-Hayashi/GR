
#include <avr/pgmspace.h> 

#include <EEPROM.h>


//PC5 A/BB  H:RAM-A選択 L:RAM-B選択
//PC4 SE    H:内部バッファRAM手動切り替え L:内部バッファRAM自動切り替え
//PC3 A3    内部バッファRAMアドレス(MSB)
//PC2 A2    内部バッファRAMアドレス
//PC1 A1    内部バッファRAMアドレス
//PC0 A0    内部バッファRAMアドレス(LSB)
//
//PB4 ALE   H:アドレスラッチ有効 L:アドレスラッチ無効
//PB3 WE    H:内部バッファRAMへ書き込み L:内部バッファRAMへ書き込まない
//PB2 CLK   立ち上がりエッジでデータ取り込み
//PB1 DR    H:green L:消灯nnnnn
//PB0 DG    H:red L:消灯

#define SE  3
#define AB  2
#define ADDRESS3  19
#define ADDRESS2  18
#define ADDRESS1  1
#define ADDRESS0  0
#define DG  9
#define CLK  8
#define WE  7
#define DR  6
#define ALE 5


const PROGMEM unsigned int font_tbl_r[2][16] =
{
  {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,    //快
  }
  ,
  {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,    //快
  }
  ,
};

const PROGMEM unsigned int font_tbl_g[2][16] =
{
  {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,    //快
  }
  ,
  {
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,    //快
  }
  ,
};

void send_data(unsigned char iADDRESS_y, unsigned long *idata_r, unsigned long *idata_g);

void send_data(unsigned char iADDRESS_y, unsigned long *idata_r, unsigned long *idata_g)
{
  volatile int j;
  unsigned long red;
  unsigned long green;

  red = *idata_r;
  green = *idata_g;

  for (j = 0; j < 32; j++) {
    digitalWrite(CLK, LOW);
    if ((red & 0x80000000UL) != 0) {    //MSBから送信していく
      digitalWrite(DR, HIGH);
    } 
    else {
      digitalWrite(DR, LOW);
    }

    if ((green & 0x80000000UL) != 0) {  //MSBから送信していく
      digitalWrite(DG, HIGH);
    } 
    else {
      digitalWrite(DG, LOW);
    }
    red = red << 1;       //次の列へ
    green = green << 1;   //次の列へ
    digitalWrite(CLK, HIGH);
  }
  //書き込むRAMのアドレスをセットする
  digitalWrite(ADDRESS0, (iADDRESS_y >> 0) & 0x01);
  digitalWrite(ADDRESS1, (iADDRESS_y >> 1) & 0x01);
  digitalWrite(ADDRESS2, (iADDRESS_y >> 2) & 0x01);
  digitalWrite(ADDRESS3, (iADDRESS_y >> 3) & 0x01);
  digitalWrite(WE, HIGH);

  //内部バッファRAMへ書き込み
  digitalWrite(ALE, HIGH);

  //クリア
  digitalWrite(WE, LOW);
  digitalWrite(ALE, LOW);
}

static unsigned long time;
void setup() {
  Serial4.begin(9600);
  pinMode(AB, OUTPUT);
  pinMode(SE, OUTPUT);
  pinMode(ADDRESS3, OUTPUT);
  pinMode(ADDRESS2, OUTPUT);
  pinMode(ADDRESS1, OUTPUT);
  pinMode(ADDRESS0, OUTPUT);
  pinMode(WE, OUTPUT);
  pinMode(ALE, OUTPUT);
  pinMode(CLK, OUTPUT);
  pinMode(DR, OUTPUT);
  pinMode(DG, OUTPUT);

  digitalWrite(SE, LOW);

  Serial.begin(9600);
  delay(100);

  byte* rdata = (byte*)&time;
  for(int i=0;i<sizeof(time);i++){
    rdata[i] = EEPROM.read(i);
  }
  Serial.println(time);
}

unsigned int disp_buf_r[2][16];
unsigned int disp_buf_g[2][16];

void loop() {
  int i;
  unsigned long red;
  unsigned long green;
  delay(1000);

  time++;

  for (i = 0; i < 16; i++) {
    disp_buf_r[1][i] = pgm_read_word(&font_tbl_r[0][i]);
    disp_buf_r[0][i] = pgm_read_word(&font_tbl_r[1][i]);
    disp_buf_g[1][i] = pgm_read_word(&font_tbl_g[0][i]);
    disp_buf_g[0][i] = pgm_read_word(&font_tbl_g[1][i]);
  }
  for (i = 0; i < 16; i++) {
    red = disp_buf_r[1][i];
    red = (red << 16) | disp_buf_r[0][i];      //16bit+16bit=32bit(1行)
    green = disp_buf_g[1][i];
    green = (green << 16) | disp_buf_g[0][i];  //16bit+16bit=32bit(1行)
    send_data(i, &red, &green);                //1行描画
  }


  if(time%601==0){
    byte* wdata = (byte*)&time;
    for(i=0;i<sizeof(time);i++){
      EEPROM.write(i, wdata[i]);
    }
    Serial.println(time);
  }
}



