void Indicators() {
}

void initLEDS() {
}

void LEDSAllOff() {
}


void InitTxPackets() {
  Serial.println("InitTxPackets");
  HPacket.id = 0;  
  CPacket.id = 101;
  Serial.println("Done InitTxPackets");
}
