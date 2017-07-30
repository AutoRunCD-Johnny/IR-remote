unsigned char tau,time0,time1,i,j,len,duration=10;
short list[4]={0,1,0,1};


void carrier(){ //in 1 kHz
  //tau=500/1-5;//minus 5 is offset
  //time0=micros();
  digitalWrite(5,HIGH);
  //time1=micros();
  delayMicroseconds(495);
  digitalWrite(5,LOW);
  delayMicroseconds(495);
}

void head(){
  for(i=0;i<9;i++)
    carrier();
  digitalWrite(5,LOW);
  delayMicroseconds(4500);
}

void transmit(short list[]){
  len=sizeof(list);
  for(i=0;i<len;i++){
    if(list[i]==0){
      for(j=0;j<10;j++)//duration=10
        carrier();  
      digitalWrite(5,LOW);
      delay(10);
    }
    else if(list[i]==1){
     for(j=0;j<10;j++)
        carrier();  
     digitalWrite(5,LOW);
     delay(10);    
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  head();
  //transmit(list);
  digitalWrite(5,LOW);
  delay(2000);
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
