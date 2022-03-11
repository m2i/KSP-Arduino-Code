void initialize(LedControl lc) {
  for (int address = 0; address < lc.getDeviceCount(); address++) {
    lc.shutdown(address, false);
    lc.setIntensity(address, 8);
    lc.clearDisplay(address);
  }
}

void SevenSegSetup() {
  Serial.println("SevenSegSetup");
  initialize(lc);
  initialize(lc1);
  initialize(lc2);
  initialize(lc3);
  Serial.println("Done SevenSegSetup");
}

void displayFloat(LedControl lc, int address, float number) {
  byte digits[8];
  boolean decimals[8];
  for (int i = 0; i <= 7; i++) {
    decimals[i] = false;
  }

  int power;
  uint32_t numberInt;

  // check size of number, multiply or divide by ten while incrementing the power
  // variable until the number is in range. Large numbers should be shrunk to 4 or
  // 5 digits. Small numbers should be grown to up to 8 digits. Some numbers will
  // need no size altering.
  power = 0;
  if (number > 99999999999999.9f) {
    while (number > 9999.9f) {
      number /= 10;
      power++;
    }
    // positive single digit power variable reduction
  } else if (number > 99999999.9f) {
    while (number > 99999.9f) {
      number /= 10;
      power++;
    }
  }
  // ... or no size reduction is needed
  numberInt = (uint32_t) number;

  // if the power variable has two digits...
  if (power > 9) {
    // digits[7] is the second digit of the power variable
    digits[7] = power % 10;
    // digits[6] is the first digit of the power variable
    digits[6] = power / 10;
    // digits[5] will be turned into an "E"
    digits[5] = 11;
    // digits[4] will be a black space
    digits[4] = 22;
    // digits[0]-digits[3] are the significant figures of the display values
    for (int i = 3; i >= 1; i--) {
      digits[i] = numberInt % 10;
      numberInt /= 10;
    }
    digits[0] = numberInt;
    decimals[3] = true;
    // if the power variable has a single digit...
  } else if (power > 0) {
    // digits[7] is the power variable
    digits[7] = power;
    // digits[6] will be turned into an "E"
    digits[6] = 11;
    // digits[5] will be a blank space
    digits[5] = 22;
    // digits[0]-digits[4] are the significant figures of the display values
    for (int i = 4; i >= 1; i--) {
      digits[i] = numberInt % 10;
      numberInt /= 10;
    }
    digits[0] = numberInt;
    decimals[4] = true;
  } else {
    // digits[0]-digits[7] are the significant figures of the display values
    for (int i = 7; i >= 1; i--) {
      digits[i] = numberInt % 10;
      numberInt /= 10;
    }
    digits[0] = numberInt;
    decimals[7] = true;
  }

  for (int i = 0; i <= 7; i++) {
    byte digit  = digits[i];
    if (digit > 9) {
      if (digit > 20) {
        lc.setChar(address, i, ' ', false);
      } else {
        lc.setChar(address, i, 'E', false);
      }
    }/* else {
      lc.setDigit(address, i, digit, decimals[i]);
      if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0 && digits[5] == 0 && digits[6] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);
        lc.setChar(address, 5, ' ', decimals[5]);
        lc.setChar(address, 6, ' ', decimals[6]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0 && digits[5] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);
        lc.setChar(address, 5, ' ', decimals[5]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);}
      else if (digits[0] == 0 && digits[1] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);}
      else if (digits[0] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);}
    }*/
  }

      if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0 && digits[5] == 0 && digits[6] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);
        lc.setChar(address, 5, ' ', decimals[5]);
        lc.setChar(address, 6, ' ', decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0 && digits[5] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);
        lc.setChar(address, 5, ' ', decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0 && digits[4] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setChar(address, 4, ' ', decimals[4]);
        lc.setDigit(address, 5, digits[5], decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0 && digits[3] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setChar(address, 3, ' ', decimals[3]);
        lc.setDigit(address, 4, digits[4], decimals[4]);
        lc.setDigit(address, 5, digits[5], decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0 && digits[1] == 0 && digits[2] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setChar(address, 2, ' ', decimals[2]);
        lc.setDigit(address, 3, digits[3], decimals[3]);
        lc.setDigit(address, 4, digits[4], decimals[4]);
        lc.setDigit(address, 5, digits[5], decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0 && digits[1] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setChar(address, 1, ' ', decimals[1]);
        lc.setDigit(address, 2, digits[2], decimals[2]);
        lc.setDigit(address, 3, digits[3], decimals[3]);
        lc.setDigit(address, 4, digits[4], decimals[4]);
        lc.setDigit(address, 5, digits[5], decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
      else if (digits[0] == 0){
        lc.setChar(address, 0, ' ', decimals[0]);
        lc.setDigit(address, 1, digits[1], decimals[1]);
        lc.setDigit(address, 2, digits[2], decimals[2]);
        lc.setDigit(address, 3, digits[3], decimals[3]);
        lc.setDigit(address, 4, digits[4], decimals[4]);
        lc.setDigit(address, 5, digits[5], decimals[5]);
        lc.setDigit(address, 6, digits[6], decimals[6]);
        lc.setDigit(address, 7, digits[7], decimals[7]);}
  
}
