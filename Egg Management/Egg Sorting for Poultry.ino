// C++ code
//
#include <Servo.h>

int Weight = 0;

Servo servo_9;

void setup()
{
  pinMode(A1, INPUT);
  servo_9.attach(9, 500, 2500);

  pinMode(3, OUTPUT);
}

void loop()
{
  Weight = analogRead(A1);
  if (Weight < 50) {
    servo_9.write(60);
    analogWrite(3, 0);
    analogWrite(5, 0);
    analogWrite(6, 255);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    servo_9.write(120);
    analogWrite(3, 255);
    analogWrite(5, 0);
    analogWrite(6, 0);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}