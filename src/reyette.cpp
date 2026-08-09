#include "config.h"
#include "reyette.h"

#define OLED_BIG (SCREEN_HEIGHT == 64)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void initDisplay() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  randomSeed(analogRead(0));
  display.clearDisplay();
  scrambleTypewriterText("Reyette-Project", 10, 1, 50);
  typewriterText("ESP32", 24, 3, 200);
  errorScreenEffect();
  display.display();
  delay(200);
  display.clearDisplay();
}

//Text default no animation
void centerText(const char* text, int y, int size) {
  int16_t x1,y1;
  uint16_t w,h;

  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  display.getTextBounds(text,0,0,&x1,&y1,&w,&h);
  display.setCursor((SCREEN_WIDTH-w)/2,y);
  display.print(text);
}

//Type writer animation
void typewriterText(const char* text, int y, int size, int charDelay) {
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(text, 0, y, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  for (int i = 0; text[i] != '\0'; i++) {
    display.fillRect(x, y, w, h, SSD1306_BLACK);
    display.setCursor(x, y);
    for (int j = 0; j <= i; j++) {
      display.print(text[j]);
    }
    display.display();
    delay(charDelay);
  }
}

// Random Text Animation
void scrambleToText(const char* target, int y, int size, int stepDelay) {
  int len = strlen(target);
  char buffer[64];
  strcpy(buffer, target);

  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);

  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(target, 0, y, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;

  const char charset[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*()-_=+[]{};:,.<>?/";

  int charsetLen = strlen(charset);
  for (int i = 0; i < len; i++) buffer[i] = charset[random(charsetLen)];
  for (int i = 0; i < len; i++) {
    int spins = random(2, 6);
    for (int s = 0; s < spins; s++) {
      buffer[i] = charset[random(charsetLen)];
      display.fillRect(x, y, w, h, SSD1306_BLACK);
      display.setCursor(x, y);
      display.print(buffer);
      display.display();
      delay(stepDelay / 2);
    }
    buffer[i] = target[i];
    display.fillRect(x, y, w, h, SSD1306_BLACK);
    display.setCursor(x, y);
    display.print(buffer);
    display.display();
    delay(stepDelay);
  }
}

//Scramble X Typewriter animation
void scrambleTypewriterText(const char* target, int y, int size, int charDelay) {
  int len = strlen(target);
  char buffer[64];
  strcpy(buffer, target);
  display.setTextSize(size);
  display.setTextColor(SSD1306_WHITE);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(target, 0, y, &x1, &y1, &w, &h);
  int x = (SCREEN_WIDTH - w) / 2;
  const char charset[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "!@#$%^&*()-_=+[]{};:,.<>?/";
  int charsetLen = strlen(charset);
  for (int i = 0; i < len; i++) {
    int spins = random(2, 6);
    for (int s = 0; s < spins; s++) {
      buffer[i] = charset[random(charsetLen)];
      display.fillRect(x, y, w, h, SSD1306_BLACK);

      display.setCursor(x, y);
      for (int j = 0; j <= i; j++) {
        display.print(buffer[j]);
      }
      display.display();

      delay(charDelay / 2);
    }

    buffer[i] = target[i];
    display.fillRect(x, y, w, h, SSD1306_BLACK);
    display.setCursor(x, y);
    for (int j = 0; j <= i; j++) {
      display.print(buffer[j]);
    }
    display.display();

    delay(charDelay);
  }
}

//SFX
void errorScreenEffect(){
  auto sfx = [](int z, int a){
    for (int x = 0; x < a; x++){
      display.invertDisplay(true);
      delay(z);
      display.invertDisplay(false);
      delay(z);
    }
  };

  int S = random(1, 6);
  int F = random(20, 101);
  int X = random(500, 1001);

  sfx(F, S);
  delay(X);
}
