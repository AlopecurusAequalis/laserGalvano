#include <AS5048A.h>
#include <DueTimer.h>
//#include <MsTimer2.h>
#include <stdio.h>
#define LengthColumn 242

//motor A connected between A01 and A02
//motor B connected between B01 and B02
AS5048A angleSensorX(4);
AS5048A angleSensorY(10);

unsigned long millis();
int STBY = 13; //standby

//Motor A
int PWMA = 3; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

float pgainXFloat = 0;
float igainXFloat = 0;
float dgainXFloat = 0;

float pgainYFloat = 0;
float igainYFloat = 0;
float dgainYFloat = 0;

// シリアルから読み取るときはInt型しかだめなので
int pgainXInt = 0;
int igainXInt = 0;
int dgainXInt = 0;

int pgainYInt = 0;
int igainYInt = 0;
int dgainYInt = 0;

long errorX;
long errorY;

long iErrorX;
long iErrorY;

long passedTime;

//word val1;
//word val2;
long nowAngX;
long nowAngY;
long referenceAngX = 0;
long referenceAngY = 0;
long passedAngX;
long passedAngY;
long motorPowerX = 0;
long motorPowerY = 0;
long passedmotorPowerX;
long passedmotorPowerY;

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
  Timer3.start(500); // 2.5msec
  //  MsTimer2::set(5, control);
  //  MsTimer2::start();
  Serial.begin(115200);
}



void Timer3_handler(void) {
  long passedRefAngX = referenceAngX;
  long passedRefAngY = referenceAngY;

  // referenceXAng = genStepSignal(step, 10000);
  // referenceYAng = genStepSignal(step, 10000);

  referenceAngX = getMotorXreference(step);
//  referenceAngY = getMotorYreference(step);
  step++;
  if (step == LengthColumn - 1){
    step =0;
  }
  //モーター回す
  passedAngX = nowAngX;
  passedAngY = nowAngY;
  nowAngX = angleSensorX.getRawRotation();
  nowAngY = angleSensorY.getRawRotation();

  pgainXFloat=pgainXInt*0.001;
  igainXFloat=igainXInt*0.001;
  dgainXFloat=dgainXInt*0.001;
  pgainYFloat=pgainYInt*0.001;
  igainYFloat=igainYInt*0.001;
  dgainYFloat=dgainYInt*0.001;

  passedmotorPowerX=motorPowerX;
  float motorPowerX = calcMotorInputX(passedRefAngX, referenceAngX, passedAngX, nowAngX, (passedTime - micros()));
    if (motorPowerX > 0){
      move(1, motorPowerX, 1);
    }
    else{
      move(1, abs(motorPowerX), 0);
    }

  passedmotorPowerY=motorPowerY;
  float motorPowerY = calcMotorInputY(passedRefAngY, referenceAngY, passedAngY, nowAngY, (passedTime - micros()));
    if (motorPowerY > 0){
      move(2, motorPowerY, 1);
    }
    else{
      move(2, abs(motorPowerY), 0);
    }
  //２個目のモータ
  if (step % 20 == 0){
//    Serial.print(nowAngX);
//    Serial.print(",");
//    Serial.println(referenceAngX);
//    Serial.println(step);
//    Serial.print(pgainXInt);
//    Serial.print(" , ");
//    Serial.print(pgainXFloat);
//    Serial.print(" , ");
    Serial.print("motorPower:"); 
    Serial.println(motorPowerX);
//    Serial.print(" . ");
//    Serial.print(referenceAngX);
//    Serial.print(" . ");
//    Serial.print("  sa:");
//    Serial.print(micros() - passedTime);
//    Serial.print("  passedTime:");
//    Serial.print(passedTime);
//    Serial.print("  micro:");
//    Serial.println(micros());
  }
  //  Serial.print(referenceAng);
  //  Serial.print(",");
  //  Serial.println(motorPower);
  //  Serial.print(",");
  //  Serial.println(nowAng1);
  //  Serial.print(",");
  //  Serial.print(referenceAng2);
  //  Serial.print(",");
  //  Serial.print(motorPower2);
  //  Serial.print(",");
  //  Serial.println(nowAng2);
  passedTime = micros();
}

void loop(){
  Serial.println("Please select gain (p,i,d)or(P,I,D) ");
  getInput();
  // 処理1
  if (receiveData[0] == 'p'){
    Serial.println("P gain = ");
    getInput();
    pgainXInt = atoi(receiveData);
    Serial.println(pgainXInt);
  }
  if (receiveData[0] == 'i'){
    Serial.println("I gain = ");
    getInput();
    errorX = 0; // 積分器のリセット
    igainXInt = atoi(receiveData);
    Serial.println(igainXInt);
  }
  if (receiveData[0] == 'd'){
    Serial.println("D gain = ");
    getInput();
    dgainXInt = atoi(receiveData);
    Serial.println(dgainXInt);
  }
  // 処理2
  if (receiveData[0] == 'P'){
    Serial.println("P gain2 = ");
    getInput();
    pgainYInt = atoi(receiveData);
    Serial.println(pgainYInt);
  }
  if (receiveData[0] == 'I'){
    Serial.println("I gain2 = ");
    getInput();
    errorY = 0; // 積分器のリセット
    igainYInt = atoi(receiveData);
    Serial.println(igainYInt);
  }
  if (receiveData[0] == 'D'){
    Serial.println("D gain2 = ");
    getInput();
    dgainYInt = atoi(receiveData);
    Serial.println(dgainYInt);
  }
}
