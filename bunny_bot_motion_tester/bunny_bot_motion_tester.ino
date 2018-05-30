
int sonic_trig = 8;
int spine_controll = 2;
int spine_return = 3;
int legs_controll = 7;
int arms_return = 6;
int arms_controll = 5;
int legs_return = 4;

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  pinMode(legs_controll, OUTPUT);
  pinMode(arms_controll, OUTPUT);
  pinMode(spine_controll, OUTPUT);
  pinMode(spine_return, INPUT);
  pinMode(arms_return, INPUT);
  pinMode(legs_return, INPUT);
}


float check_distance() {
  int result[3];
  int mini = 18000;
  for (int i = 0; i < 3; i++) {
    digitalWrite(10, LOW);
    delayMicroseconds(2);
    digitalWrite(10, HIGH);
    delayMicroseconds(10);
    digitalWrite(10, LOW);
    result[i] = pulseIn(11, HIGH) / 58;
  }
  for (int i = 0; i < 3; i++) {
    if (mini > result[i]) {
      mini = result[i];
    }
  }
  return mini;
}


void signal_operation(float pwm) {
  for (int i = 0; i < 5; i++) {

    digitalWrite(spine_controll, HIGH);
    digitalWrite(legs_controll, HIGH);
    digitalWrite(arms_controll, HIGH);
    delayMicroseconds((pwm * 1000) - 12);
    digitalWrite(spine_controll, LOW);
    digitalWrite(legs_controll, LOW);
    digitalWrite(arms_controll, LOW);
    delay(10);
    Serial.println(pwm);
  }
  delayMicroseconds((1 - pwm) * 1000);
}






//foundation motion base_________________________________________________________________________________________________________________________________
void head_check_left() {
  signal_operation(0.2);
  Serial.println("check left");
}
void head_check_right() {
  signal_operation(0.22);
  Serial.println("check right");
}
void head_check_half_left() {
  signal_operation(0.28);
  Serial.println("check half left");
}
void head_check_half_right() {
  signal_operation(0.30);
  Serial.println("check half right");
}
void head_check_low() {
  signal_operation(0.24);
  Serial.println("check low");
}
void head_check_high() {
  signal_operation(0.26);
  Serial.println("check high");
}
void head_return() {
  signal_operation(0.27);
  Serial.println("return");
}








// motion base______________________________________________________________________________________________________________________________________________


//movements.................................................................................................................................................

void run_forward() {
  signal_operation(0.31);
  Serial.println("running forward");
}
void run_left() {
  signal_operation(0.32);
  Serial.println("running left");
}
void run_right() {
  signal_operation(0.33);
  Serial.println("running right");
}
void walk_forward() {
  signal_operation(0.34);
  Serial.println("walking forward");
}
void walk_left() {
  signal_operation(0.35);
  Serial.println("walking left");
}
void walk_right() {
  signal_operation(0.36);
  Serial.println("walking right");

}
void half_left() {
  signal_operation(0.18);
  Serial.println("half left");
}
void half_right() {
  signal_operation(0.19);
  Serial.println("half right");
}
void run_scared_for() {
  signal_operation(0.11);
  Serial.println("scared forward");

}
void run_scared_left() {
  signal_operation(0.12);
  Serial.println("scared left");

}
void run_scared_right() {
  signal_operation(0.13);
  Serial.println("scared right");

}

//mothions without opsition changing................................................................................................................................


void stand_up() {
  Serial.println("standing up");
  signal_operation(0.37);
}
void prone() {
  Serial.println("going prone");
  signal_operation(0.38);
}
void face_rob_short() {
  Serial.println("face robbing");
  signal_operation(0.39);
}
void push_human() {
  Serial.println("pushy pushy:");
  signal_operation(0.1);
}
void stretch() {
  signal_operation(0.17);
  Serial.println("stretching");
}

void lifted_1() {
  signal_operation(0.14);
  Serial.println("lifted1");
}
void lifted_2() {
  signal_operation(0.15);
  Serial.println("lifted2");
}
void lifted_3() {
  signal_operation(0.16);
  Serial.println("lifted3");
}



void execute(int todo) {
  if (todo == 1) {
    head_check_left();
  }
  if (todo == 2) {
    head_check_right();
  }
  if (todo == 3) {
    head_check_half_left();
  }
  if (todo == 4) {
    head_check_half_right();
  }
  if (todo == 5) {
    head_check_low();
  }
  if (todo == 6) {
    head_check_high();
  }
  if (todo == 7) {
    head_return();
  }
  if (todo == 8) {
    run_forward();
  }
  if (todo == 9) {
    run_left();
  }
  if (todo == 10) {
    run_right();
  }
  if (todo == 11) {
    walk_forward();
  }
  if (todo == 12) {
    walk_left();
  }
  if (todo == 13) {
    walk_right();
  }
  if (todo == 14) {
    half_left();
  }
  if (todo == 15) {
    half_right();
  }
  if (todo == 16) {
    run_scared_for();
  }
  if (todo == 17) {
    run_scared_left();
  }
  if (todo == 18) {
    run_scared_right();
  }
  if (todo == 19) {
    stand_up();
  }
  if (todo == 20) {
    prone();
  }
  if (todo == 21) {
    face_rob_short();
  }
  if (todo == 22) {
    push_human();
  }
  if (todo == 23) {
    stretch();
  }
  if (todo == 24) {
    lifted_1();
  }
  if (todo == 25) {
    lifted_2();
  }
  if (todo == 26) {
    lifted_3();
  }
}

void check_noise(){
  int left=analogRead(A1);
  int right=analogRead(A3);
  if(left-right>30){
    execute(1); 
  }  
  else if(right-left>30){
    execute(2);  
  }
}

int check_human(){
  int left=analogRead(A0);
  int right=analogRead(A2);
  int result;
  if(left==0&&right==0){
        result=0;
  }  
  else if(left>300&&right==0){
        result=1;  
  }
  else if(left==0&&right>300){
        result=2;  
  }
  else if(left>300&&right>300){
        result=3;  
  }
return result;
}




void loop() {
  int todo;
  randomSeed(analogRead(A5));
  //Serial.print("distance:");
  //Serial.println(check_distance());
  if (check_distance() <= 10) {
    int todo = random(2);
    if (todo==1) {
    todo = 22;
    }
  }
  else {
    todo = random(15);
    if (todo > 10) {
      todo += 8;
    }
    //todo = 22;

  }
  //Serial.println(todo);
  execute(todo);
  delay(20);
  while (digitalRead(spine_return) == 0 || digitalRead(legs_return) == 0 || digitalRead(arms_return) == 0) {
  }
 // Serial.println("returned");
  delay(30);

}

