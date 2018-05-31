#include "sensors.h"
#include "movements.h"
#include <SoftwareSerial.h>

SoftwareSerial lzserial(13, 17);

#define L_EYE=A4;
#define R_EYE=A5;
#define L_EAR=A6;
#define R_EAR=A7;

int H = 9 , N1 = 10, N2 = 11, SPINE = 12, LS = 8, LA = 6, LT = 16, LN = 5, LF = 4, RS = 3, RA = 2, RT = 15, RN = 7, RF = 14;
int head_position = 2;
int mood_count = 0;
int lost_human = 0;
int mood_limit = 10;

unsigned char bytes[2];
int counter = 0;




//motions..............................................................................................................
void head_check_left() {
  set(H,30);
  give_pwm(5);
}

void head_check_right() {
  set(H,150);
  give_pwm(5);
}

void check_half_left() {
  set(H,60);
  give_pwm(5);
}

void check_half_right() {
  set(H,120);
  give_pwm(5);
}

void head_return() {
  set(H,90);
  set(N1,120);
  set(N2,40);
  give_pwm(5);
}

void check_low() {
  set(N1,90);
  set(N2,90);
  give_pwm(5);
}

void check_high() {
  set(N1,135);
  set(N2,40);
  give_pwm(5);
}

void random_head_check(int looptimes){
    
  randomSeed(analogRead(A1));
  looptimes=looptimes*(random(3)+1);
    for(int i=0;i<looptimes;i++){
      int todo=random(7);
      int delaytime=random(1000)+200;
      if(todo==0){
        head_return();  
      }  
      if(todo==1){
        head_check_left();  
      }
      if(todo==2){
        head_check_right();  
      }
      if(todo==3){
        check_half_left();
      }
      if(todo==4){
        check_half_right();  
      }
      if(todo==5){
        check_low();  
      }
      if(todo==6){
        check_high();  
      }
      delay(delaytime);
    }
}

void walk_forward() {
  check_low();
  int LTv = 0;
  int RTv = 0;
  int LFv = 70;
  int RFv = 70;
  int LNv = 80;
  int RNv = 70;
  int LSv=65;
  int RSv=65;
  int LAv=5;
  int RAv=90;
  set(LN, 80);
  set(RN, 70);
  set(LA,5);
  give_pwm(5);
  for (int i = 0; i < 12; i++) {
    LTv += 4;
    RTv += 4;
    LFv -= 4;
    RFv -= 4;
    RSv+=4;
    LSv-=2;
    LAv+=2;
    RAv-=4;
    set(LT, LTv);
    set(RT, RTv);
    set(LF, LFv);
    set(RF, RFv);
    set(LS, LSv);
    set(RS, RSv);
    set(LA, LAv);
    set(RA, RAv);
    give_pwm(1);
  }
  set(RA,20);
  give_pwm(5);
  for (int i = 0; i < 12; i++) {
    LTv += 4;
    RTv += 4;
    LNv+=6;
    RNv+=4;
    LSv+=2;
    RSv-=2;
    RAv-=8;
    set(LT, LTv);
    set(RT, RTv);
    set(LN, LNv);
    set(RN, LNv);
    set(LS, LSv);
    set(RS, RSv);
    set(LA, LAv);
    set(RA, RAv);
    give_pwm(1);
  }
  set(LT, 80);
  set(RT, 90);
  set(LF, 12);
  set(RF, 10);
  set(LS, 50);
  set(RS, 50);
  set(LA, 50);
  set(RA, 90);
  give_pwm(4);
  set(LS, 50);
  set(RS, 50);
  set(LN, 180);
  set(RN, 180);
  give_pwm(2);
  set(LS, 50);
  set(RS, 50);
  set(LN, 0);
  set(RN, 0);
  set(LF, 0);
  set(RF, 0);
  give_pwm(3);
  reset();
  set(LF, 0);
  set(RF, 0);
  give_pwm(5);
  reset();
  give_pwm(5);
}

void move_right() {
  head_check_right();
  set(LS,90);
  set(LA,30);

  set(RS,90);
  set(RA,30);
  
  set(LT,15);
  set(RT,15);
  set(LF,80);
  set(RF,80);
  give_pwm(4);
  
  for(int i=0;i<10;i++){
    set(SPINE,110);
  set(LS,30);
  set(RS,30);
  
  set(LT,90);
  set(LN,30);
  set(LF,0);

  set(RT,10);
  set(RN,80);
  give_pwm(1);
  delay(20);
    }
  reset();
  give_pwm(20);
}

void move_left() {
  head_check_left();
  set(LS,90);
  set(LA,30);

  set(RS,90);
  set(RA,30);
  
  set(LT,15);
  set(RT,15);
  set(LF,80);
  set(RF,80);
  give_pwm(4);
  
  for(int i=0;i<10;i++){
  set(SPINE,50);
  set(LS,30);
  set(RS,30);
  
  set(RT,90);
  set(RN,30);
  set(RF,0);

  set(LT,10);
  set(LN,80);
  give_pwm(1);  
  delay(20);
  }
  reset();
  give_pwm(20);
  delay(1000);
}

void random_walk(){
  randomSeed(analogRead(A1));
  int looptimes=random(3)+1;
    for(int i=0;i<looptimes;i++){
      int todo=random(3);
      int delaytime=random(500)+200;
      if(todo==0){
        walk_forward();  
      }  
      if(todo==1){
        move_left();  
      }
      if(todo==2){
        move_right();  
      }
      delay(delaytime);
    }
}

void run_forward() {
  check_low();
  set(LT, 30);
  set(RT, 30);
  set(LF, 50);
  set(RF, 50);
  set(LN, 100);
  set(RN, 90);
  set(LS, 20);
  set(RS, 20);
  set(LA, 20);
  set(RA, 40);
  give_pwm(6);
  set(LT, 80);
  set(RT, 90);
  set(LF, 2);
  set(RF, 0);
  set(LS, 50);
  set(RS, 50);
  set(LA, 50);
  set(RA, 90);
  give_pwm(6);
  reset();
  set(LS, 50);
  set(RS, 50);
  set(LN,25);
  set(RN,25);
  set(LF, 0);
  set(RF, 0);
  give_pwm(4);
  reset();
  set(LS, 50);
  set(RS, 50);
  give_pwm(8);
  reset();
  give_pwm(3);
}

void run_left() {
  head_check_left();
  set(LS,90);
  set(LA,30);

  set(RS,90);
  set(RA,30);
  
  set(LT,15);
  set(RT,15);
  set(LF,80);
  set(RF,80);
  give_pwm(4);
  
  set(SPINE,50);
  set(LS,30);
  set(RS,30);
  
  set(RT,90);
  set(RN,30);
  set(RF,0);

  set(LT,10);
  set(LN,80);
  give_pwm(10);
  reset();
  give_pwm(20);
  delay(1000);
}

void run_right() {
  head_check_right();
  set(LS,90);
  set(LA,30);

  set(RS,90);
  set(RA,30);
  
  set(LT,15);
  set(RT,15);
  set(LF,80);
  set(RF,80);
  give_pwm(4);
  
    set(SPINE,110);
  set(LS,30);
  set(RS,30);
  
  set(LT,90);
  set(LN,30);
  set(LF,0);

  set(RT,10);
  set(RN,80);
  give_pwm(10);
  reset();
  give_pwm(20);
}

void random_run(){
  randomSeed(analogRead(A1));
  int looptimes=random(3)+1;
    for(int i=0;i<looptimes;i++){
      int todo=random(3);
      int delaytime=random(200)+200;
      if(todo==0){
        run_forward();  
      }  
      if(todo==1){
        run_left();  
      }
      if(todo==2){
        run_right();  
      }
      delay(delaytime);
    }
}

void roll() {
}

void stand() {
}

void prone() {
  check_low();
  for(int i=0;i<8;i++){
      set(LT,80);
      set(RT,80);
      set(LN,20);
      set(RN,20);
      set(LF,0);
      set(RF,0);
      set(LS,130);
      set(RS,130);
      set(LA,0);
      set(RA,0);
      give_pwm(1);
      delay(30);
  }
  int looptimes=random(2)+1;
  random_head_check(looptimes);
  reset();
  give_pwm(6);
  delay(500);
}

void poof(){
  
}
void jump() {
}

void rob_face() {
}

void push() {
}

void fall() {
}
//motions..............................................................................................................




void setup() {
  for (int i = 2; i < 17; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
  lzserial.begin(9600);
  sort();
  get_dtime();
  set(SPINE,80);
  set(LS, 65);
  set(RS, 65);
  set(LT, 0);
  set(RT, 0);
  set(N1, 120);
  set(N2, 40);
  set(LN, 70);
  set(RN, 60);
  set(LF, 70);
  set(RF, 70);

  change_reset();
  while (!Serial) {
  }
}

float check_distance() {
  Serial.write(0XA0);
  delay(10);
  while (Serial.available()) {
    bytes[counter] = Serial.read();
    //Serial.println(bytes[counter]);
    counter++;
  }
  counter = 0;
  return (bytes[0] << 8)&bytes[1];
}


void do_normal() {
  Serial.println("doing normal");
  int todo = random(1);
}
void do_happy() {
  Serial.println("doing happy");
  int todo = random(1);
}
void do_relaxed() {
  Serial.println("doing relaxed");
  int todo = random(1);
}
void do_scared() {
  Serial.println("doing scared");
  int todo = random(1);
}



void primary() {
  randomSeed(analogRead(A0));
  situation_now = situation();
  if (situation_now == 9) {
    mood = 4;
    mood_count = 0;
    do_scared();
  }
  if (mood == 1) {
    if (situation_now == 4 || situation_now == 5 || situation_now == 6) {
      mood = 2;
      mood_count = 0;
      do_happy();
    }
    else if (situation_now == 8) {
      reset();
      head_check_left();
      Serial.println("check_left");
    }
    else if (situation_now = 7) {
      reset();
      head_check_right();
      Serial.println("check_right");
    }
    else {
      do_normal();
    }
  }
  else if (mood == 2) {
    if (situation_now != 4 && situation_now != 5 && situation_now != 6) {
      if (lost_human == 0) {
        lost_human++;
        do_happy();
      }
      else if (lost_human == mood_limit) {
        mood = 1;
        mood_count = 0;
        lost_human = 0;
        do_normal();
      }
      else {
        lost_human++;
        do_happy();
      }
    }
    if (mood_count == mood_limit) {
      mood = 3;
      mood_count = 0;
      do_relaxed();
    }
    else {
      lost_human = 0;
      mood_count++;
      do_happy();
    }
  }
  else if (mood == 3) {
    if (situation_now != 4 && situation_now != 5 && situation_now != 6) {
      if (lost_human == 0) {
        lost_human++;
        do_relaxed();
      }
      else if (lost_human == mood_limit) {
        mood = 1;
        lost_human = 0;
        do_normal();
      }
      else {
        lost_human++;
        do_relaxed();
      }
    }
    else {
      lost_human = 0;
      do_relaxed();
    }

  }
  else if (mood == 4) {
    if (situation_now == 9) {
      mood_count = 0;
      do_scared();
    }
    else if (situation_now == 4 || situation_now == 5 || situation_now == 6) {
      mood = 2;
      mood_count = 0;
      do_happy();
    }
    else if (situation_now != 4 && situation_now != 5 && situation_now != 6 && situation_now != 9 && mood_count < mood_limit) {
      mood_count++;
      do_scared();
    }
    else {
      mood = 1;
      mood_count = 0;
      do_normal();
    }
  }
}

void test_loop() {
  randomSeed(analogRead(A0));
  int todo=random(4);
  if(todo==0){
    random_run();  
  }
  if(todo==1){
    random_head_check(1);  
  }
  if(todo==2){
    random_walk();  
  }
  if(todo==3){
    prone();  
  }
}

void loop(){
  test_loop();
}
