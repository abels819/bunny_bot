int pwmrcv = 13;
int occupied = 12;

int nx1 = 2;
int ny1 = 3;
int nx2 = 4;
int ny2 = 5;
int sx1 = 6;
int sy1 = 7;
int sx2 = 8;
int positions[7] = {1500, 1000, 2100, 1500, 1500, 1100, 1500};
int origin[7] = {1500, 1000, 2100, 1500, 1500, 1100, 1500};



void single_pwm(int pin, int width) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(width);
  digitalWrite(pin, LOW);
  delayMicroseconds(2500 - width);
}

void give_pwm(int looptimes) {
  if (looptimes == 0) {
    looptimes = 1;
  }
  for (int j = 0; j < looptimes; j++) {

    for (int i = 2; i < 9; i++) {
      single_pwm(i, positions[i - 2]);
    }
    delayMicroseconds(20000 - (7 * 2500));
  }
}



void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A0));
  Serial.begin(9600);
  pinMode(pwmrcv, INPUT);
  pinMode(occupied, OUTPUT);
  for (int i = 0; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  digitalWrite(occupied, HIGH);
  give_pwm(40);
}
void reset() {
  for (int i = 0; i < 8; i++) {
    positions[i] = origin[i];
  }
}

//..........................................................................motion base...........................................................................................................//

//root motion...................................................................

void body_return() {

}


//foundation motion base_________________________________________________________________________________________________________________________________

void head_return() {
  reset();
  give_pwm(5);
}




void head_check_left() {
  positions[0] = 500;
  give_pwm(10);
  reset();
}
void head_check_right() {
  positions[0] = 2500;
  give_pwm(10);
  reset();
}
void head_check_half_left() {
  positions[0] = 1000;
  give_pwm(10);
  reset();
}
void head_check_half_right() {
  positions[0] = 2000;
  give_pwm(10);
  reset();
}
void head_check_low() {
  positions[1] = 1300;
  positions[2] = 1300;
  give_pwm(10);
  reset();
}
void head_check_high() {
  positions[1] = 1800;
  positions[2] = 1600;
  give_pwm(10);
  reset();
}








// motion base______________________________________________________________________________________________________________________________________________
//movements......................................................................................................................
void run_forward() {
  head_check_low();
  give_pwm(5);
}
void run_left() {
  head_check_half_left();
  give_pwm(5);
}
void run_right() {
  head_check_half_right();
  give_pwm(5);
}
void random_run_initiate(){
  
}
void quick_forward() {
}
void quick_left() {
}
void quick_right() {
}
void half_left() {
}
void half_right() {
}
void run_scared_for() {
}
void run_scared_left() {
}
void run_scared_right() {
}

//mothions without positional changes..........................................................................................................................


void stand_up() {
  int todo = random(3);
  for (int i = 0; i < 2; i++) {
    if (todo == 0) {
      positions[1] = 1300;
      positions[2] = 1000;
      give_pwm(20);
    }
    if (todo == 1) {

      positions[0] = 1000;

      positions[1] = 1300;
      positions[2] = 1000;
      give_pwm(20);
    }
    if (todo == 2) {

      positions[0] = 2000;

      positions[1] = 1300;
      positions[2] = 1000;
      give_pwm(20);

    }

    todo = random(3);
  }

  reset();
}
void prone() {
  int todo = random(4);
  head_check_low();
  for (int i = 0; i < 6; i++) {
    if (todo == 1) {
      head_check_half_left();
    }
    if (todo == 2) {
      head_check_half_right();
    }
    if (todo == 3) {
      head_check_high();
    }
    if (todo == 4) {
      head_return();
    }
    if (todo == 5) {
      head_check_low();
    }
    delay(300);
    todo = random(6);
  }
}
void face_rob_short() {

  positions[0] = 1200;
  positions[1] = 1000;
  positions[2] = 1300;
  for (int i = 0; i < 85; i++) {
    int movement = random(25) - 12;
    positions[0] += movement;
    positions[1] += movement;
    positions[2] += movement;
    give_pwm(2);
  }
  positions[0] = 1800;
  positions[1] = 1000;
  positions[2] = 1300;
  for (int i = 0; i < 85; i++) {
    int movement = random(7) - 3;
    positions[0] += movement;
    positions[1] += movement;
    positions[2] += movement;
    give_pwm(2);
  }
  reset();
  give_pwm(10);
}
void push_human() {
}
void stretch() {
}
void lifted_1() {
}
void lifted_2() {
}
void lifted_3() {
}



//..........................................................................end motion base.......................................................................................................//

void judge_and_do(int pwm) {
  digitalWrite(occupied, LOW);
  if (305 < pwm && pwm < 315) {
    run_forward();
  }
  else if (315 < pwm && pwm < 325) {
    run_left();
  }
  else if (325 < pwm && pwm < 335) {
    run_right();
  } else if (335 < pwm && pwm < 345) {
    quick_forward();
  }
  else if (345 < pwm && pwm < 355) {
    quick_left();
  } else if (355 < pwm && pwm < 365) {
    quick_right();
  }
  else if (365 < pwm && pwm < 375) {
    stand_up();
  } else if (375 < pwm && pwm < 385) {
    prone();
  }
  else if (385 < pwm && pwm < 395) {
    face_rob_short();
  }
  else if(395<pwm && pwm<405){
    random_run_initiate();  
  }
  else if (95 < pwm && pwm < 105) {
    push_human();
  }
  else if (105 < pwm && pwm < 115) {
    run_scared_for();
  }
  else if (115 < pwm && pwm < 125) {
    run_scared_left();
  }
  else if (125 < pwm && pwm < 135) {
    run_scared_right();
  }
  else if (135 < pwm && pwm < 145) {
    lifted_1();
  }
  else if (145 < pwm && pwm < 155) {
    lifted_2();
  }
  else if (155 < pwm && pwm < 165) {
    lifted_3();
  }
  else if (175 < pwm && pwm < 185) {
    half_left();
  }
  else if (185 < pwm && pwm < 195) {
    half_right();
  }
  else if (195 < pwm && pwm < 205) {
    head_check_left();
  }
  else if (215 < pwm && pwm < 225) {
    head_check_right();
  }
  else if (275 < pwm && pwm < 285) {
    head_check_half_left();
  }
  else if (295 < pwm && pwm < 305) {
    head_check_half_right();
  }
  else if (235 < pwm && pwm < 245) {
    head_check_low();
  }
  else if (255 < pwm && pwm < 265) {
    head_check_high();
  }
  else if (405 < pwm && pwm < 415) {
    head_return();
  }
  body_return();
  digitalWrite(occupied, HIGH);
}



void loop() {
  int pwmtime;
  int j=0;
  pwmtime=(pulseIn(pwmrcv,HIGH)/100)*10;
    judge_and_do(pwmtime);
}
