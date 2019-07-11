int genStepSignal(int step, int squarePeriod){
  if (step > squarePeriod/2){
    return 8000;
  }else{
    return 9000;
  }
}
