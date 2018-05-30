#include "sensors.h"
#include "movements.h"
#include <SoftwareSerial.h>

SoftwareSerial lzserial(13,17);

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
}

void head_check_right() {
}

void check_half_left() {
}

void check_half_right() {
}

void head_return() {
}

void check_low() {
}

void check_high() {
}

void walk_forward() {
}

void walk_left() {
}

void walk_right() {
}

void run_forward() {
  set(LT,30);
  set(RT,30);
  set(LF,50);
  set(RF,50);
  set(LN,100);
  set(RN,90);
  set(LS,20);
  set(RS,20);
  set(LA,20);
  set(RA,40);
  give_pwm(10);
  delay(5);
  set(LT,90);
  set(RT,90);
  set(LF,12);
  set(RF,10);
  set(LS,50);
  set(RS,50);
  set(LA,50);
  set(RA,90);
  give_pwm(10);
  delay(5);
  reset();
  set(LS,50);
  set(RS,50);
  set(LN,0);
  set(RN,0);
  set(LF,0);
  set(RF,0);
  give_pwm(4);
  reset();
  set(LS,50);
  set(RS,50);
  give_pwm(8);
  reset();
  give_pwm(3);
  delay(1000);
}

void run_left() {
}

void run_right() {
}

void roll() {
}

void stand() {
}

void prone() {
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
  set(LS,65);
  set(RS,65);
  set(LT,0);
  set(RT,0);
  set(N1,120);
  set(N2,40);
  set(LN,70);
  set(RN,60);
  set(LF,70);
  set(RF,70);

  change_reset();
  while(!Serial){
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
  int todo=random(1);
}
void do_happy() {
  Serial.println("doing happy");
  int todo=random(1);
}
void do_relaxed() {
  Serial.println("doing relaxed");
  int todo=random(1);
}
void do_scared() {
  Serial.println("doing scared");
  int todo=random(1);
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

void loop() {
    run_forward();
}