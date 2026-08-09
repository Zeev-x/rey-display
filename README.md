# ReyDisplay
Tampilkan teks di layar esp32 mu dengan mudah.

## How to use

Example code:
```cpp
#include <reyette.h>

void setup(){
  initDisplay();
  display.clearDisplay();
  centerText("Center", 10, 1);
  typewriterText("Typewriter", 22, 1, 100);
  scrambleToText("Scramble", 35, 1, 100);
  scrambleTypewriterText("scrambleTypewriter", 48, 1, 100);
}

void loop(){
  //Loop code here
}
```
