void Timer3_handler(void) {
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    referenceAngle[xyIdx][1] = referenceAngle[xyIdx][0];
  }
  referenceAngle[0][0] = getMotorXreference(step);
  referenceAngle[1][0] = getMotorYreference(step);

  step++;
  if (step == LengthColumn - 1){
    step =0;
  }
  for (int xyIdx = 0; xyIdx <= 1; xyIdx ++){
    angle[xyIdx][1] = angle[xyIdx][0];
  }
  angle[0][0] = angleSensorX.getRawRotation();
  angle[1][0] = angleSensorY.getRawRotation();

  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    error[xyIdx][1] = error[xyIdx][0];
    error[xyIdx][0] = referenceAngle[xyIdx][0] - angle[xyIdx][0];
  }

  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    motorPower[xyIdx][1] = motorPower[xyIdx][0];
  }
  calcMotorInput();
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    move(xyIdx, motorPower[xyIdx][0]);
  }

//  debugSerialOut(step);
  passedTime = micros();
}
