/*
  RS485Serial.h - Class for sending and receiving on the RS485.
  Created by Shao-Qian Mah, Jan 25, 2020.
*/
#ifndef RS485Serial_h
#define RS485Serial_h

#include "Arduino.h"

class RS485Serial {
  private:
    // This is a reference to the stream object.
    Stream &_serialRef;
    int _ctrlPin;
  public:
    RS485Serial(Stream &serial, int ctrlPin);
    void print(const String &message);
    bool sendPacket(const int &id, const String &data);
};

#endif