#include "center_text.h"

#include <string>

void centerPrint(const std::string& text, int font, int height) {
    // This function is not used in the current context, but can be implemented if needed.
    display.clearDisplay();
    display.setTextSize(font);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(centerText(text, font), height);
    display.println(text.c_str());
    display.display();
}

int16_t centerText(const std::string& text, int font) {


    // Calculate the width of the text based on the font size
    int wid = calculateWidth(text, font); 

    int16_t padding = CENTER_WIDTH - (wid / 2);
    return padding;
}

int calculateWidth(const std::string& text, const int fontSize ) {

    // 1 is default 6x8, 2 is 12x16, 3 is 18x24, etc
    int fontRatio = fontSize * 6;

    return text.length() * fontRatio;
}