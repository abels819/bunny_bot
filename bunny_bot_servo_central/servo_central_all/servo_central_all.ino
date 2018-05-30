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



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmrcv, INPUT);
  pinMode(occupied, OUTPUT);
  for (int i = 0; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  digitalWrite(occupied, HIGH);
}
void single_pwm(int pin,int width){
  digitalWrite(pin,HIGH);
  delayMicroseconds(width);
  digitalWrite(pin,LOW);
  delayMicroseconds(2500-width);
}

void give_pwm(int looptimes){
  if(looptimes==0){
    looptimes=1;  
  }
  for (int j = 0; j < looptimes; j++) {

    for (int i = 2; i < 9; i++) {
      single_pwm(i, positions[i - 2]);
    }
    delayMicroseconds(20000 - (7 * 2500));
  }
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
  give_pwm(50);
}




void head_check_left() {
  positions[0] = 500;
  give_pwm(50);
  reset();
}
void head_check_right() {
  positions[0] = 2500;
  give_pwm(50);
  reset();
}
void head_check_half_left() {
  
}
void head_check_half_right() {
}
void head_check_low() {
}
void head_check_high() {
}








// motion base______________________________________________________________________________________________________________________________________________
//movements......................................................................................................................
void run_forward() {
}
void run_left() {
}
void run_right() {
}
void walk_forward() {
}
void walk_left() {
}
void walk_right() {
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
}
void prone() {
}
void face_rob_short() {
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
  if (0 < pwm && pwm < 15) {
    run_forward();
  }
  else if (15 < pwm && pwm < 25) {
    run_left();
  }
  else if (25 < pwm && pwm < 35) {
    run_right();
  } else if (35 < pwm && pwm < 45) {
    walk_forward();
  }
  else if (45 < pwm && pwm < 55) {
    walk_left();
  } else if (55 < pwm && pwm < 65) {
    walk_right();
  }
  else if (65 < pwm && pwm < 75) {
    stand_up();
  } else if (75 < pwm && pwm < 85) {
    prone();
  }
  else if (85 < pwm && pwm < 95) {
    face_rob_short();
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
  else if (265 < pwm && pwm < 275) {
    head_return();
  }
  body_return();
  digitalWrite(occupied, HIGH);
}



void loop() {
  //int pwmtime=pulseIn(pwmrcv,HIGH);
  //if(pwmtime!=0){
  //  judge_and_do(pwmtime);
  //}
  head_check_left();
  head_return();
  head_check_right();
  head_return();
}
