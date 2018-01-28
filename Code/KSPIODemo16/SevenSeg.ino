void SevenSegSetup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

  lc.shutdown(1,false);
  lc.setIntensity(1,8);
  lc.clearDisplay(1);

  lc1.shutdown(0,false);
  lc1.setIntensity(0,8);
  lc1.clearDisplay(0);

  lc1.shutdown(1,false);
  lc1.setIntensity(1,8);
  lc1.clearDisplay(1);

  lc2.shutdown(0,false);
  lc2.setIntensity(0,8);
  lc2.clearDisplay(0);

  lc2.shutdown(1,false);
  lc2.setIntensity(1,8);
  lc2.clearDisplay(1);

  lc3.shutdown(0,false);
  lc3.setIntensity(0,8);
  lc3.clearDisplay(0);

  lc3.shutdown(1,false);
  lc3.setIntensity(1,8);
  lc3.clearDisplay(1);
}

/*void displaydfloat(float num) {
  num = num*100;
  d1 = trunc(num/10000000);
  d2 = trunc(num/1000000)-d1*10;
  d3 = trunc(num/100000)-d1*100-d2*10;
  dd1 = d1*10000000+d2*1000000+d3*100000;
  d4 = trunc(num/10000)-d1*1000-d2*100-d3*10;
  d5 = trunc(num/1000)-d1*10000-d2*1000-d3*100-d4*10;
  d6 = trunc(num/100)-d1*100000-d2*10000-d3*1000-d4*100-d5*10;
  d7 = trunc(num/10)-d1*1000000-d2*100000-d3*10000-d4*1000-d5*100-d6*10;
  dd3 = dd1+d4*10000+d5*1000+d6*100+d7*10;
  d8 = num-d1*10000000-d2*1000000-d3*100000-d4*10000-d5*1000-d6*100-d7*10;

  lc.setDigit(0,7,d1,false);
  lc.setDigit(0,6,d2,false);
  lc.setDigit(0,5,d3,false);
  lc.setDigit(0,4,d4,false);
  lc.setDigit(0,3,d5,false);
  lc.setDigit(0,2,d6,true);
  lc.setDigit(0,1,d7,false);
  lc.setDigit(0,0,d8,false);
};*/

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
};

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
};

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
};

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
};

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
};

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
};

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
};

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
};

/*void numberdisplayed(float num) {
  num = num * 100;

  d11 = trunc(fmod(num/10000000,10));
  d22 = trunc(fmod(num/1000000,10));
  d33 = trunc(fmod(num/100000,10));
  d44 = trunc(fmod(num/10000,10));
  d55 = trunc(fmod(num/1000,10));
  d66 = trunc(fmod(num/100,10));
  d77 = trunc(fmod(num/10,10));
  d88 = trunc(fmod(num,10));

  lc.setDigit(1,7,d11,false);
  lc.setDigit(1,6,d22,false);
  lc.setDigit(1,5,d33,false);
  lc.setDigit(1,4,d44,false);
  lc.setDigit(1,3,d55,false);
  lc.setDigit(1,2,d66,false);
  lc.setDigit(1,1,d77,false);
  lc.setDigit(1,0,d88,false);
  
}*/

