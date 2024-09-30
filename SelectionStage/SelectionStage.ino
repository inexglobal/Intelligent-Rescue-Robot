#include <POP32.h>
int Stage = 1;
void setup() {
  oled.mode(2);
  oled.text(0, 0, "SW_B go to stage 1");
  oled.text(2, 0, "SW_A go to stage 2");
  oled.text(4, 0, "SW_OK go to stage 3");
  oled.show();
  while(1){
    if(SW_B()){
      Stage=1;beep();break;
    }
    if(SW_A()){
      Stage=2;beep();break;
    }
    if(SW_OK()){
      Stage=3;beep();break;
    }
  }
  oled.clear();
}
void loop() {
  if(Stage==1){
    oled.text(0, 0, "Stage = 1");
    oled.show();

    /* ----- Start Sequence Command---   */ 
    oled.text(1, 0, "Loop  1 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  2 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  3 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  4 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  5 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  6 ");oled.show();delay(500);
    /* ----- End ---   */

    oled.clear();
    Stage=2;
  }else if (Stage==2){
    oled.text(0, 0, "Stage = 2");
    oled.show();

    /* ----- Start Sequence Command---   */
    int Timer = 0;
    while(1){
      Timer++;
      oled.text(1, 0, "Loop  %d ",Timer);
      oled.show();
      if(Timer >= 6){  
        break;   // End loop while
      }
      delay(500);
    }
   /* ----End---- */

    oled.clear();
    Stage=3;
  }else if (Stage==3){
    oled.text(0, 0, "Stage = 3");
    oled.show();

    /* ----Start Sequence Command---- */
    oled.text(1, 0, "Loop  1 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  2 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  3 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  4 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  5 ");oled.show();delay(500);
    oled.text(1, 0, "Loop  6 ");oled.show();delay(500);
   /* ----End---- */

    oled.clear();
    Stage=4;
  }else{
    oled.text(0, 0, "End Stage ");
    oled.show();
    while(1);
  }


}
