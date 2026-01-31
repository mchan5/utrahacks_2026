#include <Arduino.h>
#include <Servo.h>

Servo servo;

constexpr int SERVO_PIN = 6;

void setup() {
    servo.attach(SERVO_PIN);
    servo.write(90); 
}

void loop() {
    servo.write(0);
    delay(1000);

    servo.write(90);
    delay(1000);

    servo.write(180);
    delay(1000);
}
