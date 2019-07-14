void getPDgainFromAnalogread(){
  Timer3.stop();
  move(1, 0);
  move(2, 0);
  int analogreadPinIdx[][3] = {{0, 0, 1}, {2, 2, 3}};
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      pidGainInt[xyIdx][pidIdx] = analogRead(analogreadPinIdx[xyIdx][pidIdx]);
      analogread2Range();
      pidGainFloat[xyIdx][pidIdx] = pidGainInt[xyIdx][pidIdx]*0.001;
    }
  }
  // debugSerialPrint();
  Timer3.start(500);
}
void analogread2Range(){
  const int pidGainIntMax[][3] = {{300, 0, 100}, {300, 0, 100}};
  float temp;
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      temp = (float) pidGainInt[xyIdx][pidIdx]*pidGainIntMax[xyIdx][pidIdx]/1024.0;
      pidGainInt[xyIdx][pidIdx] = (int) temp;
    }
  }
}
