void internalTransmit(String *message) {
  // Set pin to high to have control over transmit.
  digitalWrite(RSCONTROL, HIGH);
  INTERNALSERIAL.print(*message);
  // Relinquish control.
  digitalWrite(RSCONTROL, LOW);
}
