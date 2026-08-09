# ReyDisplay
Tampilkan teks di layar esp32 mu dengan mudah.

## How to use

Example code:
```cpp
#include <reyette.h>

void setup(){
  initDisplay();
  centerText("Center Text", 1, 2);
  typewriterText("Typewriter Text", 10, 1, 100);
  scrambleToText("Scramble Text", 10, 1, 100);
  scrambleTypewriterText("scrambleTypewriter Text", 10, 1, 100);
}
```
