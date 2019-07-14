#include <AS5048A.h>
#include <DueTimer.h>
#include <stdio.h>
#define LengthColumn 242

//motor A connected between A01 and A02
//motor B connected between B01 and B02
AS5048A angleSensorX(4);
AS5048A angleSensorY(10);

unsigned long millis();
long passedTime;
int STBY = 13; //standby

//Motor A
int PWMA = 3; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

float pidGainFloat[2][3];
int pidGainInt[2][3]; // シリアルから読み取るときはInt型しかだめなので
// {{xNow, xPrevious}, {yNow, yPrevious}}
// value[0][0] -> xNow, value[0][1] -> xPrevious, value[1][0] -> yNow,
long error[2][2];
long angle[2][2];
long referenceAngle[2][2];
long motorPower[2][2];

//割り込み用
int step = 0;
boolean stringComplete = false;
char receiveData[16];
char receiveDataIdx = 0;

void setup(){
  angleSensorX.init();
  angleSensorY.init();

  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // タイマ割り込みの設定
  Timer3.attachInterrupt(Timer3_handler);
  Timer3.start(500);
  //  MsTimer2::set(5, control);
  //  MsTimer2::start();
  Serial.begin(115200);

  attachInterrupt(50, getPDgainFromAnalogread, FALLING);
}

void loop(){
  getInput();
  if (receiveData[0] == 'S'){
    Timer3.stop();
     move(1, 0);
     move(2, 0);
     Serial.print("k");
     debugSerialPrint();
     Timer3.start(500);
  }
}
