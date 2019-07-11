void getInput(){
  stringComplete = false;
  while (!stringComplete){
    while (Serial.available()){
      receiveData[receiveDataIdx] = (char)Serial.read();
      receiveDataIdx++;
      if (receiveData[receiveDataIdx-1] == '\n'){
        stringComplete = true;
        receiveData[receiveDataIdx-1] = '\0';
        receiveDataIdx = 0;
      } else if ( receiveDataIdx > 15 ){
        receiveDataIdx = 15;
      }
    }
  }
}
