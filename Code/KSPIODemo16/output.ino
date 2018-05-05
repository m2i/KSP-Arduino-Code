void output() {
  now = millis();
  controlTime = now - controlTimeOld;
  if (controlTime > CONTROLREFRESH) {
    controlTimeOld = now;
    controls();
  }
}

void controls() {
  if (Connected) {
    /*
        if (digitalRead(SASPIN)) { //--------- This is how you do main controls
          MainControls(SAS, HIGH);
          setSASMode(SMSAS); //setting SAS mode
          //setNavballMode(NAVBallSURFACE); //setting navball mode
        }
        else {
          //setNavballMode(NAVBallTARGET);
          MainControls(SAS, LOW);
        }

        if (digitalRead(RCSPIN))
          MainControls(RCS, HIGH);
        else
          MainControls(RCS, LOW);

        if (digitalRead(CG1PIN))   //--------- This is how you do control groups
          ControlGroups(1, HIGH);
        else
          ControlGroups(1, LOW);


           if (getSASMode() == SMPrograde) { //--------- This is how you read SAS modes
             //Blink LED, do stuff, etc.
           }

           if (getNavballMode() == NAVBallTARGET) { //--------- This is how you read navball modes
             //Blink LED, do stuff, etc.
           }
    */

    //------------------------------------------------------------------------------------------------
    /*  if (digitalRead(41))        //Stage transition
        MainControls(STAGE, LOW);
      else
        MainControls(STAGE, HIGH);


      //This is an example of reading analog inputs to an axis, with deadband and limits
      CPacket.Throttle = constrain(map(analogRead(THROTTLEPIN), THROTTLEDB, 1024 - THROTTLEDB, 0, 1000), 0, 1000);
      //CPacket.Throttle = constrain(map(analogRead(A5), THROTTLEDB, 1024 - THROTTLEDB, 0, 1000), 0, 1000);

      //This is an example of reading analog inputs to an axis, with deadband and limits
      CPacket.Pitch = constrain(map(analogRead(A2),0,1024,-1000,1000),-1000, 1000);
      CPacket.Yaw = constrain(map(analogRead(A1),0,1024,-1000,1000),-1000, 1000);
    */
    //=================================================================================================
    if (digitalRead(22) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Roll Right CoPilot
      CPacket.Roll = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(22) & digitalRead(23) == 1 & digitalRead(47) == 1 & digitalRead(48) == 1)
      CPacket.Roll = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(23) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Roll Left CoPilot
      CPacket.Roll = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(24) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Pitch up CoPilot
      CPacket.Pitch = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(24) & digitalRead(25) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1)
      CPacket.Pitch = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(25) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Pitch Down CoPilot
      CPacket.Pitch = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(26) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Yaw Right CoPilot
      CPacket.Yaw = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(26) & digitalRead(27) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)
      CPacket.Yaw = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(27) == 0 & digitalRead(47) == 1 & digitalRead(48) == 1 & digitalRead(49) == 1 & digitalRead(50) == 1 & digitalRead(51) == 1 & digitalRead(52) == 1)         // Yaw Left CoPilot
      CPacket.Yaw = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(28) == 0) {       // SAS
      if (bitRead(VData.ActionGroups, 0) == 0) {
        MainControls(SAS, HIGH);
      } else {
        MainControls(SAS, LOW);
      }
    }
    //==============================================================================================
    if (digitalRead(29))              // Action Group 1
      ControlGroups(1, LOW);
    else
      ControlGroups(1, HIGH);
    //==============================================================================================
    if (digitalRead(30))              // Lights
      MainControls(LIGHTS, LOW);
    else
      MainControls(LIGHTS, HIGH);
    //==============================================================================================
    if (digitalRead(31))              // Brakes
      MainControls(BRAKES, LOW);
    else
      MainControls(BRAKES, HIGH);
    //==============================================================================================
    if (digitalRead(32))              // Gear
      MainControls(GEAR, LOW);
    else
      MainControls(GEAR, HIGH);
    //==============================================================================================
    if (digitalRead(33))              // RCS
      MainControls(RCS, LOW);
    else
      MainControls(RCS, HIGH);
    //==============================================================================================
    if (digitalRead(34) == 0)         // Translation -X
      CPacket.TX = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(34) & digitalRead(35) == 1)
      CPacket.TX = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(35) == 0)         // Translation +X
      CPacket.TX = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(36) == 0)         // Translation +Y
      CPacket.TY = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(36) & digitalRead(37) == 1)
      CPacket.TY = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(37) == 0)         // Translation -Y
      CPacket.TY = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(38) == 0)         // Translation -Z
      CPacket.TZ = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    else if (digitalRead(38) & digitalRead(39) == 1)
      CPacket.TZ = constrain( map(512, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(39) == 0)         // Translation +Z
      CPacket.TZ = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(40) == 0)              // Abort Sequence
      MainControls(ABORT, HIGH);
    else
      MainControls(ABORT, LOW);
    //==============================================================================================
/*    if (digitalRead(41) == 1)              // Ignition Sequence
      MainControls(STAGE, HIGH);
    else
      MainControls(STAGE, LOW);
*/    //==============================================================================================
    if (digitalRead(42) == 1)              // Stage transition
      MainControls(STAGE, HIGH);
    else
      MainControls(STAGE, LOW);
    //==============================================================================================
    if (digitalRead(43))              // Action Group 2
      ControlGroups(2, LOW);
    else
      ControlGroups(2, HIGH);
    //==============================================================================================
    if (digitalRead(A4))              // Action Group 3
      ControlGroups(3, LOW);
    else
      ControlGroups(3, HIGH);
    //==============================================================================================
    if (digitalRead(A5))              // Action Group 4
      ControlGroups(4, LOW);
    else
      ControlGroups(4, HIGH);
    //==============================================================================================
    if (digitalRead(A6))              // Action Group 5
      ControlGroups(5, LOW);
    else
      ControlGroups(5, HIGH);
    //==============================================================================================
    if (digitalRead(47) == 0)         // Roll Right Pilot
      CPacket.Roll = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(48) == 0)         // Roll Left Pilot
      CPacket.Roll = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(49) == 0)         // Pitch up Pilot
      CPacket.Pitch = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(50) == 0)        //Pitch Down Pilot
      CPacket.Pitch = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(51) == 0)         // Yaw Right Pilot
      CPacket.Yaw = constrain( map(1024, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(52) == 0)         // Yaw Left Pilot
      CPacket.Yaw = constrain( map(0, 0, 1024, -1000, 1000), -1000, 1000 );
    //==============================================================================================
    if (digitalRead(53) == 0) {       // SAS
      if (bitRead(VData.ActionGroups, 0) == 0) {
        MainControls(SAS, HIGH);
      } else {
        MainControls(SAS, LOW);
      }
    }
    //==============================================================================================
    CPacket.Throttle = constrain(map(analogRead(A0), THROTTLEDB, 1024 - THROTTLEDB, 0, 1000), 0, 1000);
    //==============================================================================================
    //CPacket.Yaw = constrain(map(analogRead(A1),0,1024,-1000,1000), -1000, 1000);
    //==============================================================================================
    //CPacket.Pitch = constrain(map(analogRead(A2),0,1024,-1000,1000), -1000, 1000);
    //==============================================================================================
    //CPacket.Roll = constrain(map(analogRead(A3),0,1024,-1000,1000), -1000, 1000);
    //=================================================================================================
    //-------------------------------------------------------------------------------------------------

    KSPBoardSendData(details(CPacket));
  }
}

void controlsInit() {
  // Copilot
  pinMode(22, INPUT_PULLUP);    //Roll Right Joystick
  pinMode(23, INPUT_PULLUP);    //Roll Left Joystick
  pinMode(24, INPUT_PULLUP);    //Pitch Up Joystick
  pinMode(25, INPUT_PULLUP);    //Pitch Down Joystick
  pinMode(26, INPUT_PULLUP);    //Yaw Right Joystick
  pinMode(27, INPUT_PULLUP);    //Yaw Left Joystick
  pinMode(28, INPUT_PULLUP);    //SAS Joystick

  // Middle
  pinMode(29, INPUT_PULLUP);    //Action Group 1
  pinMode(30, INPUT_PULLUP);    //Lights
  pinMode(31, INPUT_PULLUP);    //Breaks
  pinMode(32, INPUT_PULLUP);    //Gears
  pinMode(33, INPUT_PULLUP);    //RCS
  pinMode(34, INPUT_PULLUP);    //RCS Direction
  pinMode(35, INPUT_PULLUP);    //RCS Direction
  pinMode(36, INPUT_PULLUP);    //RCS Direction
  pinMode(37, INPUT_PULLUP);    //RCS Direction
  pinMode(38, INPUT_PULLUP);    //RCS Direction
  pinMode(39, INPUT_PULLUP);    //RCS Direction
  pinMode(40, INPUT_PULLUP);    //Abort
  pinMode(41, INPUT_PULLUP);    //Ignition
  pinMode(42, INPUT_PULLUP);    //Stages SPDT single buttion multiple switches
  pinMode(43, INPUT_PULLUP);    //Action Group 2
  pinMode(A4, INPUT_PULLUP);    //Action Group 3
  pinMode(A5, INPUT_PULLUP);    //Action Group 4
  pinMode(A6, INPUT_PULLUP);    //Action Group 5

  // Pilot
  pinMode(47, INPUT_PULLUP);    //Roll Right Joystick
  pinMode(48, INPUT_PULLUP);    //Roll Left Joystick
  pinMode(49, INPUT_PULLUP);    //Pitch Up Joystick
  pinMode(50, INPUT_PULLUP);    //Pitch Down Joystick
  pinMode(51, INPUT_PULLUP);    //Yaw Right Joystick
  pinMode(52, INPUT_PULLUP);    //Yaw Left Joystick
  pinMode(53, INPUT_PULLUP);    //SAS Joystick

  // Analog
  pinMode(A0, INPUT);           //Throttle
}

byte getSASMode() {
  return VData.NavballSASMode & B00001111;  // leaves alone the lower 4 bits of; all higher bits set to 0.
}

byte getNavballMode() {
  return VData.NavballSASMode >> 4;         // leaves alone the higher 4 bits of; all lower bits set to 0.
}

void setSASMode(byte m) {
  CPacket.NavballSASMode &= B11110000;
  CPacket.NavballSASMode += m;
}

void setNavballMode(byte m) {
  CPacket.NavballSASMode &= B00001111;
  CPacket.NavballSASMode += m << 4;
}

void MainControls(byte n, boolean s) {
  if (s)
    CPacket.MainControls |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.MainControls &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}

void ControlGroups(byte n, boolean s) {
  if (s)
    CPacket.ControlGroup |= (1 << n);       // forces nth bit of x to be 1.  all other bits left alone.
  else
    CPacket.ControlGroup &= ~(1 << n);      // forces nth bit of x to be 0.  all other bits left alone.
}

