void move(int motor, int speed, int direction){
  //Move specific motor at speed and direction
  //motor: 0 for B 1 for A
  //speed: 0 is off, and 255 is full speed
  //direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

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

//float calcMotorInputX(long passedRefValue, long nowRefValue, long passedAng, long nowAng, float stepTime){
//  if (abs(errorX) > 160000){
//    errorX = 160000*errorX/abs(error);
//  }
//  float input;
//  long error_pre;
//  errorX = nowRefValue - nowAng;
//  error_pre = passedRefValue - passedAng;
//  iErrorX = iErrorX + errorX;
//  input = pgainXFloat*error + dgainXFloat*(error-error_pre)/stepTime + igainXFloat*(iErrorX);
//  return input;
//}
//
//float calcMotorInputY(long passedRefValue, long nowRefValue, long passedAng, long nowAng, float stepTime){
//  if (abs(errorY) > 160000){
//    errorY = 160000*errorY/abs(error);
//  }
//  float input;
//  long error_pre;
//  errorY = nowRefValue - nowAng;
//  error_pre = passedRefValue - passedAng;
//  iErrorY = iErrorY + errorY;
//  input = pgainYFloat*error + dgainYFloat*(error-error_pre)/stepTime + igainYFloat*(iErrorY);
//  return input;
//}
