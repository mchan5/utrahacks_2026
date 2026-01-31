#include <Arduino.h>
#include <TCS3200.h>
#include "constants.hpp"

TCS3200 tcs3200(clr::S0, clr::S1, clr::S2, clr::S3, clr::S_Out);
// Create instance of TCS3200 (Colour Sensor) class

String color_indices[] = {"Red", "Green", "Blue"};
RGBColor color_values[] = {
  {255, 0, 0},  // Red
  {0, 255, 0},  // Green
  {0, 0, 255},  // Blue
};

void setup(){

    tcs3200.begin();
    tcs3200.frequency_scaling(TCS3200_OFREQ_20P);
    // Set up sensor - Arduino pins & sensor frequency

    Serial.begin(115200);
    delay(500);

}

void loop(){

    // RGBColor rgb_color = tcs3200.read_rgb_color();
    // Read colour from sensor

    // Serial.println("Red: " + String(rgb_color.red));
    // Serial.println("Green: " + String(rgb_color.green));
    // Serial.println("Blue: " + String(rgb_color.blue));
    // Serial.println("Dominant color: " + color_indices[tcs3200.get_rgb_dominant_color()]);
    // Print colouur sensor data

    HSVColor hsv = tcs3200.read_hsv();
    Serial.println("Hue: " + String(hsv.hue));
    Serial.println("Saturation: " + String(hsv.saturation));
    Serial.println("Value: " + String(hsv.value));

    Serial.println("-----------------------------------");

    delay(500);

}