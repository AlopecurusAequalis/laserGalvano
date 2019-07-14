void debugSerialOut(int step){
  if (step % 20 == 0){
//    Serial.print(pgainXFloat);
//    Serial.print("  motorPower:");
//    Serial.print(motorPowerX);

//    Serial.print(" referenceAngX:");
//    Serial.print(referenceAngX);

//    Serial.print("  Sa:");
//    Serial.print(micros() - passedTime);

//    Serial.print("  passedTime:");
//    Serial.print(passedTime);

//    Serial.print("  micro:");
//    Serial.print(micros());
  Serial.println();
  }
}
void debugSerialPrint(){
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      Serial.print(pidGainInt[xyIdx][pidIdx]);
      Serial.print(" , ");
    }
  }
  Serial.println();
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      Serial.print(pidGainFloat[xyIdx][pidIdx]);
      Serial.print(" , ");
    }
  }
  Serial.println();
  for (int xyIdx = 0; xyIdx <=1; xyIdx++){
      Serial.print(motorPower[xyIdx][0]);
      Serial.print(" , ");
    }
  Serial.println();
  Serial.print(pidGainInt[0][0]);
  Serial.print(" , ");
  const int pidGainIntMax[][3] = {{300, 0, 100}, {300, 0, 100}};
  Serial.println(pidGainIntMax[0][0]);
}
