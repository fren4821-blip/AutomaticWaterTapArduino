#include <Servo.h>


int mesure_distance_cm(byte trig_pin,byte dist_pin)
{
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig_pin,LOW);
  int value = (pulseIn(dist_pin,HIGH)/2)/29.1+2;
  if (value>255) { value=255; }
  delay(20);
  return value;
}
Servo servo_4;


void setup() {
  pinMode(5,OUTPUT);//Sonar triger pin
  pinMode(2,INPUT);//Sonar distance pulse pin
  servo_4.attach(4);

}

void loop() {
  if (mesure_distance_cm(5,2) < 20) {
    servo_4.write(180);

  } else {
    servo_4.write(0);

  }

}