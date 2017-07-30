unsigned char tau,time0,time1,i,j,len,duration;
short list1[35]={1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,1,0,0,1,0};
short list2[33]={0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1};
short k;

void carrier(){ //in 38 kHz
  //tau=500/freq-5;//minus 5 is offset
  //time0=micros();
  digitalWrite(5,HIGH);
  //time1=micros();
  delayMicroseconds(8);//tau=500/38-5
  digitalWrite(5,LOW);
  delayMicroseconds(8);
}

void head(){//head signal 9ms HI 4.5ms LOW
  for(k=0;k<342;k++)//342 un-usable
    carrier();
  digitalWrite(5,LOW);
  delayMicroseconds(4500);
}

void conn(){//0.5625ms HI,20ms LOW
  for(i=0;i<21;i++)
    carrier();
  digitalWrite(5,LOW);
  delay(20);
}

void transmit1(short list[]){
  len=sizeof(list1)/sizeof(list1[0]);//Serial.println(len);
  for(i=0;i<len;i++){
    if(list[i]==0){// signal 0 duty cycle 50%, duration 1.125ms
      for(j=0;j<21;j++)//  0.5625*38=21
        carrier();  
      digitalWrite(5,LOW);
      delayMicroseconds(563);//1.125/2=0.5625ms
    }
    else if(list1[i]==1){
     for(j=0;j<21;j++)
        carrier();  
     digitalWrite(5,LOW);
     delayMicroseconds(1687);//0.5625*3=1.6875ms    
    }
  }
}

void transmit2(short list[]){
 len=sizeof(list2)/sizeof(list2[0]);//Serial.println(len);
  for(i=0;i<len;i++){
    if(list2[i]==0){// signal 0 duty cycle 50%, duration 1.125ms
      for(j=0;j<21;j++)//  0.5625*38=21
        carrier();  
      digitalWrite(5,LOW);
      delayMicroseconds(563);//1.125/2=0.5625ms
    }
    else if(list2[i]==1){
     for(j=0;j<21;j++)
        carrier();  
     digitalWrite(5,LOW);
     delayMicroseconds(1687);//0.5625*3=1.6875ms    
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  //Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  head();
  transmit1(list1);
  conn();
  transmit2(list2);
  digitalWrite(5,LOW);
  delay(1000);
  /*len=sizeof(list);
  for(i=0;i<len;i++){
    if(list[i]==0){
      for(j=0;j<duration;j++)
        {digitalWrite(5,HIGH);
  //time1=micros();
  delayMicroseconds(500-5);
  digitalWrite(5,LOW);
  delayMicroseconds(500-5);}  
      digitalWrite(5,LOW);
      delay(10);
    }
    else if(list[i]==1){
     for(j=0;j<duration;j++)
        {digitalWrite(5,HIGH);
  //time1=micros();
  delayMicroseconds(500-5);
  digitalWrite(5,LOW);
  delayMicroseconds(500);}  
     digitalWrite(5,LOW);
     delay(30);    
    }  }*/
}
