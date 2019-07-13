void getPDgainFromAnalogread(){
  // {{xPgainPin, yPgainPin}, {xDgainPin, yDgainPin}};
  int analogreadPinIdx[][2] = {{0, 2},{1, 3}};
  for (int xyIdx = 0; xyIdx <= 1; xyIdx++){
    for (int pidIdx = 0; pidIdx <= 2; pidIdx++){
      pidGainInt[xyIdx][pidIdx] = analogRead(analogreadPinIdx[xyIdx][pidIdx]);
    }
  }
}
