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
  Serial.begin(9600);
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
unsigned long vertailuHetki = HOLDTIME;
bool timeToSwitchDisplays(){
  unsigned long nykyHetki = millis();
  if( nykyHetki >= vertailuHetki ){
    vertailuHetki += HOLDTIME;
    return true;
  }
  return false;
}
bool showOnes = true;
void showValue( int val ){
  if( timeToSwitchDisplays() ){
    if( showOnes == true ){
      showNum( val % 10 );
      digitalWrite(DISP1, DISPOFF);
      digitalWrite(DISP2, DISPON);
      showOnes = false;
    }else{
      val /= 10;
      showNum(val % 10);
      digitalWrite(DISP1, DISPON);
      digitalWrite(DISP2, DISPOFF);
      showOnes = true;
    }
  }
}

void loop(){
  showValue( 24 );
}














