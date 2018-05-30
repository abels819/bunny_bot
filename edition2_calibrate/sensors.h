

float left_noise() {  //checked
  return analogRead(A4);
}

float right_IR() {
  return analogRead(A5);
}

float right_noise() {  //checked
  return analogRead(A6);
}

float left_IR() {  //checked
  return analogRead(A7);
}


int situation() {
  float l_noise = left_noise();
  float r_noise = right_noise();
  float l_IR = left_IR();
  float r_IR = right_IR();
  if ((l_noise > 300 || r_noise > 300) && l_IR < 30  && r_IR < 30) {
    return 9;
  }
  else {
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
}
