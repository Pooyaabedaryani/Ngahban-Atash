int Atesh = 0;
bool Biz = false;
int i = 0;
bool R1,R2,R3;
bool L1,L2,L3;
bool SE1;
bool yek;
void setup() {
pinMode(1,OUTPUT);

pinMode(9,OUTPUT);
pinMode(10,OUTPUT);


pinMode(13,OUTPUT);
pinMode(0,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);

pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(5,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
pinMode(8,INPUT);

  analogWrite(9,100);
  analogWrite(10,100);
delay(100);

}

void loop() {
  Atesh = analogRead(A2);
  while(Atesh > 200){
    STOP();
    Biz = true;
    Atesh = analogRead(A2);
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
  analogWrite(9,90);
  analogWrite(10,90);
  R1 = digitalRead(8);
  L2 = digitalRead(2);
  L1 = digitalRead(4);
  L3 = digitalRead(3);
  SE1 = digitalRead(5);
  R2 = digitalRead(6);
  R3 = digitalRead(7);


 
GAHATYABI();


}
void GAHATYABI(){
    if(SE1 == false){
    if(L1 == true && L2 == true && R3 == true && R2 == true ){
    GOLO();
    }
    if(L1 == false && L2 == false && R3 == false && R2 == false ){
    STOP();
    }
    
  }
  if(SE1 == true){
    if(L1 == false || L2 == false || L3 == false && R1 == true && R2 == true){
      CHAP();
    }
    if(R3 == false || R2 == false || R3 == false && L3 == true && L2 == true){
      RAST();
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
  analogWrite(9,110);
  analogWrite(10,110);
  digitalWrite(0,HIGH);
  digitalWrite(12,LOW);

  digitalWrite(13,LOW);
  digitalWrite(11,HIGH);
  delay(1);
  
}
void CHAP(){
    analogWrite(9,110);
  analogWrite(10,110);
  digitalWrite(0,LOW);
  digitalWrite(12,HIGH);

  digitalWrite(13,HIGH);
  digitalWrite(11,LOW);
delay(1);
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
  delay(10);  
}
