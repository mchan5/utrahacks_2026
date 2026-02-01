#ifndef MOVEMENTS_H
#define MOVEMENTS_H

#include <Arduino.h>
#include <Servo.h>
#include <L298NX2.h>
extern L298NX2 drivetrain;

void moveForward(int duration);
void turnLeft(int duration);
void turnRight(int duration);
void elevateBox(Servo &myServo);
void lowerBox(Servo &myServo);


#endif