#include <LedControl.h>

float a1;
float a2;
float a3;
float a4;
float a5;
float a6;
float a7;
float a8;
float num = 12345679;
 
 LedControl lc=LedControl(13,11,12,2);  // Data,Clock,Load,#ofdisplays
 
void setup() {
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

  lc.shutdown(1,false);
  lc.setIntensity(1,8);
  lc.clearDisplay(1);
  
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


void loop() {
  
  lc.setDigit(1,7,a1,false);
  lc.setDigit(1,6,a2,false);
  lc.setDigit(1,5,a3,false);
  lc.setDigit(1,4,a4,false);
  lc.setDigit(1,3,a5,true);
  lc.setChar(1,2,' ',false);
  lc.setChar(1,1,'e',false);
  lc.setDigit(1,0,a8,false);
}
