#include "movement.h"
#include "sensors.h"

#define L_EYE=A4;
#define R_EYE=A5;
#define L_EAR=A6;
#define R_EAR=A7;

int H = 9 , N1 = 10, N2 = 11, SPINE = 12, LS = 8, LA = 6, LT = 16, LN = 5, LF = 4, RS = 3, RA = 2, RT = 15, RN = 7, RF = 14;

//reverse:2  3   7  14  15

int situation() {
  float l_noise = left_noise();
  float r_noise = right_noise();
  float l_IR = left_IR();
  float r_IR = right_IR();
  if (l_noise < 300 && r_noise < 300) {
    if (l_noise - r_noise > 40) {
      return 8;
    }
    else if (r_noise - l_noise > 40) {
      return 7;
    }
    else {
      if (l_IR > 200 && r_IR < 30) {
        return 6;
      }
      else if (r_IR > 200 && l_IR < 30) {
        return 5;
      }
      else if (l_IR > 200 && r_IR > 200) {
        return 4;
      }
      else {
        return 0;
      }
    }
  }
  else {
    return 9;
  }
}



void give_pwm(int looptimes) {
  for (int i = 0; i < 9; i++) {
    pwms[i] = plus(posi[i]);
  }
  for (int i = 9; i < 14; i++) {
    pwms[i] = reverse(posi[i]);
  }
  sort();
  int delaytime = 20000 - pwms[13];
  for (int i = 0; i < looptimes; i++) {
    pwm_once();
    delayMicroseconds(delaytime);
    if (mood == 1) {
      situation_now = situation();
      if (situation() != 0) {
        break;
      }
    }
  }
}

void setup() {
  for (int i = 2; i < 16; i++) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
}
