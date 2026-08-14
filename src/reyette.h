#pragma once
#include <Adafruit_SSD1306.h>

extern Adafruit_SSD1306 display;

void initDisplay();
void showLogo();
void centerText(const char* text, int y, int size=1);
void typewriterText(const char* text, int y, int size, int charDelay);
void scrambleToText(const char* target, int y, int size, int stepDelay);
void scrambleTypewriterText(const char* target, int y, int size, int charDelay);
void errorScreenEffect();

#if defined(LCD32)
  #define SCREEN_HEIGHT 32
#elif defined(LCD64)
  #define SCREEN_HEIGHT 64
#else
  #error "Use LCD32 or LCD64"
#endif

#define SCREEN_WIDTH 128
#define OLED_BIG (SCREEN_HEIGHT == 64)
