int positions[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500};
int origin[] = {1500, 1500, 1500, 1500, 1500, 1500, 1500};
int pwmrcv = 13;
int occupied = 12;

int ry = 5;
int ll1 = 6;
int ll2 = 7;
int ll3 = 8;
int rl1 = 9;
int rl2 = 10;
int rl3 = 11;

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

    for (int i = 5; i < 12; i++) {
      single_pwm(i, positions[i - 5]);
    }
    delayMicroseconds(20000 - (7 * 2500));
  }
  Serial.println("given");
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmrcv, INPUT);
  pinMode(occupied, OUTPUT);
  pinMode(ry, OUTPUT);
  pinMode(ll1, OUTPUT);
  pinMode(ll2, OUTPUT);
  pinMode(ll3, OUTPUT);
  pinMode(rl1, OUTPUT);
  pinMode(rl2, OUTPUT);
  pinMode(rl3, OUTPUT);
  digitalWrite(occupied, HIGH);
  give_pwm(40);
}



void reset() {
  for (int i = 0; i < 7; i++) {
    positions[i] = origin[i];
  }
}

//..........................................................................motion base...........................................................................................................//

//root motion...................................................................

void body_return() {
  Serial.println("returning");
  reset();
  give_pwm(20);
}


//foundation motion base_________________________________________________________________________________________________________________________________

void head_return() {
  reset();
  give_pwm(10);
}



void head_check_left() {
}
void head_check_right() {
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
//movements.......................................................................................

void run_forward() {

  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[1] = 2500;
  positions[4] = 500;
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[1] = 2500;
  positions[4] = 500;
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  reset();
  give_pwm(10);
}
void run_left() {
  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[0] = 1800; //
  positions[1] = 1900; //
  positions[4] = 500;
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[0] = 1800; //
  positions[1] = 1900; //
  positions[4] = 500;
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  reset();
  give_pwm(10);
}
void run_right() {
  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[0] = 1200; //
  positions[1] = 2500;
  positions[4] = 1100; //
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[0] = 1200; //
  positions[1] = 2500;
  positions[4] = 1100; //
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  reset();
  give_pwm(10);
}
void random_run_initiate() {
  positions[1]=1900;
  positions[4]=1100;
  positions[2]=1100;
  positions[5]=1700;
  give_pwm(10);
}
void quick_forward() {
  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[1] = 2500;
  positions[4] = 500;
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[1] = 2500;
  positions[4] = 500;
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  random_run_initiate();
}
void quick_left() {
  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[0] = 1800; //
  positions[1] = 1900; //
  positions[4] = 500;
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[0] = 1800; //
  positions[1] = 1900; //
  positions[4] = 500;
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  random_run_initiate();
}
void quick_right() {
  positions[1] = 2500;
  positions[4] = 500;
  give_pwm(5);
  positions[0] = 1200; //
  positions[1] = 2500;
  positions[4] = 1100; //
  positions[2] = 500;
  positions[5] = 2500;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(13);
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[0] = 1200; //
  positions[1] = 2500;
  positions[4] = 1100; //
  positions[3] = 500;
  positions[6] = 2500;
  give_pwm(5);
  reset();
  positions[2] = 1800;
  positions[5] = 1200;
  positions[3] = 1900;
  positions[6] = 1100;
  give_pwm(15);
  random_run_initiate();
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


//mothions without positional changes.................................................................................................................


void stand_up() {
  delay(10);
  positions[1] = 1800;
  positions[4] = 1200;
  give_pwm(70);
  reset();
  give_pwm(10);
}
void prone() {
  positions[1] = 1200;
  give_pwm(10);
  positions[1] = 1700;
  positions[4] = 1700;
  give_pwm(20);
  positions[1] = 1300;
  give_pwm(390);
  positions[1] = 1700;
  positions[4] = 1700;
  give_pwm(10);
  reset();
  give_pwm(10);
}
void face_rob_short() {
  reset();
  positions[1] = 1800;
  positions[4] = 1200;
  give_pwm(340);
  reset();
  give_pwm(10);
}
void push_human() {
  positions[1] = 1800;
  positions[4] = 1200;
  give_pwm(70);
  reset();
  give_pwm(10);
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
    //run_right();
    //run_left();
    run_forward();
  }
  else if (315 < pwm && pwm < 325) {
    run_left();
    //run_right();
  }
  else if (325 < pwm && pwm < 335) {
    run_right();
    //run_left();
    //run_forward();
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
  else if (395 < pwm && pwm < 405){
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
  digitalWrite(occupied, HIGH);
}

void loop() {
  int pwmtime;
  int j = 0;
  //Serial.println((pulseIn(pwmrcv,HIGH)/100)*10);
  for(int i=0;i<3;i++){
      
  pwmtime=(pulseIn(pwmrcv,HIGH)/100)*10;
  if(pwmtime!=0){
    break;
    }  
  }
  Serial.println(pwmtime);
  judge_and_do(pwmtime);
}
