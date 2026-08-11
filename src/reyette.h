#pragma once
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void initDisplay();
void centerText(const char* text, int y, int size=1);
void typewriterText(const char* text, int y, int size, int charDelay);
void scrambleToText(const char* target, int y, int size, int stepDelay);
void scrambleTypewriterText(const char* target, int y, int size, int charDelay);
void errorScreenEffect();
