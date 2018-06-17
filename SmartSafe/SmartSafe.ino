/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 
 
 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Knob
 */

#include <Servo.h> 
#include "iodefine.h"
#include "PS_PAD.h"
#include "MFRC522.h"
Servo myservo;  // create servo object to control a servo 

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

#define PS2_SEL        9
PS_PAD PAD(PS2_SEL);

#define RC522_SDA        8
#define RC522_RESET      7
MFRC522 rfid(RC522_SDA, RC522_RESET);


void setup() 
{
  
  SPI.begin();
  rfid.PCD_Init();
  
  pinMode(5, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  PAD.init();
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);

  MTU2TCR_2 = (1<<5); //TGRAのコンペアマッチ/立ち上がりエッジでカウント/32MHz(分周なし)カウンタクロックの選択
  MTU2TIOR_2 = (1<<1)|(1<<0);  //初期出力は0出力//コンペアマッチでトグル出力
  MTU2TGRA_2=800;  //周期20kHz
  MTU2TGRB_2=400;  //Duty:50%
  MTU2TMDR_2 = (1<<1);//PWMモード1

    GPIOPIBC5 &= ~(1<<14);
  GPIOPBDC5 &= ~(1<<14);
  GPIOPM5 |= (1<<14);
  GPIOPMC5 &= ~(1<<14);
  GPIOPIPC5 &= ~(1<<14);

  GPIOPBDC5 &= ~(1<<14);
  GPIOPFC5 |= (1<<14);
  GPIOPFCE5 |= (1<<14);
  GPIOPFCAE5 &= ~(1<<14);
  GPIOPMC5 |= (1<<14);
  GPIOPM5   &= ~(1<<14);
} 

void loop() 
{ 
  val = digitalRead(A0);            // reads the value of the potentiometer (value between 0 and 1023) 
  PAD.poll();
//  Serial.print(PAD.read(PS_PAD::ANALOG_LY));
//  Serial.print(" : ");
//  Serial.println(val);
//  Serial.print(" : ");
//  Serial.println(MTU2TCNT_2);

  if(val==HIGH){
    myservo.write(30);
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    MTU2TSTR &= ~(1<<2);  //カウント動作停止
  }
  else{
    myservo.write(120);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    MTU2TSTR |= (1<<2);  //カウント動作開始
  }
  rfid_main();
  // sets the servo position according to the scaled value 
  delay(1000);                           // waits for the servo to get there 
} 


bool auth_state = false;
#define AHTH_TH 10
void rfid_main()
{
  const char expected_uid[] = {0x61, 0x20, 0xC4, 0x30};
  static int auth_cnt = AHTH_TH;

  if (!rfid.PICC_IsNewCardPresent()) {
    Serial.println(F("New card is not present"));
    auth_cnt = max(auth_cnt--, 0);
    goto END;
  }

  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println(F("Card cannot be read"));
    goto END;
  }

  {
    MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
    if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
        piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
        piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
      Serial.println(F("Your tag is not of type MIFARE Classic."));
      auth_cnt = max(auth_cnt--, 0);
      goto END;
    }
  }

  Serial.print("Tap card key: ");
  for (byte i = 0; i < 4; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    if (i < 3) {
      Serial.print(":");
    } else {
      Serial.println("");
    }
  }

  if (memcmp(expected_uid, rfid.uid.uidByte, sizeof(expected_uid)) == 0) {
    auth_cnt = AHTH_TH;
  } else {
    Serial.println("**Acces denied**");
    auth_cnt = max(auth_cnt--, 0);
  }

END:
  {

    static bool auth_state_old = false;
    auth_state = false;
    Serial.println(auth_cnt);

    if (auth_cnt > 0) {
      auth_state = true;
    } else {
      auth_state = false;
    }

    if (auth_state_old != auth_state) {
      if (auth_state == true) {
        Serial.println("false to true");
      } else {
        Serial.println("true to false");
      }
    }
    auth_state_old = auth_state;
  }
}






