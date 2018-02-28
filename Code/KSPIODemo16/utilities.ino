void Indicators() {
  caution = 0;
  warning = 0;

  caution += VData.G > GCAUTION;
  warning += VData.G > GWARN;
  caution += VData.LiquidFuelS / VData.LiquidFuelTotS * 100 < FUELCAUTION;
  warning += VData.LiquidFuelS / VData.LiquidFuelTotS * 100 < FUELWARN;

  if (caution != 0)
    digitalWrite(YLED, HIGH);
  else
    digitalWrite(YLED, LOW);

  if (warning != 0)
    digitalWrite(RLED, HIGH);
  else
    digitalWrite(RLED, LOW);

  digitalWrite(SASLED, ControlStatus(AGSAS));
  digitalWrite(RCSLED, ControlStatus(AGRCS));
  digitalWrite(CG1LED, ControlStatus(AGCustom01));
}

void initLEDS() {
  pinMode(GLED, OUTPUT);
  digitalWrite(GLED, HIGH);

  pinMode(YLED, OUTPUT);
  digitalWrite(YLED, HIGH);

  pinMode(RLED, OUTPUT);
  digitalWrite(RLED, HIGH);

  pinMode(SASLED, OUTPUT);
  digitalWrite(SASLED, HIGH);

  pinMode(RCSLED, OUTPUT);
  digitalWrite(RCSLED, HIGH);

  pinMode(CG1LED, OUTPUT);
  digitalWrite(CG1LED, HIGH);
}

void LEDSAllOff() {
  digitalWrite(GLED, LOW);
  digitalWrite(YLED, LOW);
  digitalWrite(RLED, LOW);
  digitalWrite(SASLED, LOW);
  digitalWrite(RCSLED, LOW);
  digitalWrite(CG1LED, LOW);
}


void InitTxPackets() {
  HPacket.id = 0;
  CPacket.id = 101;
}

class WarningSignal {
  private:
    boolean tick = false;   // Display warning when true. Do nothing otherwise.
    float low;              // Value of lowest intensity warning.
    float high;             // Value of full intesity warning.
    float flash;            // Value above which the warning begins to blink.
    float reset;            // Value below which the warning stops.
  public:
    WarningSignal(float low, float high, float flash, float reset) {
      this->low = low;
      this->high = high;
      this->flash = flash;
      this->reset = reset;
    };
    void checkWarning(float value);
    boolean getWarning();
    void displayWarning(float value);
};

void WaringSignal::checkWarning(float value) {
  if (tick) {
    // set the warningTick to false when the value is below the reset value.
    tick = (value > reset);
  } else {
    // set the warningTick to true when the value is above the low value.
    tick = (value > low);
  }
}

boolean WaringSignal::getWarning() {
  return tick;
}

void WaringSignal::displayWarning(float value) {
  checkWarning(value);
  if (getWarning()) {
    
  }
}

