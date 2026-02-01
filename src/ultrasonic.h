#include <Arduino.h>
#include <NewPing.h>
#include <constants.hpp>

NewPing ultrasonic(sonar::TRIG, sonar::ECHO);

int checkDistance () {
    return ultrasonic.ping_cm();
}
