int positions[7]={1500,1000,2100,1500,1500,1100,1500};

void setup() {
  // put your setup code here, to run once:
  for (int i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}
void single_pwm(int pin,int width){
  digitalWrite(pin,HIGH);
  delayMicroseconds(width);
  digitalWrite(pin,LOW);
  delayMicroseconds(2500-width);
}

void give_pwm(){
  for(int i=2;i<9;i++){
    single_pwm(i,positions[i-2]);
  }  
  delayMicroseconds(20000-(7*2500));
}


void loop() {
  give_pwm();
}
