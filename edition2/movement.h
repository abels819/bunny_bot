int mood=1;
int situation_now=0;
int order[]={9,10,11,12,8,6,16,5,4,3,2,15,7,14};
int order_ori[]={9,10,11,12,8,6,16,5,4,3,2,15,7,14};
int pwms[]={1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500};
int pwms_ori[]={1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500,1500};
int posi[]={90,90,90,90,90,90,90,90,90,90,90,90,90,90};
int posi_ori[]={90,90,90,90,90,90,90,90,90,90,90,90,90,90};



int set(int tar,int val){
    tar=tar-2;
    posi[tar]=val;
}

int plus(int angle){
    return 500+(angle/180)*2000;  
}
int reverse(int angle){
    return 2500-plus(angle);  
}

void sort(){
  int temp;
    for(int i=0;i<13;i++)  {
      for(int j=13-i;j>0;j--)  {
          if(pwms[j]<pwms[j-1]){
              temp=pwms[j];
              pwms[j]=pwms[j-1];
              pwms[j-1]=temp;
              temp=order[j];
              order[j]=order[j-1];
              order[j-1]=temp;
            }
        }
    }
}

void pwm_once(){
    int i=0;
    while(pwms[i]){
      digitalWrite(order[i],HIGH);
      i++;  
    }
    i=0;
    while(pwms[i]){
      int delaytime;
      if(i==0){
        delaytime=pwms[i]-pwms[i-1];
      }
      else{
        delaytime=pwms[i];  
      }
      delayMicroseconds(delaytime);
      digitalWrite(order[i],LOW);
      i++;
    }
}

void give_pwm(int looptimes) {
  for (int i = 0; i < 14; i++) {
    if(order[i]==2||order[i]==3||order[i]==7||order[i]==14||order[i]==15){
      pwms[i]=reverse(posi[i]);  
    }
    else{
      pwms[i]=plus[i];  
    }
  }
  sort();
  int delaytime = 20000 - pwms[13];
  for (int i = 0; i < looptimes; i++) {
    pwm_once();
    delayMicroseconds(delaytime);
    if (mood == 1) {
    //  situation_now = situation();
    //  if (situation() != 0) {
    //    break;
    //  }
    }
  }
}



void reset(){
  for(int i=0;i<14;i++){
    posi[i]=posi_ori[i];
    pwms[i]=pwms_ori[i];
    order[i]=order_ori[i];  
  }
}

