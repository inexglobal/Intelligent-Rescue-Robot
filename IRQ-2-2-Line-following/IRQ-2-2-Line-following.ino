#include <POP32.h>
int ref = 1500;
void setup() {
}
void loop() {
  waitSW_OK();
  fd(40);
  delay(250);
  track();
}
void track() {
  while (1) {
    if (analog(0) > ref && analog(1) > ref) {
      Motor(40, 40, 1);
    } else if (analog(0) < ref && analog(1) > ref) {
      Motor(40, 0, 1);
    } else if (analog(0) > ref && analog(1) < ref) {
      Motor(0, 40, 1);
    } else if (analog(0) < ref && analog(1) < ref) {
      Motor(20, 20, 350);
      Motor(0, 0, 10);
      break;
    }
  }
}
void Motor(int L, int R, int T) {
  motor(1, L);
  motor(2, R);
  delay(T);
}
