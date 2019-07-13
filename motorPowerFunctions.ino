void move(int motor, int speed){
  //Move specific motor at speed and direction
  //motor: 0 for B 1 for A
  //speed: 0 is off, and 255 is full speed

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(speed > 0){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  speed = abs(speed);

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){
  digitalWrite(STBY, LOW);
}

void calcMotorInput(){
  float pInput = 0;
  float dInput = 0;
  for (int xyIdx = 0; xyIdx <=1; xyIdx++){
    pInput = pidGainFloat[xyIdx][0]*error[xyIdx][0];
    dInput = pidGainFloat[xyIdx][2]*(error[xyIdx][0] - error[xyIdx][1]);
    motorPower[xyIdx][0] = pInput + dInput;
  }
}
