//NIME
//yihan
//november 2017
//arduino 1.8.3 on a macbook



#define encoder0PinA  14  //rotary encoder 1 c pin
#define encoder0PinB  15      //rotary encoder 1 d pin

#define encoder0PinA2  16 //rotary encoder 2 c pin
#define encoder0PinB2  17 //rotary encoder 2 d pin

#define encoder0PinA3  18 //c
#define encoder0PinB3  19 //d

#define encoder0PinA4  24  //c the bord is order
#define encoder0PinB4  23 //d

//#define encoder0PinA5  13 //c
//#define encoder0PinB5  12 //d
////
//#define encoder0PinA6  11 //c
//#define encoder0PinB6  10 //d

//#define encoder0PinA7  9 //c
//#define encoder0PinB7  6 //d
//
//#define encoder0PinA8  5 //c
//#define encoder0PinB8  21 //d

//set up the range of serial wirte

int max = 100;
int min = 0;

//variables for storing current and previous position
//int isEncoderTurning = 0;

int val = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
//int val5 = 0;
//int val6 = 0;
//int val7 = 0;
//int val8 = 0;

////
//boolean serial = false;
//boolean blow = false;

//
volatile unsigned int encoder0Pos = 0;
volatile unsigned int encoder0Pos2 = 0;
volatile unsigned int encoder0Pos3 = 0;
volatile unsigned int encoder0Pos4 = 0;
//volatile unsigned int encoder0Pos5 = 0;
//volatile unsigned int encoder0Pos6 = 0;
//volatile unsigned int encoder0Pos7 = 0;
//volatile unsigned int encoder0Pos8 = 0;
  
  
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

//  
//  pinMode(encoder0PinA5, INPUT); 
//  digitalWrite(encoder0PinA5, HIGH);       
//  pinMode(encoder0PinB5, INPUT); 
//  digitalWrite(encoder0PinB5, HIGH);


//  pinMode(encoder0PinA6, INPUT); 
//  digitalWrite(encoder0PinA6, HIGH);       
//  pinMode(encoder0PinB6, INPUT); 
//  digitalWrite(encoder0PinB6, HIGH);   

//  pinMode(encoder0PinA7, INPUT); 
//  digitalWrite(encoder0PinA7, HIGH);       
//  pinMode(encoder0PinB7, INPUT); 
//  digitalWrite(encoder0PinB7, HIGH); 

//  
//  pinMode(encoder0PinA8, INPUT); 
//  digitalWrite(encoder0PinA8, HIGH);       
//  pinMode(encoder0PinB8, INPUT); 
//  digitalWrite(encoder0PinB8, HIGH);
  
  attachInterrupt(digitalPinToInterrupt(14), doEncoder, CHANGE);  // encoder pin on interrupt 0 - pin 2

  attachInterrupt(digitalPinToInterrupt(16), doEncoder2, CHANGE);  // encoder pin on interrupt 0 - pin 2

  attachInterrupt(digitalPinToInterrupt(18), doEncoder3, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
  attachInterrupt(digitalPinToInterrupt(24), doEncoder4, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
 // attachInterrupt(digitalPinToInterrupt(12), doEncoder5, CHANGE);  // encoder pin on interrupt 0 - pin 2
////  attachInterrupt(digitalPinToInterrupt(0), doEncoder5, CHANGE);  // encoder pin on interrupt 0 - pin 2

////  attachInterrupt(digitalPinToInterrupt(18), doEncoder3, CHANGE);  // encoder pin on interrupt 0 - pin 2
 // attachInterrupt(digitalPinToInterrupt(10), doEncoder6, CHANGE);  // encoder pin on interrupt 0 - pin 2
//  
//// attachInterrupt(digitalPinToInterrupt(24), doEncoder4, CHANGE);  // encoder pin on interrupt 0 - pin 2
//  attachInterrupt(digitalPinToInterrupt(6), doEncoder7, CHANGE);  // encoder pin on interrupt 0 - pin 2
//  
//  attachInterrupt(digitalPinToInterrupt(21), doEncoder8, CHANGE);  // encoder pin on interrupt 0 - pin 2
//////  attachInterrupt(digitalPinToInterrupt(0), doEncoder5, CHANGE);  // encoder pin on interrupt 0 - pin 2
  
  Serial.begin (115200);
  //Serial.println("0,0");

}   

void loop(){
 
  //doEncoder();
 // Serial.println(encoder0Pos);
 // Serial.print("1 = ");
    Serial.print(encoder0Pos);
    Serial.print(" ");
    Serial.print(encoder0Pos2);
//
    Serial.print(" ");
    Serial.print(encoder0Pos3);
    Serial.print(" ");
    Serial.print(encoder0Pos4);
    Serial.print(" ");
 //   Serial.print(encoder0Pos5);
//    Serial.print(" ");
//    Serial.print(encoder0Pos6);
//    Serial.print(" ");
//    Serial.print(encoder0Pos7);
//    Serial.print(" ");
//    Serial.print(encoder0Pos8);
//    
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

//void doEncoder5(){
//    if (digitalRead(encoder0PinA5) == digitalRead(encoder0PinB5)) {
//    if(encoder0Pos5 > min){
//      encoder0Pos5--;
//    }else{
//      encoder0Pos5 = min;
//    }
//  } else {
//    if(encoder0Pos5 < max){
//      encoder0Pos5++;
//    }else{
//      encoder0Pos5 = max;
//    }
//  }
//  
//}

//void doEncoder6() {
//
//  if (digitalRead(encoder0PinA6) == digitalRead(encoder0PinB6)) {
//    if(encoder0Pos6 > min){
//      encoder0Pos6--;
//    }else{
//      encoder0Pos6 = min;
//    }
//  } else {
//    if(encoder0Pos6 < max){
//      encoder0Pos6++;
//    }else{
//      encoder0Pos6 = max;
//    }
//  }
//
// }
//
//void doEncoder7(){
//    if (digitalRead(encoder0PinA7) == digitalRead(encoder0PinB7)) {
//    if(encoder0Pos7 > min){
//      encoder0Pos7--;
//    }else{
//      encoder0Pos7 = min;
//    }
//  } else {
//    if(encoder0Pos7 < max){
//      encoder0Pos7++;
//    }else{
//      encoder0Pos7 = max;
//    }
//  }
//  
//}
//
//void doEncoder8(){
//    if (digitalRead(encoder0PinA8) == digitalRead(encoder0PinB8)) {
//    if(encoder0Pos8 > min){
//      encoder0Pos8--;
//    }else{
//      encoder0Pos8 = min;
//    }
//  } else {
//    if(encoder0Pos8 < max){
//      encoder0Pos8++;
//    }else{
//      encoder0Pos8 = max;
//    }
//  }
//  
//}


