// Handshake

void Handshake() {
  digitalWrite(GLED, HIGH);

  HPacket.id = 0;
  HPacket.M1 = 3;
  HPacket.M2 = 1;
  HPacket.M3 = 4;

  KSPBoardSendData(details(HPacket));
  // Serial.println(F("KSP;0"));
  // delay(1000);
}

