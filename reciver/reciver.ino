#include <SPI.h>
#include<RF24.h>
#include <Servo.h>
int VR;
int JL_x;
int JL_y;
int JR_x;
int JR_y;
int tSwitch[] = {0, 0, 0};

RF24 radio (9, 10);
byte address[][6] = {"ADR00001"};
int data[8];
void setup() {
  Serial.begin(9600);

  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  radio.setChannel(124);
  radio.openReadingPipe(1, address[0]);
  radio.startListening();


}

void loop() {
  if (radio.available()) {

    radio.read(&data, sizeof(data));

    for (int i = 0; i < 3; i++) {
      tSwitch[i] =  data[i];
    }
    VR = data[3];
    JL_x = data[4];
    JL_y = data[5];
    JR_x = data[6];
    JR_y = data[7];

    Serial.print("tSwitch 1 : "); Serial.print(tSwitch[1]); Serial.print("   ");
    Serial.print("tSwitch 2  : "); Serial.print(tSwitch[2]); Serial.print("   ");
    Serial.print("tSwitch 3  : "); Serial.print(tSwitch[3]); Serial.print("   ");
    Serial.print("VR : "); Serial.print(VR); Serial.print("   ");
    Serial.print("JL_x : "); Serial.print(JL_x); Serial.print("   ");
    Serial.print("JL_y : "); Serial.print(JL_y); Serial.print("   ");
    Serial.print("JR_x : "); Serial.print(JR_x); Serial.print("   ");
    Serial.print("JR_y : "); Serial.print(JR_y); Serial.print("   ");

    Serial.println();

  }
  delay(5);
}
