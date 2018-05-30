

int legs_controll = 7;
int arms_controll = 5;
int spine_controll = 2;
int legs_return_signal = 4;
int arms_return_signal = 6;
int spine_return_signal = 3;
int sonic_trigger = 10;
int sonic_in = 11;
int current_mood;
int IR_timer_detected;
int IR_timer_undetected;
int scared_timer;
int lifted_timer;
int confirm_lifted_timer_top = 1; // value for brain to count if the time is long enough to judge that being lifted
int happy_limit_top = 10; //value for brain to count if the time is long enough to expire happy mode
int undetection_limit = 10; //value for brain to count if the time is long enough since first lose sign of human
int scared_timer_top = 10; //value for brain to count if the time is enough to expire scared mode
int human_IR_judge_true = 120; //value for human detector to decide if there is a human
int scaring_noise = 10000; //value for noise detector to decide if being scared    /tested & modified
void setup() {
  scared_timer = scared_timer_top + 1;
  IR_timer_detected = 0;
  IR_timer_undetected = undetection_limit + 1;
  lifted_timer = 0;
  pinMode(legs_controll, OUTPUT);
  pinMode(arms_controll, OUTPUT);
  pinMode(spine_controll, OUTPUT);
  pinMode(legs_return_signal, INPUT);
  pinMode(arms_return_signal, INPUT);
  pinMode(spine_return_signal, INPUT);
  pinMode(sonic_trigger, OUTPUT);
  pinMode(sonic_in, INPUT);
  randomSeed(analogRead(A0));
}


//neuron simulation send&receive protocal_________________________________________________________________________________________________________________

float check_distance() {
  int result[3];
  int mini = 18000;
  for (int i = 0; i < 3; i++) {
    digitalWrite(sonic_trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(sonic_trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(sonic_trigger, LOW);
    result[i] = pulseIn(sonic_in, HIGH) / 58;
  }
  for (int i = 0; i < 3; i++) {
    if (mini > result[i]) {
      mini = result[i];
    }
  }
  return mini;
}

void signal_operation(float pwm) {
  for (int i = 0; i < 3; i++) {

    digitalWrite(spine_controll, HIGH);
    digitalWrite(legs_controll, HIGH);
    digitalWrite(arms_controll, HIGH);
    delayMicroseconds(pwm * 100);
    digitalWrite(spine_controll, LOW);
    digitalWrite(legs_controll, LOW);
    digitalWrite(arms_controll, LOW);
    delay(1);
  }
  delay(20);
}



int check_human() {
  int left = analogRead(A0);
  int right = analogRead(A2);
  int result;
  if (left == 0 && right == 0) {
    result = 0;
  }
  else if (left > 300 && right == 0) {
    result = 1;
  }
  else if (left == 0 && right > 300) {
    result = 2;
  }
  else if (left > 300 && right > 300) {
    result = 3;
  }
  return result;
}



//foundation motion base_________________________________________________________________________________________________________________________________
void head_check_left() {
  signal_operation(20);
}
void head_check_right() {
  signal_operation(22);
}
void head_check_half_left() {
  signal_operation(28);
}
void head_check_half_right() {
  signal_operation(30);
}
void head_check_low() {
  signal_operation(24);
}
void head_check_high() {
  signal_operation(26);
}
void head_return() {
  signal_operation(41);
}








// motion base______________________________________________________________________________________________________________________________________________


//movements.................................................................................................................................................

void run_forward() {
  head_return();
  while (digitalRead(spine_return_signal) == 0 || digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  if (check_distance() > 20) {
    signal_operation(31);
  }
}
void run_left() {
  head_check_left();
  while (digitalRead(spine_return_signal) == 0 || digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  int distance = check_distance();
  if (distance > 20) {
    signal_operation(32);
  }
}
void run_right() {
  head_check_right();
  while (digitalRead(spine_return_signal) == 0 || digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  int distance = check_distance();
  if (distance > 20) {
    signal_operation(33);
  }
  head_return();
}
void half_right() {
  head_check_half_right();
  if (check_distance() > 50) {
    signal_operation(19);
  }
  head_return();
}






void quick_run_forward() {
  signal_operation(34);
}


void quick_run_left() {
  head_check_left();
  delay(40);
  while (digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  if (check_distance() > 30) {
    signal_operation(35);
  }
}

void quick_run_right() {
  head_check_right();
  delay(40);
  while (digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  if (check_distance() > 30) {
    signal_operation(36);
  }
}


void random_run() {
  //signal_operation(40);
  //delay(12 * 20);
  int looptimes = random(5) + 1;
  for (int i = 0; i < looptimes; i++) {
    int todo = random(3);
    if (todo == 0) {
      run_forward();
    }
    else if (todo == 1) {
      run_left();
    }
    else {
      run_right();
    }

    while (digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
    }
  }
  signal_operation(41);
}







//mothions without opsition changing................................................................................................................................


void stand_up() {
  signal_operation(37);
}
void prone() {
  signal_operation(38);
}
void face_rob_short() {
  signal_operation(39);
}
void push_human() {
  if (check_human() == 3) {
    signal_operation(1);
  }
  else {
    stand_up();
  }

}
void stretch() {
  signal_operation(17);
}





//mood base_________________________________________________________________________________________________________________________________________________

void random_head_check() {
  int todo = random(8);
  if (todo == 1) {
    head_check_left();
  }
  if (todo == 2) {
    head_check_half_left();
  }
  if (todo == 3) {
    head_check_right();
  }
  if (todo == 4) {
    head_check_half_right();
  }
  if (todo == 5) {
    head_check_high();
  }
  if (todo == 6) {
    head_check_low();
  }
  if (todo == 7) {
    head_return();
  }
  delay(800);
}


void do_happy() {
  int todo = random(14);

  if (todo == 1) {
    run_forward();
  }
  else if (todo == 2) {
    run_left();

  }
  else if (todo == 3) {
    run_right();
  }
  else if (todo == 4) {
    stand_up();
  }
  else if (todo == 5) {
    prone();
  }
  else if (todo == 6) {
    face_rob_short();
  }
  else if (todo == 7) {
    push_human();
  }
  else if (todo > 7 && todo < 11) {
    random_run();
  }
  else if (todo >= 11) {
    random_head_check();
  }
}


//___________________________________________________________________________________________________________________________________________________________________________

void do_scared() {
  random_run();
}
//_____________________________________________________________________________________________________________________________________________________________________________
void do_normal() {
  int todo = random(17);
  if (todo == 1) {
    run_forward();
  }
  else if (todo == 2) {
    run_left();
  }
  else if (todo == 3) {
    run_right();
  }
  else if (todo > 3 && todo < 7) {
    random_run();
  }
  else if (todo == 7) {
    face_rob_short();
  }
  else if (todo == 8) {
    stand_up();
  }
  else if (todo == 9) {
    prone();
  }
  else if (todo == 10) {
    stretch();
  }
  else if (todo >= 11) {
    random_head_check();
  }
}
//____________________________________________________________________________________________________________________________________________________________________________
void do_relaxed() {
  int todo = random(12);
  if (todo == 1) {
    run_forward();
  }
  else if (todo == 2) {
    run_left();
  }
  else if (todo == 3) {
    run_right();
  }
  else if (todo == 4) {
    stand_up();
  }
  else if (todo == 5) {
    prone();
  }
  else if (todo == 6) {
    face_rob_short();
  }
  else if (todo >= 7) {
    random_head_check();
  }
}

int scare_noise() {
  if (analogRead(A1) >= scaring_noise && analogRead(A3) >= scaring_noise) {
    return 1;
  }
  else {
    return 0;
  }
}
int human_exists() {
  if (analogRead(A0) == 0 && analogRead(A2) == 0) {
    return 0;
  }
  else {
    return 0; //customization
  }
}

//_____________________________________________________________________________________________________________________________________________________________________________
int judge_mood() {
  if (scare_noise() == 1 && human_exists() == 0) {
    scared_timer = 0;
    return 2;
  }
  else if (scared_timer < scared_timer_top) {
    scared_timer++;
    return 2  ;
  }
  else if (human_exists() == 1 && scared_timer >= scared_timer_top)  { //human detected
    IR_timer_undetected = 0;
    IR_timer_detected++;
    //human detected as a resume mode or been long
    if (IR_timer_detected != 0) {
      if (IR_timer_detected < happy_limit_top) { //human just showed
        return 1;
      }
      else {
        return 4;
      }

    }
    //human detected as a new showing
    else {
      return 1;
    }
  }
  else if (human_exists() == 0 && scared_timer >= scared_timer_top) { //human not detected
    //human undetected as long gone
    IR_timer_undetected++;
    if (IR_timer_undetected > undetection_limit) {
      IR_timer_detected = 0;
      return 3;
    }
    //human undetected as just gone
    else {
      if (IR_timer_detected < happy_limit_top && IR_timer_detected != 0) {
        return 1;
      }
      else if (IR_timer_detected >= happy_limit_top && IR_timer_detected != 0) {
        return 4;
      }
    }
  }
}


void do_mood() {
  int mood = judge_mood();
  current_mood = mood;
  if (mood == 1) {
    do_happy();
  }
  else if (mood == 2) {
    do_scared();
  }
  else if (mood == 3) {
    do_normal();
  }
  else if (mood == 4) {
    do_relaxed();
  }

}



void check_noise() {
  for (int i = 0; i < 50; i++) {

    int left = analogRead(A1);
    int right = analogRead(A3);
    if (left - right > 40) {
      head_check_left();
      while (digitalRead(spine_return_signal) == 1) {
      }
      break;
    }
    else if (right - left > 40) {
      head_check_right();
      while (digitalRead(spine_return_signal) == 1) {
      }
      break;
    }
  }

}



void loop() {
  randomSeed(analogRead(A1));
  if (current_mood != 2) {
    check_noise();
  }
  do_mood();
  delay(20);
  while (digitalRead(spine_return_signal) == 0 || digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
  head_return();
  while (digitalRead(spine_return_signal) == 0 || digitalRead(legs_return_signal) == 0 || digitalRead(arms_return_signal) == 0) {
  }
}
