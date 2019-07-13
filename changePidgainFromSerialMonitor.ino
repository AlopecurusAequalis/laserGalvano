// void changePidgainFromSerialMonitor(){
//   Serial.println("Please select gain (p,i,d)or(P,I,D) ");
//   getInput();
//   if (receiveData[0] == 'S'){
//     Timer3.stop();
//      move(1, 0, 1);
//      move(2, 0, 1);
//     Serial.println("loop停止しました");
//   }
//   if (receiveData[0] == 's'){
//     Timer3.start(250);
//     Serial.println("loop開始しました");
//   }
//   // 処理1
//   if (receiveData[0] == 'p'){
//     Serial.println("P gain = ");
//     getInput();
//     pgainXInt = atoi(receiveData);
//     Serial.println(pgainXInt);
//   }
//   if (receiveData[0] == 'i'){
//     Serial.println("I gain = ");
//     getInput();
//     errorX = 0; // 積分器のリセット
//     igainXInt = atoi(receiveData);
//     Serial.println(igainXInt);
//   }
//   if (receiveData[0] == 'd'){
//     Serial.println("D gain = ");
//     getInput();
//     dgainXInt = atoi(receiveData);
//     Serial.println(dgainXInt);
//   }
//   // 処理2
//   if (receiveData[0] == 'P'){
//     Serial.println("P gain2 = ");
//     getInput();
//     pgainYInt = atoi(receiveData);
//     Serial.println(pgainYInt);
//   }
//   if (receiveData[0] == 'I'){
//     Serial.println("I gain2 = ");
//     getInput();
//     errorY = 0; // 積分器のリセット
//     igainYInt = atoi(receiveData);
//     Serial.println(igainYInt);
//   }
//   if (receiveData[0] == 'D'){
//     Serial.println("D gain2 = ");
//     getInput();
//     dgainYInt = atoi(receiveData);
//     Serial.println(dgainYInt);
//   }
//   for (xyIdx = 0; xyIdx <= 1; xyIdx++){
//     for (pidIdx = 0; pidIdx <=2; pidIdx++){
//       pidGainFloat[xyIdx][pidIdx] = (float) pgainXInt[xyIdx][pidIdx]*0.001;
//     }
//   }
// }
