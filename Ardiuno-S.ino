// BA
int Atash = 0;
bool Biz = false;
void Atesh();
int i; // :)
bool yek;
// BB
bool R1,R2,R3,L1,L2,L3,SV;
void GahatYabi();
//BC
bool Start = false;
bool SRAST,SCHAP;
void setup() {
pinMode(1,OUTPUT); //Bizzer
pinMode(9,OUTPUT); //PWM DRIVER CONTROL A
pinMode(10,OUTPUT); //PWM DRIVER CONTROL B
pinMode(13,OUTPUT); //L298 CONTROL 1
pinMode(0,OUTPUT);  //L298 CONTROL 2
pinMode(11,OUTPUT); //L298 CONTROL 3
pinMode(12,OUTPUT); //L298 CONTROL 4

pinMode(2,INPUT); // Sensor
pinMode(3,INPUT); // Sensor
pinMode(4,INPUT); // Sensor
pinMode(5,INPUT); // Sensor
pinMode(6,INPUT); // Sensor
pinMode(7,INPUT); // Sensor
pinMode(8,INPUT); // Sensor

digitalWrite(1,true);
delay(50);
digitalWrite(1,false);
}

void loop() {
    Atesh();
    GahatYabi();
  
}
void GahatYabi(){
  Mach();
  analogWrite(9,110);
  analogWrite(10,110);
  if(SV == false){
    GOLO();
    if(R1 == false && L1 == false){
      STOP();
    }
  }
  while(SV == true){
    Mach();
    if(R3 == false){
      analogWrite(9,80);
      analogWrite(10,80);
      RAST();
    }
     if(R2 == false){
      analogWrite(9,100);
      analogWrite(10,100);
      RAST();
    }
     if(R1 == false)SRAST = true;
     while(SRAST == true){
      analogWrite(9,130);
      analogWrite(10,130);
      RAST();
      if(L1 == true ){
        SRAST = false;
        delay(1);
      }
     }
    if(L3 == false){
      analogWrite(9,80);
      analogWrite(10,80);
      CHAP();
    }
     if(L2 == false){
      analogWrite(9,100);
      analogWrite(10,100);
      CHAP();
    }
     if(L1 == false)SCHAP = true;
     while(SCHAP == true){
      analogWrite(9,130);
      analogWrite(10,130);
      CHAP();
      if(R1 == true ){
        SCHAP = false;
        delay(1);
      }
     }
  }
}
void Mach(){
  R1 = digitalRead(8);
  L2 = digitalRead(2);
  L1 = digitalRead(3);
  L3 = digitalRead(4);
  SV = digitalRead(5);
  R2 = digitalRead(6);
  R3 = digitalRead(7);
}
void Atesh(){
  Atash = analogRead(A2);
    while(Atash > 200){
    STOP();
    Biz = true;
    Atash = analogRead(A2);
  }
  if (Biz == true){
    for ( ; i < 165 ; i++){
      digitalWrite(1,HIGH);
      delay(1);
    }
    if( i > 163){
       digitalWrite(1,LOW);
       i = 0;
       Biz = false;
       yek = false;
    }
  }
  
}
void GOLO(){
  digitalWrite(0,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
}
void RAST(){
  digitalWrite(0,HIGH);
  digitalWrite(12,LOW);

  digitalWrite(13,LOW);
  digitalWrite(11,HIGH);
}
void CHAP(){
  digitalWrite(0,LOW);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
}
void STOP(){
  digitalWrite(0,LOW);
  digitalWrite(12,LOW);

  digitalWrite(13,LOW);
  digitalWrite(11,LOW);  
}
void BACK(){
  digitalWrite(0,LOW);
  digitalWrite(12,HIGH);

  digitalWrite(13,LOW);
  digitalWrite(11,HIGH);
}
