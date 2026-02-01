// #include <Arduino.h>

// // pin definitions
// // #define S0 11
// // #define S1 12
// #define S2 A5
// #define S3 7
// #define OUT_PIN 8

// volatile unsigned long pulseCount = 0;

// // Calibration data
// unsigned long blackCal[3] = {0, 0, 0};
// unsigned long whiteCal[3] = {1, 1, 1};
// bool calibrated = false;

// void pulseISR() { pulseCount++; }
// // read frequency for given S2, S3 settings
// unsigned long readFrequency(uint8_t s2, uint8_t s3) {
//   digitalWrite(S2, s2);
//   digitalWrite(S3, s3);

//   pulseCount = 0;
//   delay(5);  // settle

//   unsigned long start = millis();
//   while (millis() - start < 100) {
//     // counting pulses
//   }
//   return pulseCount * 10;  // Hz
// }

// // rgb read
// void readRGB(unsigned long rgb[3]) {
//   rgb[0] = readFrequency(LOW, LOW);    // RED
//   rgb[1] = readFrequency(HIGH, HIGH);  // GREEN
//   rgb[2] = readFrequency(LOW, HIGH);   // BLUE
// }

// float normalize(unsigned long v, unsigned long b, unsigned long w) {
//   if (w <= b) return 0.0;
//   float n = (float)(v - b) / (float)(w - b);
//   return constrain(n, 0.0, 1.0);
// }

// // calibration routine
// void calibrate() {
//   unsigned long temp[3];

//   Serial.println("\n--- CALIBRATION MODE ---");
//   Serial.println("Place BLACK object and press any key");
//   while (!Serial.available()) {
//   }
//   Serial.read();
//   delay(300);
//   readRGB(blackCal);

//   Serial.print("Black → R:");
//   Serial.print(blackCal[0]);
//   Serial.print(" G:");
//   Serial.print(blackCal[1]);
//   Serial.print(" B:");
//   Serial.println(blackCal[2]);

//   Serial.println("Place WHITE object and press any key");
//   while (!Serial.available()) {
//   }
//   Serial.read();
//   delay(300);
//   readRGB(whiteCal);

//   Serial.print("White → R:");
//   Serial.print(whiteCal[0]);
//   Serial.print(" G:");
//   Serial.print(whiteCal[1]);
//   Serial.print(" B:");
//   Serial.println(whiteCal[2]);

//   calibrated = true;
//   Serial.println("Calibration saved.\n");
// }

// // color classification, adjust as needed
// const char* classify(float r, float g, float b) {
//   if (r > g && r > b && r > 0.2) return "RED";
//   if (g > r && g > b && g > 0.05) return "GREEN";
//   if (b > r && b > g && b > 0.2) return "BLUE";
//   if (r > 0.35 && g > 0.35 && b > 0.35) return "WHITE";
//   if (r < 0.1 && g < 0.1 && b < 0.1) return "BLACK";
//   return "UNKNOWN";
// }

// // setup with tune
// void setup() {
//   Serial.begin(115200);
//   while (!Serial) {
//   }

//   // pinMode(S0, OUTPUT);
//   // pinMode(S1, OUTPUT);
//   pinMode(S2, OUTPUT);
//   pinMode(S3, OUTPUT);
//   pinMode(OUT_PIN, INPUT);

//   // 20% frequency scaling
//   // digitalWrite(S0, HIGH);
//   // digitalWrite(S1, LOW);

//   attachInterrupt(digitalPinToInterrupt(OUT_PIN), pulseISR, RISING);

//   Serial.println("=== TCS3200 READY ===");
//   Serial.println("Press:");
//   Serial.println("  c → calibrate");
//   Serial.println("  t → test mode");
// }

// // main
// void loop() {
//   // Check user input
//   if (Serial.available()) {
//     char cmd = Serial.read();
//     if (cmd == 'c') calibrate();
//     if (cmd == 't') {
//       if (!calibrated) {
//         Serial.println("⚠ Calibrate first (press 'c')");
//       } else {
//         Serial.println("\n--- TEST MODE ---");
//       }
//     }
//   }

//   if (!calibrated) return;

//   // Test mode output
//   unsigned long raw[3];
//   readRGB(raw);

//   float r = normalize(raw[0], blackCal[0], whiteCal[0]);
//   float g = normalize(raw[1], blackCal[1], whiteCal[1]);
//   float b = normalize(raw[2], blackCal[2], whiteCal[2]);

//   Serial.print("RGB = ");
//   Serial.print(r, 2);
//   Serial.print(", ");
//   Serial.print(g, 2);
//   Serial.print(", ");
//   Serial.print(b, 2);

//   Serial.print(" → ");
//   Serial.println(classify(r, g, b));

//   delay(250);
// }