float calcMotorInputX(long passedRefValue, long nowRefValue, long passedAng, long nowAng, float stepTime){
  if (abs(errorX) > 160000){
    errorX = 160000*errorX/abs(errorX);
  }
  float input;
  long error_pre;
  errorX = nowRefValue - nowAng;
  error_pre = passedRefValue - passedAng;
  iErrorX = iErrorX + errorX;
  input = pgainXFloat*errorX + dgainXFloat*(errorX-error_pre)/stepTime + igainXFloat*(iErrorX);
  return input;
}
float calcMotorInputY(long passedRefValue, long nowRefValue, long passedAng, long nowAng, float stepTime){
  if (abs(errorY) > 160000){
    errorY = 160000*errorY/abs(errorY);
  }
  float input;
  long error_pre;
  errorY = nowRefValue - nowAng;
  error_pre = passedRefValue - passedAng;
  iErrorY = iErrorY + errorY;
  input = pgainYFloat*errorY + dgainYFloat*(errorY-error_pre)/stepTime + igainYFloat*(iErrorY);
  return input;
}
