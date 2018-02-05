void initialize(LedControl lc) {
  for (int address = 0; address < lc.getDeviceCount(); address++) {
    lc.shutdown(address, false);
    lc.setIntensity(address, 8);
    lc.clearDisplay(address);
  }
}

void SevenSegSetup() {
//  initialize(lc);
//  initialize(lc1);
//  initialize(lc2);
//  initialize(lc3);
    
  // chain 1, display 1
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

  // chain 1, display 2
  lc.shutdown(1,false);
  lc.setIntensity(1,8);
  lc.clearDisplay(1);

  // chain 2, display 1
  lc1.shutdown(0,false);
  lc1.setIntensity(0,8);
  lc1.clearDisplay(0);

  // chain 2, display 2
  lc1.shutdown(1,false);
  lc1.setIntensity(1,8);
  lc1.clearDisplay(1);

  // chain 3, display 1
  lc2.shutdown(0,false);
  lc2.setIntensity(0,8);
  lc2.clearDisplay(0);

  // chain 3, display 2
  lc2.shutdown(1,false);
  lc2.setIntensity(1,8);
  lc2.clearDisplay(1);

  // chain 4, display 1
  lc3.shutdown(0,false);
  lc3.setIntensity(0,8);
  lc3.clearDisplay(0);

  // chain 4, display 2
  lc3.shutdown(1,false);
  lc3.setIntensity(1,8);
  lc3.clearDisplay(1);
}

void displayfloat1(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc.setDigit(0,7,a1,false);
  lc.setDigit(0,6,a2,false);
  lc.setDigit(0,5,a3,false);
  lc.setDigit(0,4,a4,false);
  lc.setDigit(0,3,a5,false);
  lc.setDigit(0,2,a6,false);
  lc.setDigit(0,1,a7,false);
  lc.setDigit(0,0,a8,false);
}

void displayfloat2(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));
  
  lc.setDigit(1,7,a1,false);
  lc.setDigit(1,6,a2,false);
  lc.setDigit(1,5,a3,false);
  lc.setDigit(1,4,a4,false);
  lc.setDigit(1,3,a5,false);
  lc.setDigit(1,2,a6,false);
  lc.setDigit(1,1,a7,false);
  lc.setDigit(1,0,a8,false);
}

void displayfloat3(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));
  
  lc1.setDigit(0,7,a1,false);
  lc1.setDigit(0,6,a2,false);
  lc1.setDigit(0,5,a3,false);
  lc1.setDigit(0,4,a4,false);
  lc1.setDigit(0,3,a5,false);
  lc1.setDigit(0,2,a6,false);
  lc1.setDigit(0,1,a7,false);
  lc1.setDigit(0,0,a8,false);
}

void displayfloat4(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc1.setDigit(1,7,a1,false);
  lc1.setDigit(1,6,a2,false);
  lc1.setDigit(1,5,a3,false);
  lc1.setDigit(1,4,a4,false);
  lc1.setDigit(1,3,a5,false);
  lc1.setDigit(1,2,a6,false);
  lc1.setDigit(1,1,a7,false);
  lc1.setDigit(1,0,a8,false);
}

void displayfloat5(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc2.setDigit(0,7,a1,false);
  lc2.setDigit(0,6,a2,false);
  lc2.setDigit(0,5,a3,false);
  lc2.setDigit(0,4,a4,false);
  lc2.setDigit(0,3,a5,false);
  lc2.setDigit(0,2,a6,false);
  lc2.setDigit(0,1,a7,false);
  lc2.setDigit(0,0,a8,false);
}

void displayfloat6(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc2.setDigit(1,7,a1,false);
  lc2.setDigit(1,6,a2,false);
  lc2.setDigit(1,5,a3,false);
  lc2.setDigit(1,4,a4,false);
  lc2.setDigit(1,3,a5,false);
  lc2.setDigit(1,2,a6,false);
  lc2.setDigit(1,1,a7,false);
  lc2.setDigit(1,0,a8,false);
}

void displayfloat7(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc3.setDigit(0,7,a1,false);
  lc3.setDigit(0,6,a2,false);
  lc3.setDigit(0,5,a3,false);
  lc3.setDigit(0,4,a4,false);
  lc3.setDigit(0,3,a5,false);
  lc3.setDigit(0,2,a6,false);
  lc3.setDigit(0,1,a7,false);
  lc3.setDigit(0,0,a8,false);
}

void displayfloat8(float num) {
  a1 = trunc(fmod(num/10000000,10));
  a2 = trunc(fmod(num/1000000,10));
  a3 = trunc(fmod(num/100000,10));
  a4 = trunc(fmod(num/10000,10));
  a5 = trunc(fmod(num/1000,10));
  a6 = trunc(fmod(num/100,10));
  a7 = trunc(fmod(num/10,10));
  a8 = trunc(fmod(num,10));

  lc3.setDigit(1,7,a1,false);
  lc3.setDigit(1,6,a2,false);
  lc3.setDigit(1,5,a3,false);
  lc3.setDigit(1,4,a4,false);
  lc3.setDigit(1,3,a5,false);
  lc3.setDigit(1,2,a6,false);
  lc3.setDigit(1,1,a7,false);
  lc3.setDigit(1,0,a8,false);
}

void displayFloat(LedControl lc, int address, float number) {
  byte digits[8];
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
  
  for (int i = 0; i <= 7; i++) {
    byte digit  = digits[i];
    if (digit > 9) {
      if (digit > 20) {
        lc.setChar(address, 7-i, ' ', false);
      } else {
        lc.setChar(address, 7-i, 'E', false);
      }
    } else {
      lc.setDigit(address, 7-i, digit, decimals[i]);
    }
  }
}

