#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "center_text.h"
#include <list>
#include <string>
using std::list;
using std::string;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define CENTER_WIDTH 64
#define CENTER_HEIGHT 32

// I2C-pins to ESP32 
#define OLED_SDA 21
#define OLED_SCL 22

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);



void setup() {
  Serial.begin(115200);

  // Start I2C with defined pins
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialisering fejlede");
    for (;;); // Stop program due to error
  }

  centerPrint("Hello, World!", 1, 0); // Example usage of centerPrint
}

unsigned long previousMillis = 0;
const unsigned long interval = 1000; 

list<string> textList = {
    "Hello, World!",
    "This is a test.",
    "Centering text is fun!",
    "Adafruit SSD1306",
    "ESP32 with OLED"
};

int i = 0;

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

    if (i > 4) {
        i = 0; // Reset index if it exceeds the list size
    }
    auto it = textList.begin();
    std::advance(it, i);
    centerPrint(*it, 1, 0); // Print centered text
    i++;
  }
}
