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
