
int positions[] = {1500, 1500, 1500, 1500, 1500, 1500};
int origin[] = {1500, 1500, 1500, 1500, 1500, 1500};
int pwmrcv = 13;
int occupied = 12;


int la1 = 6;
int la2 = 7;
int la3 = 8;
int ra1 = 9;
int ra2 = 10;
int ra3 = 11;


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

    for (int i = 6; i < 12; i++) {
      single_pwm(i, positions[i - 6]);
    }
    delayMicroseconds(20000 - (6 * 2500));
  }
  Serial.println("given");
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pwmrcv, INPUT);
  pinMode(occupied, OUTPUT);
  pinMode(la1, OUTPUT);
  pinMode(la2, OUTPUT);
  pinMode(la3, OUTPUT);
  pinMode(ra1, OUTPUT);
  pinMode(ra2, OUTPUT);
  pinMode(ra3, OUTPUT);
  digitalWrite(occupied, HIGH);
  give_pwm(40);
}


void reset() {
  for (int i = 0; i < 6; i++) {
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
  give_pwm(5);
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
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1850;
  positions[5] = 1150;
  give_pwm(35);
  reset();
  give_pwm(7);
}
void run_left() {
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1750;
  positions[5] = 1250;
  give_pwm(35);
  reset();
  give_pwm(7);
}
void run_right() {
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1750;
  positions[5] = 1250;
  give_pwm(35);
  reset();
  give_pwm(7);
}
void random_run_initiate(){
  reset();
  give_pwm(5);
  
}
void quick_forward(){
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1850;
  positions[5] = 1150;
  give_pwm(35);
  random_run_initiate();
}
void quick_left() {
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1750;
  positions[5] = 1250;
  give_pwm(35);
  random_run_initiate();
}
void quick_right() {
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(6);
  positions[0] = 950;
  positions[1] = 2050;
  positions[3] = 2050;
  positions[4] = 950;
  give_pwm(9);
  reset();
  positions[2] = 1750;
  positions[5] = 1250;
  give_pwm(35);
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
  delay(15);
  positions[0] = 2000;
  positions[1] = 1000;
  positions[3] = 1000;
  positions[4] = 2000;
  give_pwm(70);
  reset();
  give_pwm(5);
}
void prone() {
  give_pwm(2);
  positions[0] = 1900;
  positions[1] = 1100;
  positions[3] = 1900;
  positions[4] = 1100;
  positions[2] = 2200;
  give_pwm(10);
  positions[0] = 800;
  positions[1] = 2200;
  positions[3] = 2200;
  positions[4] = 800;
  positions[2] = 1700;
  positions[5] = 1300;
  give_pwm(20);
  delay(1300 * 6);
  delay(40);
  positions[0] = 1900;
  positions[1] = 1100;
  positions[3] = 1900;
  positions[4] = 1100;
  positions[2] = 2200;
  give_pwm(10);
  reset();
  give_pwm(5);
}
void left_rob() {
  for (int j = 0; j < 2; j++) {
    positions[0] = 800;
    positions[1] = 2200;
    positions[2] = 2000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[0] += 30;
      positions[1] -= 30;
      positions[2] -= 40;
      give_pwm(2);
    }
  }
  delay(800);
}
void right_rob() {
  for (int j = 0; j < 2; j++) {
    positions[3] = 2200;
    positions[4] = 800;
    positions[5] = 1000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[3] -= 30;
      positions[4] += 30;
      positions[5] += 40;
      give_pwm(2);
    }
  }
  delay(800);
}
void left_rob_tri() {
  for (int j = 0; j < 2; j++) {
    positions[0] = 800;
    positions[1] = 2200;
    positions[2] = 2000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[0] += 30;
      positions[1] -= 30;
      positions[2] -= 40;
      give_pwm(2);
    }
  }
  delay(200);
}
void right_rob_tri() {

  for (int j = 0; j < 2; j++) {
    positions[3] = 2200;
    positions[4] = 800;
    positions[5] = 1000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[3] -= 30;
      positions[4] += 30;
      positions[5] += 40;
      give_pwm(2);
    }
  }
  delay(200);
}
void right_push_up() {
  positions[3] = 2200;
  positions[4] = 800;
  positions[5] = 800;
  give_pwm(10);
  for (int i = 0; i < 10; i++) {
    positions[3] -= 30;
    positions[4] += 30;
    positions[5] += 40;
    give_pwm(2);
  }
}
void lick_left() {
  for (int j = 0; j < 2; j++) {
    positions[0] = 1100;
    positions[1] = 1900;
    positions[2] = 2000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[0] -= 10;
      positions[1] += 10;
      positions[2] -= 20;
      give_pwm(2);
    }
  }
  delay(200);
}
void left_push_up() {

  positions[0] = 800;
  positions[1] = 2200;
  positions[2] = 2200;
  give_pwm(10);
  for (int i = 0; i < 10; i++) {
    positions[0] += 30;
    positions[1] -= 30;
    positions[2] -= 40;
    give_pwm(2);
  }
}

void lick_right() {
  for (int j = 0; j < 2; j++) {
    positions[3] = 1900;
    positions[4] = 1100;
    positions[5] = 1000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[3] += 10;
      positions[4] -= 10;
      positions[5] += 20;
      give_pwm(2);
    }
  }
  delay(200);
}
void both_rob() {
  for (int j = 0; j < 2; j++) {

    positions[0] = 800;
    positions[1] = 2200;
    positions[2] = 2000;
    positions[3] = 2200;
    positions[4] = 800;
    positions[5] = 1000;
    give_pwm(10);
    for (int i = 0; i < 10; i++) {
      positions[3] -= 30;
      positions[4] += 30;
      positions[5] += 40;
      positions[0] += 30;
      positions[1] -= 30;
      positions[2] -= 40;
      give_pwm(2);
    }
  }
  delay(200);
}
void decide_left() {
  int todo;
  for (int i = 0; i < 2; i++) {
    todo = random(3);
    if (todo == 0) {
      left_rob();
    }
    if (todo == 1) {
      left_rob_tri();
    }
    if (todo == 2) {
      lick_left();
    }
    if (todo == 3) {
      both_rob();
    }
  }
}
void decide_right() {
  int todo;
  for (int i = 0; i < 2; i++) {
    todo = random(4);
    if (todo == 0) {
      right_rob();
    }
    if (todo == 1) {
      right_rob_tri();
    }
    if (todo == 2) {
      lick_right();
    }
    if (todo == 3) {
      both_rob();
    }
  }
}
void left() {
  int order = random(4);
  if (order == 0) {
    left_push_up();
    decide_left();
  }
  else {
    decide_left();
    left_push_up();
  }
  positions[0] = 1300;
  positions[1] = 1700;
}
void right() {

  int order = random(2);
  if (order == 0) {
    right_push_up();
    decide_right();
  }
  else {
    decide_right();
    right_push_up();
  }
}
void face_rob_short() {
  left();
  right();
  reset();
  give_pwm(5);
}
void push_1() {
  positions[0] = 1900;
  positions[1] = 1100;
  positions[3] = 1100;
  positions[4] = 1900;
  positions[2] = 2500;
  positions[5] = 500;
  give_pwm(10);
  reset();

  positions[0] = 600;
  positions[1] = 2400;
  positions[3] = 2400;
  positions[4] = 600;
  give_pwm(10);
  positions[0] = 1100;
  positions[1] = 1900;
  positions[3] = 1900;
  positions[4] = 1100;
  give_pwm(10);
}
void push_2() {
  positions[0] = 1900;
  positions[1] = 1100;
  positions[3] = 1100;
  positions[4] = 1900;
  positions[5] = 500;
  give_pwm(10);
  reset();
  positions[3] = 2400;
  positions[4] = 600;
  give_pwm(10);
  positions[0] = 1100;
  positions[1] = 1900;
  positions[3] = 1900;
  positions[4] = 1100;
  give_pwm(10);

}
void push_3() {

  positions[0] = 1900;
  positions[1] = 1100;
  positions[3] = 1100;
  positions[4] = 1900;
  positions[2] = 2500;
  give_pwm(10);
  reset();
  positions[0] = 600;
  positions[1] = 2400;
  give_pwm(10);
  positions[0] = 1100;
  positions[1] = 1900;
  positions[3] = 1900;
  positions[4] = 1100;
  give_pwm(10);
}
void push_4() {
  reset();
  give_pwm(30);
}
void push_human() {

  int todo = random(5);
  for (int i = 0; i < 2; i++) {
    while (todo == 0) {
      todo = random(5);
    }
    if (todo == 1) {
      push_1();
    }
    if (todo == 2) {
      push_2();
    }
    if (todo == 3) {
      push_3();
    }
    if (todo == 4) {
      push_4();
    }
    todo =random(5);
  }
  reset();
  give_pwm(5);
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
  Serial.println(pwm);
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
  digitalWrite(occupied, HIGH);
}


void loop() {
  int pwmtime;
  int j=0;
  for(int i=0;i<3;i++){
      
  pwmtime=(pulseIn(pwmrcv,HIGH)/100)*10;
  Serial.println(pwmtime);
  if(pwmtime!=0){
    break;
    }  
  }
  //
    judge_and_do(pwmtime);
}
