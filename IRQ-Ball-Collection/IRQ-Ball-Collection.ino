#include <POP32.h>
#define SONAR_READ_CM (analog(8) * 100) / 4095  // Read analog raw data and convert it to centimeter.
#define SPD 45                                  // Determine speed value.
#define kpsonar 5                               // Determine threshold between ultrasonic sensor and wall.
#define kpspin_t 350                            // Determine spin left or right time.
#define kpifr 1500                              // Determine threshold of black line detection.
#define kpfreq 500                              // Determine sound frequency.
#define kpstop_t 300                            // Determine how long the robot stops.

#define sv2d 130    //Determine position servo 2 dribble the ball
#define sv2u 10     //Determine position servo 2 pick the ball
#define sv2d20 120  //Determine position servo 2 drop the ball on the 20 mm base.
#define sv2d30 110  //Determine position servo 2 drop the ball on the 30 mm base.
#define sv2d40 100  //Determine position servo 2 drop the ball on the 40 mm base.
#define sv2d50 90   //Determine position servo 2 drop the ball on the 50 mm base.
#define sv1p 125    //Determine position servo 1 grab the ball
#define sv1d 10     //Determine position servo 1 drop the ball
void setup() {
  Setservo();
  sw_ok_press();
  yellowball();
  blueball();
  greenball();
  redball();
}

void loop() {
}

void yellowball() {
  track(40);
  right();
  track_sonar(30);
  fd(20);
  delay(80);
  ao();
  pickup();
  bk(30);
  delay(250);
  ao();
  left();
  track(40);
  track(40);
  track(40);
  left();
  track_sonar(30);
  fd(20);
  delay(180);
  ao();
  drop20();
  bk(30);
  delay(300);
  ao();
  right();
}
void blueball() {
  track(30);
  left();
  track_sonar(30);
  fd(20);
  delay(100);
  ao();
  pickup();
  bk(30);
  delay(300);
  ao();
  left();
  track(40);
  track(40);
  track(40);
  left();
  track_sonar(30);
  fd(20);
  delay(200);
  ao();
  drop40();
  bk(30);
  delay(300);
  ao();
  right();
}
void greenball() {
  track(30);
  right();
  track(40);
  right();
  track(40);
  left();
  track_sonar(30);
  fd(20);
  delay(100);
  ao();
  pickup();
  bk(30);
  delay(300);
  ao();
  left();
  track(40);
  left();
  track(40);
  left();
  track(40);
  track_sonar(30);
  fd(20);
  delay(200);
  ao();
  drop30();
  bk(30);
  delay(300);
  ao();
  right();
}
void redball() {
  track(30);
  left();
  track_sonar(30);
  fd(20);
  delay(100);
  ao();
  pickup();
  bk(30);
  delay(300);
  ao();
  left();
  track(30);
  left();
  track(40);
  track(40);
  track_sonar(30);
  fd(20);
  delay(200);
  ao();
  drop50();
  bk(30);
  delay(300);
  ao();
  right();
  track(30);
  right();
  track(30);
}
void Setservo() {
  servo(2, sv2u);
  delay(300);
  servo(1, sv1d);
  delay(300);
}
void pickup() {
  for (int i = sv2u; i < sv2d; i++) {
    servo(2, i);
    delay(10);
  }
  for (int i = sv1d; i < sv1p; i++) {
    servo(1, i);
    delay(10);
  }
  for (int i = sv2d; i > sv2u; i--) {
    servo(2, i);
    delay(10);
  }
}
void drop20() {
  for (int i = sv2u; i < sv2d20; i++) {
    servo(2, i);
    delay(10);
  }
  for (int i = sv1p; i > sv1d; i--) {
    servo(1, i);
    delay(10);
  }
  for (int i = sv2d20; i > sv2u; i--) {
    servo(2, i);
    delay(10);
  }
}
void drop30() {
  for (int i = sv2u; i < sv2d30; i++) {
    servo(2, i);
    delay(10);
  }
  for (int i = sv1p; i > sv1d; i--) {
    servo(1, i);
    delay(10);
  }
  for (int i = sv2d30; i > sv2u; i--) {
    servo(2, i);
    delay(10);
  }
}
void drop40() {
  for (int i = sv2u; i < sv2d40; i++) {
    servo(2, i);
    delay(10);
  }
  for (int i = sv1p; i > sv1d; i--) {
    servo(1, i);
    delay(10);
  }
  for (int i = sv2d40; i > sv2u; i--) {
    servo(2, i);
    delay(10);
  }
}
void drop50() {
  for (int i = sv2u; i < sv2d50; i++) {
    servo(2, i);
    delay(10);
  }
  for (int i = sv1p; i > sv1d; i--) {
    servo(1, i);
    delay(10);
  }
  for (int i = sv2d50; i > sv2u; i--) {
    servo(2, i);
    delay(10);
  }
}
void track(int speed) {
  while (1) {
    if (analog(0) > kpifr && analog(1) > kpifr) {
      fd(speed);
    } else if (analog(0) < kpifr && analog(1) > kpifr) {
      sl(speed);
    } else if (analog(0) > kpifr && analog(1) < kpifr) {
      sr(speed);
    } else if (analog(0) < kpifr && analog(1) < kpifr) {
      ao();
      fd(30);
      delay(200);
      break;
    }
  }
}
void track_sonar(int speed) {
  while (SONAR_READ_CM > kpsonar) {
    if (analog(0) > kpifr && analog(1) > kpifr) {
      fd(speed);
    } else if (analog(0) < kpifr && analog(1) > kpifr) {
      sl(speed);
    } else if (analog(0) > kpifr && analog(1) < kpifr) {
      sr(speed);
    } else if (analog(0) < kpifr && analog(1) < kpifr) {
      ao();
      break;
    }
  }
  ao();
}
void left() {
  sl(30);
  delay(300);
  while (analog(0) > kpifr) {
    sl(30);
  }
  while (analog(0) < kpifr) {
    sl(30);
  }
  ao();
  delay(300);
}
void right() {
  sr(30);
  delay(300);
  while (analog(1) > kpifr) {
    sr(30);
  }
  while (analog(1) < kpifr) {
    sr(30);
  }
  ao();
  delay(300);
}