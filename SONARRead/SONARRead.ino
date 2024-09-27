#include <POP32.h>
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.text(1,0,"RAW:%d    ", analog(8));
  oled.text(3,0,"DISTANCE:%d CM   ", analog(8) * 100 / 4095);
  oled.show();
}