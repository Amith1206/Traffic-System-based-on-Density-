#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9          // Configurable, see typical pin layout above
#define SS_1_PIN        10         // Configurable, take a unused pin, only HIGH/LOW required, must be diffrent to SS 2
#define SS_2_PIN        8 // Configurable, take a unused pin, only HIGH/LOW required, must be diffrent to SS 1
#define SS_3_PIN
#define SS_4_PIN



#define NR_OF_READERS   2

byte ssPins[] = {SS_1_PIN, SS_2_PIN};

MFRC522 mfrc522[NR_OF_READERS];   // Create MFRC522 instance.
#define ledA1 2
#define ledA2 3
#define ledA3 4

#define ledB1 5
#define ledB2 6
#define ledB3 7

#define ledC1 8
#define ledC2 9
#define ledC3 10

#define ledD1 12
#define ledD2 11
#define ledD3 13

int count1=0;
int count2=0;
int count3=0;
int count4=0;
void setup() {

  Serial.begin(9600);

  pinMode(ledA1, OUTPUT);
  pinMode(ledA2, OUTPUT);
  pinMode(ledA3, OUTPUT);

  pinMode(ledB1, OUTPUT);
  pinMode(ledB2, OUTPUT);
  pinMode(ledB3, OUTPUT);

  pinMode(ledC1, OUTPUT);
  pinMode(ledC2, OUTPUT);
  pinMode(ledC3, OUTPUT);

  pinMode(ledD1, OUTPUT);
  pinMode(ledD2, OUTPUT);
  pinMode(ledD3, OUTPUT);


 Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)

  SPI.begin();        // Init SPI bus

  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    mfrc522[reader].PCD_Init(ssPins[reader], RST_PIN); // Init each MFRC522 card
    Serial.print(F("Reader "));
    Serial.print(reader);
    Serial.print(F(": "));
    mfrc522[reader].PCD_DumpVersionToSerial();
    count1=0;
    count2=0;
    count3=0;
    count4=0;
 
  }
}
void start()
{
 digitalWrite(ledA1,LOW);
 digitalWrite(ledA2,LOW);
 digitalWrite(ledA3,LOW);
 digitalWrite(ledB1,LOW);
 digitalWrite(ledB2,LOW);
 digitalWrite(ledB3,LOW);
 digitalWrite(ledC1,LOW);
 digitalWrite(ledC2,LOW);
 digitalWrite(ledC3,LOW);
 digitalWrite(ledD1,LOW);
 digitalWrite(ledD2,LOW);
 digitalWrite(ledD3,LOW);
}
 
 

void loop() {

  if (count1==count2==count3==count4)
  {
    priopen();
    readcount();
    /*rBopen();
    rCopen();
    rDopen();*/
  }
  else if ((count1>=count2)&& (count1>=count3)&&(count1>=count4))
  {
    rAopen();
  else if ((count2>=count1)&& (count2>=count3)&&(count2>=count4))
    {
     rBopen();
    }
  }
  else if ((count3>=count1)&& (count3>=count1)&&(count3>=count4))
  {
    rCopen();
  else if ((count4>=count1)&& (count4>=count2)&&(count4>=count3)
    {
      rDopen();
    }
  
 

void priopen()
{
  //first post prio
  digitalWrite(ledA3, LOW);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledA1,LOW);
  digitalWrite(ledA2,HIGH);
  delay(1000);
  digitalWrite(ledA2, LOW);
  digitalWrite(ledA3,HIGH);
  //readcount();

  //second post prio
  digitalWrite(ledB3, LOW);
  digitalWrite(ledB2, LOW);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  digitalWrite(ledA3, HIGH);
  delay(10000);
  digitalWrite(ledB1,LOW);
  digitalWrite(ledB2,HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  digitalWrite(ledB3,HIGH);

  //third post prio
  digitalWrite(ledC3, LOW);
  digitalWrite(ledC2, LOW);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  delay(10000);
  digitalWrite(ledC1,LOW);
  digitalWrite(ledC2,HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  digitalWrite(ledC3,HIGH);

  //fourth post prio
  digitalWrite(ledD3, LOW);
  digitalWrite(ledD2, LOW);
  digitalWrite(ledD1, HIGH);
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  delay(10000);
  digitalWrite(ledD1,LOW);
  digitalWrite(ledD2,HIGH);
  delay(1000);
  digitalWrite(ledD2, LOW);
  digitalWrite(ledD3,HIGH); 
}
void rAopen()
{
 
  void start();
  digitalWrite(ledA1, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledA1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  digitalWrite(ledA3,HIGH);
  readSensor();
  
}

void rBopen()
{
  void start();
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB1, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledB1, LOW);
  digitalWrite(ledB2, HIGH);
  delay(1000);
  digitalWrite(ledB2, LOW);
  digitalWrite(ledB3,HIGH);
  readSensor();
}

void rCopen()
{
  void start();
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC1, HIGH);
  digitalWrite(ledD3, HIGH);
  delay(10000);
  digitalWrite(ledC1, LOW);
  digitalWrite(ledC2, HIGH);
  delay(1000);
  digitalWrite(ledC2, LOW);
  digitalWrite(ledC3,HIGH);
  readSensor();
}

void rDopen()
{
  void start();
  digitalWrite(ledA3, HIGH);
  digitalWrite(ledB3, HIGH);
  digitalWrite(ledC3, HIGH);
  digitalWrite(ledD1, HIGH);
  delay(10000);
  digitalWrite(ledD1, LOW);
  digitalWrite(ledD2, HIGH);
  delay(1000);
  digitalWrite(ledD2, LOW);
  digitalWrite(ledD3,HIGH);
  readSensor();
}







void loop() {

  for (uint8_t reader = 0; reader < NR_OF_READERS; reader++) {
    // Look for new cards

    if (mfrc522[reader].PICC_IsNewCardPresent() && mfrc522[reader].PICC_ReadCardSerial()) {
    
      if(reader==0){
count1++;
 Serial.print(count1);
 }
      else
      if(reader==1){
      count1--;
Serial.print(count1);
}

      if(reader==2){
count2++;
 Serial.print(count2);
 }
      else
      if(reader==3){
      count2--;
Serial.print(count2);
}
      if(reader==4){
count3++;
 Serial.print(count3);
 }
      else
      if(reader==5){
      count3--;
Serial.print(count3);
}
      if(reader==6){
count4++;
 Serial.print(count4);
 }
      else
      if(reader==7){
      count4--;
Serial.print(count4);
}

      Serial.print(F("Reader "));
      Serial.print(reader);
      // Show some details of the PICC (that is: the tag/card)
      Serial.print(F(": Card UID:"));
      dump_byte_array(mfrc522[reader].uid.uidByte, mfrc522[reader].uid.size);
      Serial.println();
      Serial.print(F("PICC type: "));
      MFRC522::PICC_Type piccType = mfrc522[reader].PICC_GetType(mfrc522[reader].uid.sak);
      Serial.println(mfrc522[reader].PICC_GetTypeName(piccType));
      Serial.println("count is : ");
      Serial.print(count1);
      // Halt PICC
      mfrc522[reader].PICC_HaltA();
      // Stop encryption on PCD
      mfrc522[reader].PCD_StopCrypto1();
    } //if (mfrc522[reader].PICC_IsNewC
  } //for(uint8_t reader
}

/**
 * Helper routine to dump a byte array as hex values to Serial.
 */
void dump_byte_array(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
