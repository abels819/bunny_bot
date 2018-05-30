
int order[] = {9, 10, 11, 12, 8, 6, 16, 5, 4, 3, 2, 15, 7, 14};
int order_ori[] = {9, 10, 11, 12, 8, 6, 16, 5, 4, 3, 2, 15, 7, 14};
int pwms[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};
int pwms_ori[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500, 1500};
int posi[] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};
int posi_ori[] = {90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90, 90};

int dtime[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int mood = 1;
int situation_now = 0;

int prevtime = 0;


void print_pwm_list() {
  int i = 0;
  while (i < 14) {
    Serial.print(order[i]);
    Serial.print("  ,  ");
    i++;
  }
  Serial.println();
  Serial.println("pwms:");
  i = 0;
  while (i < 14) {
    Serial.print(pwms[i]);
    Serial.print("  ,  ");
    i++;
  }
  Serial.println();
  Serial.println("***********************end**********************");
}


int plus(float angle) {
  float pwm = angle / 180;
  pwm = pwm * 2000 + 500;
  return pwm;
}
int reverse(int angle) {
  return 2500 - plus(angle);
}

void sort() {
  //print_pwm_list();
  int temp;
  for (int i = 0; i < 13; i++)  {
    for (int j = 13; j > i; j--)  {
      if (pwms[j] < pwms[j - 1]) {
        temp = pwms[j];
        pwms[j] = pwms[j - 1];
        pwms[j - 1] = temp;
        temp = order[j];
        order[j] = order[j - 1];
        order[j - 1] = temp;
      }
    }
  }
}


void get_dtime() {
  int i = 0;
  while (i < 14) {
    if (i != 0) {
      dtime[i] = pwms[i] - pwms[i - 1];
    }
    else {
      dtime[i] = pwms[i] - prevtime;
    }
    i++;
  }
  i = 0;
}

int set(int tar, int val) {
  int i;
  for (i = 0; i < 14; i++) {
    if (order[i] == tar) {
      posi[i] = val;
      if ( tar == 3 || tar == 5 || tar == 6 || tar == 10 || tar == 12 || tar == 14 || tar == 15) {
        pwms[i] = reverse(posi[i]);
      }
      else {
        pwms[i] = plus(posi[i]);
      }
      break;
    }
  }
  sort();
  get_dtime();

}

int get_posi(int tar){
  for(int i=0;i<14;i++){
    if(order[i]==tar){
      return posi[i];  
    }  
  }
}


void pwm_once() {
  int i = 0;
  int j = 0;
  while (i < 14) {

    digitalWrite(order[i], HIGH);
    i++;
  }
  while (j < 14) {
    delayMicroseconds(dtime[j]);
    digitalWrite(order[j], LOW);
    j++;
    //Serial.println(delaytime);
  }
  delay(20);
}



void give_pwm(int looptimes) {
  //print_pwm_list();
  for (int i = 0; i < looptimes; i++) {
    pwm_once();
    if (mood == 1) {
      //situation_now = situation();
      //if (situation() != 0) {
      //  break;
      //}
    }
  }
}

void reset() {
  for (int i = 0; i < 14; i++) {
    posi[i] = posi_ori[i];
    pwms[i] = pwms_ori[i];
    order[i] = order_ori[i];
  }
  sort();
  get_dtime();
}

void change_reset() {
  for (int i = 0; i < 14; i++) {
    posi_ori[i] = posi[i];
    pwms_ori[i] = pwms[i] ;
    order_ori[i] = order[i] ;
  }
  
  sort();
  get_dtime();
}
