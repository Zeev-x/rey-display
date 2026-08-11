# ReyDisplay
Tampilkan teks di layar esp32 mu dengan mudah.

## How to use

Example code in main.cpp:
```cpp
#include <Arduino.h>
#include "reyette.h"

#define OLED_BIG (SCREEN_HEIGHT == 64)

void setup(){
  initDisplay();
}

void loop(){
  #if OLED_BIG
  display.clearDisplay();
  centerText("Center", 10, 1);
  typewriterText("Typewriter", 22, 1, 100);
  scrambleToText("Scramble", 35, 1, 100);
  scrambleTypewriterText("scrambleTypewriter", 48, 1, 100);
  #else
  display.clearDisplay();
  centerText("Center", 16, 1);
  delay(1000);
  display.clearDisplay();
  typewriterText("Typewriter", 16, 1, 100);
  delay(1000);
  display.clearDisplay();
  scrambleToText("Scramble", 16, 1, 100);
  delay(1000);
  display.clearDisplay();
  scrambleTypewriterText("ScrambleTypewriter", 16, 1, 100);
  delay(1000);
  #endif
}
```

---
If you use lcd 32x128,in plaformio.ini add this:
```ini
build_flags = -DLCD32
```

---
If you use lcd 64x128,in plaformio.ini add this:
```ini
build_flags = -DLCD64
```
