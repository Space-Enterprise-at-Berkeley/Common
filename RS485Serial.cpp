/*
  RS485Serial.cpp - Class for sending and receiving on the RS485.
  Created by Shao-Qian Mah, Jan 25, 2020.
*/

#include "Arduino.h"
#include "RS485Serial.h"
#include "Helpers.h"

RS485Serial::RS485Serial(Stream &serial, int ctrlPin)
:  _serialRef(serial)
{
  _ctrlPin = ctrlPin;
  pinMode(ctrlPin, OUTPUT);
  digitalWrite(ctrlPin, LOW);
}

void RS485Serial::print(const String &message) {
  digitalWrite(_ctrlPin, HIGH);
  _serialRef.print(message);
  digitalWrite(_ctrlPin, LOW);
}

bool RS485Serial::sendPacket(const int &id, const String &data) {
  digitalWrite(_ctrlPin, HIGH);
  String idString = idToString(id);
  if (!idString.length() == 0) {
    _serialRef.print("(" + idString + ")");
    digitalWrite(_ctrlPin, LOW);
    return true;
  }
  else {
    return false;
  }
}
