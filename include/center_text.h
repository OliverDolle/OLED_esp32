#ifndef CENTER_TEXT_H
#define CENTER_TEXT_H

#include <string>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define CENTER_WIDTH 64

extern Adafruit_SSD1306 display;
// Centers the given text within the specified width.
// Returns the centered string.
void centerPrint(const std::string& text, int font, int height);
int16_t centerText(const std::string& text, int font);
int calculateWidth(const std::string& text, const int fontSize );


#endif // CENTER_TEXT_H