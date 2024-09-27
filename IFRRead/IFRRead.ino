#include <POP32.h>
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.text(2, 0, "L:%d   ", analog(0));
  oled.text(4, 0, "R:%d   ", analog(1));
  oled.show();
}