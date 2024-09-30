#include <POP32.h>
int ref = 1500;
void setup() {
  // put your setup code here, to run once:
}
void loop() {
  waitSW_OK();
  track();
  left();
  track();
  right();
}

void track() {
  while (1) {
    if (analog(0) > ref && analog(1) > ref) {
      Motor(50, 50, 1);
    } else if (analog(0) < ref && analog(1) > ref) {
      Motor(50, 0, 1);
    } else if (analog(0) > ref && analog(1) < ref) {
      Motor(0, 50, 1);
    } else if (analog(0) < ref && analog(1) < ref) {
      Motor(20, 20, 300);
      Motor(0, 0, 10);
      break;
    }
  }
}

void left() {
  Motor(-50, 50, 200);
  while (analog(0) > ref) {
    Motor(-50, 50, 1);
  }
  while (analog(0) < ref) {
    Motor(-50, 50, 1);
  }
  // while (analog(1) > ref) {
  //   Motor(-30, 30, 1);
  // }
  Motor(0, 0, 1);
}
void right() {
  Motor(50, -50, 200);
  while (analog(1) > ref) {
    Motor(50, -50, 1);
  }
  while (analog(1) < ref) {
    Motor(50, -50, 1);
  }
  // while (analog(0) > ref) {
  //   Motor(30, -30, 1);
  // }
  Motor(0, 0, 1);
}
void Motor(int L, int R, int T) {
  motor(1, L);
  motor(2, R);
  delay(T);
}