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
//        displayFloat(lc,  0, VData.Alt);
//        displayFloat(lc,  1, VData.Alt);
//        displayFloat(lc1, 0, VData.Alt);
//        displayFloat(lc1, 1, VData.Alt);
//        displayFloat(lc2, 0, VData.Alt);
//        displayFloat(lc2, 1, VData.Alt);
//        displayFloat(lc3, 0, VData.Alt);
//        displayFloat(lc3, 1, VData.Alt);
        displayfloat1(VData.Alt);
        displayfloat2(VData.Alt);
        displayfloat3(VData.Alt);
        displayfloat4(VData.Alt);
        displayfloat5(VData.Alt);
        displayfloat6(VData.Alt);
        displayfloat7(VData.Alt);
        displayfloat8(VData.Alt);
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

