void getPDgainFromAnalogread(){
  int analogreadPinIdx[][3] = {{0, 0, 1}, {2, 2, 3}};
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      pidGainInt[xyIdx][pidIdx] = analogRead(analogreadPinIdx[xyIdx][pidIdx]);
      pidGainFloat[xyIdx][pidIdx] = pidGainInt[xyIdx][pidIdx]*0.001*0.4;
    }
  }
}
