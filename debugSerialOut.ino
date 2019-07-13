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
      Serial.print(" . ");
    }
  }
  Serial.println();
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      Serial.print(pidGainFloat[xyIdx][pidIdx]);
      Serial.print(" . ");
    }
  }
  for (int xyIdx = 0; xyIdx <=1; xyIdx++){
    for (int timeIdx = 0; timeIdx <=1; timeIdx++){
      Serial.print(motorPower[xyIdx][timeIdx]);
    }
  }
  Serial.println();
}

