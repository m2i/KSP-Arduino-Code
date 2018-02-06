void initialize(LedControl lc) {
  for (int address = 0; address < lc.getDeviceCount(); address++) {
    lc.shutdown(address, false);
    lc.setIntensity(address, 8);
    lc.clearDisplay(address);
  }
}

void SevenSegSetup() {
  initialize(lc);
  initialize(lc1);
  initialize(lc2);
  initialize(lc3);
}

void displayfloat(LedControl lc, int address, float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc.setDigit(address,7,a1,false);
  lc.setDigit(address,6,a2,false);
  lc.setDigit(address,5,a3,false);
  lc.setDigit(address,4,a4,false);
  lc.setDigit(address,3,a5,false);
  lc.setDigit(address,2,a6,false);
  lc.setDigit(address,1,a7,false);
  lc.setDigit(address,0,a8,false);
}

void displayFloat(LedControl LCDisplay, int address, float number) {
  int digits[8];
  boolean decimals[8];
  for (int i = 0; i <= 7; i++) {
    digits[i] = 0;
    decimals[i] = false;
  }

  int power, numberInt;

  // check size of number, multiply or divide by ten while incrementing the power
  // variable until the number is in range. Large numbers should be shrunk to 4 or
  // 5 digits. Small numbers should be grown to up to 8 digits. Some numbers will
  // need no size altering.
  power = 0;
  // negative power variable reduction
  if (number < 10000000.0f) {
    while (number < 10000000.0f) {
      number *= 10;
      power--;
      if (power == -7)
        break;
    }
    // positive two digit power variable reduction
  } else if (number > 99999999999999.9f) {
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
  numberInt = (int) number;

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

    // place location of decimal
    if (power < 0) {
      // change decimal boolean to true for the digit with the decimal
      decimals[7 + power] = true;
    } else {
      decimals[7] = true;
    }
  }
  
  LCDisplay.setDigit(address,7,digits[0],decimals[0]);
  LCDisplay.setDigit(address,6,digits[1],decimals[1]);
  LCDisplay.setDigit(address,5,digits[2],decimals[2]);
  LCDisplay.setDigit(address,4,digits[3],decimals[3]);
  LCDisplay.setDigit(address,3,digits[4],decimals[4]);
  LCDisplay.setDigit(address,2,digits[5],decimals[5]);
  LCDisplay.setDigit(address,1,digits[6],decimals[6]);
  LCDisplay.setDigit(address,0,digits[7],decimals[7]);

//  for (int i = 0; i <= 7; i++) {
//    byte digit  = digits[i];
//    if (digit > 9) {
//      if (digit > 20) {
//        LCDisplay.setChar(address, 7-i, ' ', false);
//      } else {
//        LCDisplay.setChar(address, 7-i, 'E', false);
//      }
//    } else {
//      LCDisplay.setDigit(address, 7-i, digit, decimals[i]);
//    }
//  }
}

