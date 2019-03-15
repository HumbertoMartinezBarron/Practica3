#include <SoftwareSerial.h>

int rx = 10;
int tx = 11;

SoftwareSerial xbee_serial(rx,tx);

int baud_rate = 9600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud_rate);
  xbee_serial.begin(baud_rate);
  while(xbee_serial.available()<=0)
  {
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  while(xbee_serial.available()>0)
    Serial.write(xbee_serial.read());
  while(Serial.available()>0)
    xbee_serial.write(Serial.read());
}
