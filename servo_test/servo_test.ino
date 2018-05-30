void setup() {
  // put your setup code here, to run once:
    for(int i=2;i<12;i++){
        pinMode(i,OUTPUT);  
    }
}
void loop() {
  // put your main code here, to run repeatedly:
    for(int i=5;i<12;i++){
        digitalWrite(i,HIGH);
        delayMicroseconds(1500);
        digitalWrite(i,LOW);
        delayMicroseconds(2500-1500);  
    }
    delay(2.5);

}
