#define SONAR_READ_CM (analog(5) * 100) / 4095  // Read analog raw data and convert it to centimeter.
#define SPD 45                                  // Determine speed value. (0 to 100)
#define kpsonar 7                               // Determine threshold between ultrasonic sensor and wall.
#define kpspin_t 350                            // Determine spin left or right time.
#define kpifr 1500                              // Determine threshold of black line detection.
#include <POP32.h>                              // Include POP-32 Board Library
void fdSONAR(int cm) {
  // Use fd2 function
  fd2(SPD - 2, SPD);
  while (SONAR_READ_CM > cm);
  ao();
  sound(500, 300);
}
void slMAZE(int sl_t) {
  sl(SPD);
  delay(sl_t);
  ao();
  delay(300);
}
void srMAZE(int sr_t) {
  sr(SPD);
  delay(sr_t);
  ao();
  delay(300);
}
void bkSW() {
  while (1) {
    if (!in(22) && !in(23)) {
      bk(SPD);
      sound(500, 300);
      ao();
      delay(300);
      break;
    } else if (in(22) && !in(23)) {
      sl(SPD);
    } else if (!in(22) && in(23)) {
      sr(SPD);
    } else {
      bk(SPD);
    }
  }
}
void stopline(int ifr) {
  fd2(SPD - 2, SPD);
  while (analog(2) > ifr);
  ao();
  sound(500, 300);
}
void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly:
  waitSW_OK_bmp();
  fdSONAR(kpsonar);
  srMAZE(kpspin_t);
  bkSW();
  fdSONAR(kpsonar);
  slMAZE(kpspin_t);
  bkSW();
  fdSONAR(kpsonar);
  slMAZE(kpspin_t);
  bkSW();
  fdSONAR(kpsonar);
  slMAZE(kpspin_t);
  bkSW();
  fdSONAR(kpsonar);
  srMAZE(kpspin_t);
  bkSW();
  fdSONAR(kpsonar);
  srMAZE(kpspin_t);
  bkSW();
  stopline(kpifr);
}
