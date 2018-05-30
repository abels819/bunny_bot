
unsigned char bytes[2];
int counter = 0;


float check_distance() {
  Serial.write(0XA0);
  delay(10);
  while (Serial.available()) {
    bytes[counter] = Serial.read();
    counter++;
  }
  counter = 0;
  return (bytes[0] << 8)&bytes[1];
}

float left_noise() {
  return analogRead(A4);
}

float right_noise() {
  return analogRead(A5);
}

float left_IR() {
  return analogRead(A6);
}

float right_IR() {
  return analogRead(A7);
}


