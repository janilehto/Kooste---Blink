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

void loop(){
  digitalWrite(DISP2, DISPON);
}
