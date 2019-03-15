#include <SoftwareSerial.h>

int rx = 10;
int tx = 11;

SoftwareSerial xbee_serial(rx,tx);

int baud_rate = 9600;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(baud_rate);
  xbee_serial.begin(baud_rate);
  while(!xbee_serial.available())
  {
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(xbee_serial.available())
    Serial.write(xbee_serial.read());
  if(Serial.available())
    xbee_serial.write(Serial.read());
}
