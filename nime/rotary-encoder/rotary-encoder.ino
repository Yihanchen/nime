//NIME
//yihan
//november 2017
//arduino 1.8.3 on a macbook

//1461 port blue tooth up one
//14111 port basic dowm one

#define encoder0PinA  14  //rotary encoder 1 c pin
#define encoder0PinB  15      //rotary encoder 1 d pin

#define encoder0PinA2  16 //rotary encoder 2 c pin
#define encoder0PinB2  17 //rotary encoder 2 d pin

#define encoder0PinA3  18 //c
#define encoder0PinB3  19 //d

#define encoder0PinA4  24  //c the bord is order
#define encoder0PinB4  23 //d



int max = 200;
int min = 0;



int val = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;



////
//boolean serial = false;
//boolean blow = false;

//
volatile unsigned int encoder0Pos = 0;
volatile unsigned int encoder0Pos2 = 0;
volatile unsigned int encoder0Pos3 = 0;
volatile unsigned int encoder0Pos4 = 0;

  
  
void setup() { 

  //encoder
  pinMode(encoder0PinA, INPUT); 
  digitalWrite(encoder0PinA, HIGH);       
  pinMode(encoder0PinB, INPUT); 
  digitalWrite(encoder0PinB, HIGH);   

  pinMode(encoder0PinA2, INPUT); 
  digitalWrite(encoder0PinA2, HIGH);       
  pinMode(encoder0PinB2, INPUT); 
  digitalWrite(encoder0PinB2, HIGH);       

  pinMode(encoder0PinA3, INPUT); 
  digitalWrite(encoder0PinA3, HIGH);       
  pinMode(encoder0PinB3, INPUT); 
  digitalWrite(encoder0PinB3, HIGH);   

  pinMode(encoder0PinA4, INPUT); 
  digitalWrite(encoder0PinA4, HIGH);       
  pinMode(encoder0PinB4, INPUT); 
  digitalWrite(encoder0PinB4, HIGH); 



  
  attachInterrupt(digitalPinToInterrupt(15), doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  attachInterrupt(digitalPinToInterrupt(17), doEncoder2, CHANGE);  // encoder pin on interrupt 0 - pin 2

  attachInterrupt(digitalPinToInterrupt(19), doEncoder3, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
  attachInterrupt(digitalPinToInterrupt(23), doEncoder4, CHANGE);  // encoder pin on interrupt 0 - pin 2
  



  
  Serial.begin (115200);
  //Serial.println("0,0");

}   

void loop(){
 
  //doEncoder();
    Serial.print(encoder0Pos);
    Serial.print(" ");
    Serial.print(encoder0Pos2);
    Serial.print(" ");
    Serial.print(encoder0Pos3);
    Serial.print(" ");
    Serial.print(encoder0Pos4);
    Serial.print(" ");

    
    Serial.println();
    delay(5);

   
}



void doEncoder() {

  if (digitalRead(encoder0PinA) == digitalRead(encoder0PinB)) {

   // isEncoderTurning = 0;
    
    if(encoder0Pos > min){
      encoder0Pos--;
    }else{
      encoder0Pos = min;
    }
  } else {

    //isEncoderTurning = 1;
    
    if(encoder0Pos < max){
      encoder0Pos++;
    }else{
      encoder0Pos = max;
    }
  }

   
  }

void doEncoder2(){
    if (digitalRead(encoder0PinA2) == digitalRead(encoder0PinB2)) {
    if(encoder0Pos2 > min){
      encoder0Pos2--;
    }else{
      encoder0Pos2 = min;
    }
  } else {
    if(encoder0Pos2 < max){
      encoder0Pos2++;
    }else{
      encoder0Pos2 = max;
    }
  }
  
}


void doEncoder3() {

  if (digitalRead(encoder0PinA3) == digitalRead(encoder0PinB3)) {
    if(encoder0Pos3 > min){
      encoder0Pos3--;
    }else{
      encoder0Pos3 = min;
    }
  } else {
    if(encoder0Pos3 < max){
      encoder0Pos3++;
    }else{
      encoder0Pos3 = max;
    }
  }

   
  }

void doEncoder4(){
    if (digitalRead(encoder0PinA4) == digitalRead(encoder0PinB4)) {
    if(encoder0Pos4 > min){
      encoder0Pos4--;
    }else{
      encoder0Pos4 = min;
    }
  } else {
    if(encoder0Pos4 < max){
      encoder0Pos4++;
    }else{
      encoder0Pos4 = max;
    }
  }
  
}




