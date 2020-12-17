#define BIT1 13
#define BIT2 12
#define BIT4 11
#define BIT8 10
#define BITHIGH HIGH
#define BITLOW LOW

#define DISP1 5
#define DISP2 4
#define DISPON LOW
#define DISPOFF HIGH

void setup(){
  pinMode(BIT1, OUTPUT);
  pinMode(BIT2, OUTPUT);
  pinMode(BIT4, OUTPUT);
  pinMode(BIT8, OUTPUT);
  pinMode(DISP1, OUTPUT);
  pinMode(DISP2, OUTPUT);
  digitalWrite(BIT1, BITLOW);
  digitalWrite(BIT2, BITLOW);
  digitalWrite(BIT4, BITLOW);
  digitalWrite(BIT8, BITLOW);
  digitalWrite(DISP1, DISPOFF);
  digitalWrite(DISP2, DISPOFF);
}

void showNum( int x ){
  if( (x & 1) == 1 ){
  	digitalWrite(BIT1, BITHIGH);
  }else{
    digitalWrite(BIT1, BITLOW);
  }
  if( (x & 2) == 2 ){
  	digitalWrite(BIT2, BITHIGH);
  }else{
    digitalWrite(BIT2, BITLOW);
  }
  if( (x & 4) == 4 ){
  	digitalWrite(BIT4, BITHIGH);
  }else{
    digitalWrite(BIT4, BITLOW);
  }
  if( (x & 8) == 8 ){
  	digitalWrite(BIT8, BITHIGH);
  }else{
    digitalWrite(BIT8, BITLOW);
  }
}
#define HOLDTIME 15
void loop(){
  showNum(4);
  digitalWrite(DISP1, DISPON);
  digitalWrite(DISP2, DISPOFF);
  delay(HOLDTIME);
  showNum(2);
  digitalWrite(DISP1, DISPOFF);
  digitalWrite(DISP2, DISPON);
  delay(HOLDTIME);
}

