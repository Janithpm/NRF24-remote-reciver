
#include<SPI.h>
#include<RF24.h>

RF24 radio (9, 10);
byte address[][6] = {"J2496P"};
int msg[3];
boolean button_status;
int button_sending_val;
int val;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(120);
  radio.openWritingPipe(address[0]);
  radio.stopListening();

  pinMode(2,INPUT);


}

void loop() {

  msg[0] = analogRead(A0);
  msg[1] = analogRead(A1);
  radio.write(&msg, sizeof(msg));
  Serial.print(analogRead(A0));
  Serial.print("    ");
  Serial.println(analogRead(A1));
  delay(100);
}
