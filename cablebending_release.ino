#include <Servo.h>
#define servoPin 9

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
}

void loop() {
  uint32_t start = 0;
  uint16_t delT = 800;
  uint16_t trials = 2;

  myservo.write(0);

  while (!start) {
    if(Serial.available() > 0) break;
  }

  for (uint16_t i = 0; i < trials; i++) {
    myservo.write(130);
    delay(delT);
    myservo.write(0);
    delay(delT);
  }

  exit(0);
}
