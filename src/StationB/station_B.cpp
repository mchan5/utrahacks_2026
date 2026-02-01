/**
 * @file station_B.cpp
 * @brief Implementation of Station B task sequence
 */

#include "Station_B.h"
#include "movements.h"

void runStationB() {
  moveForward(1000);
  turnLeft(500);
}
