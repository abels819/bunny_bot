
byte bytes[2];
unsigned char re_buf[2];
int counter = 0;

float check_distance_single() {

  Serial.write(0XA0);
  delay(10);
  while (Serial.available()) {
    bytes[counter] = Serial.read();
    re_buf[counter] = bytes[counter];
    counter++;
  }
  counter = 0;
  uint16_t distance = re_buf[0] << 8 | re_buf[1];
  Serial.println(distance);
  return distance;
}

float check_distance(){
  float distance;
  for(int i=0;i<3;i++){
      distance=check_distance_single();
      delay(20);
  }  

  return distance;
}


float left_noise() {  //checked
  return analogRead(A6);
}

float right_IR() {
  return analogRead(A7);
}

float right_noise() {  //checked
  return analogRead(A5);
}

float left_IR() {  //checked
  return analogRead(A4);
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
    if (l_noise - r_noise > 50) {
      return 8;
    }
    else if (r_noise - l_noise > 50) {
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
