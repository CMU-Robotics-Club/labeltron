#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_APDS9960.h>

Adafruit_APDS9960 apds;

void setup() {
  Serial.begin(115200);
  apds.begin();
  apds.enableColor();
}

void loop() {
  if (apds.colorDataReady()) {
    uint16_t r, g, b, c;
    apds.getColorData(&r, &g, &b, &c);
    if (r > g + b) Serial.print('w');
    else if (g > r + b) Serial.print('n');
    else Serial.print(' ');
  }
}