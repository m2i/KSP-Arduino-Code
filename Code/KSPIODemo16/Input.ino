int input() {
  int returnValue = -1;
  now = millis();

  if (KSPBoardReceiveData()) {
    deadtimeOld = now;
    returnValue = id;
    switch (id) {
      case 0: // Handshake packet
        Handshake();
        break;
      case 1:
        Indicators();

        // -----------------------------------------------------------------------------------------
        if(TSN == 0)
        {TSN = VData.TotalStage;}
        
        if(count == 2 && VData.CurrentStage/TSN == 1 && count2 != 1){
        colorChange(strip.Color(0,50,0));
        count = count+1;}
        else if(count == 4 && VData.CurrentStage/TSN == 1 && count2 != 1){
        colorChange(strip.Color(0,0,0));
        count = 0;}
        else if(VData.CurrentStage/TSN == 1)
        count = count+1;
        else if(VData.CurrentStage/TSN !=1 && count < 20 && count2 != 1){
        colorChange(strip.Color(0,50,0));  
        count = count+1;}
        else if(VData.CurrentStage/TSN !=1 && count > 19 && count2 != 1)
        count2 = 1;

        if(count2 == 1 && count3 == 0){
        colorChange(strip.Color(0,40,0));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 1){
        colorChange(strip.Color(0,30,0));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 2){
        colorChange(strip.Color(0,20,0));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 3){
        colorChange(strip.Color(0,10,0));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 4){
        colorChange(strip.Color(0,1,0));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 5){
        colorChange(strip.Color(0,10,10));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 6){
        colorChange(strip.Color(0,20,20));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 7){
        colorChange(strip.Color(0,30,30));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 8){
        colorChange(strip.Color(0,40,40));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 9){
        colorChange(strip.Color(0,50,50));
        count3 = count3+1;}
        else if(count2 == 1 && count3 == 10){
        Stars();
        Stars();}
        
        
        displayFloat(lc,  0, (VData.CurrentStage/VData.TotalStage)*100);
        displayFloat(lc,  1, VData.CurrentStage/TSN);
        displayFloat(lc1, 0, VData.TotalStage);
        displayFloat(lc1, 1, VData.CurrentStage);
        displayFloat(lc2, 0, (VData.CurrentStage/TSN));
        displayFloat(lc2, 1, VData.CurrentStage);
        displayFloat(lc3, 0, TSN);
        displayFloat(lc3, 1, (VData.CurrentStage/TSN));
        // -----------------------------------------------------------------------------------------

        break;
    }

    // We got some data, turn the green led on
    digitalWrite(GLED, HIGH);
    Connected = true;
  } else { // if no message received for a while, go idle
    deadtime = now - deadtimeOld;
    if (deadtime > IDLETIMER) {
      deadtimeOld = now;
      Connected = false;
      LEDSAllOff();
    }
  }

  return returnValue;
}

byte ControlStatus(byte n) {
  return ((VData.ActionGroups >> n) & 1) == 1;
}

