// REQUIRES:
// Common/Helpers/Helpers.ino

class RS485Serial {
  private:
    // This is a reference to the stream object.
    Stream &_serialRef;
    int _ctrlPin;
  public:
    void begin(Stream &serial, int ctrlPin) {
      _serialRef = serial;
      _ctrlPin = ctrlPin;
      pinMode(ctrlPin, OUTPUT);
      digitalWrite(ctrlPin, LOW);
    }

    // Send an arbitary message string.
    void print(const String &message) {
      digitalWrite(_ctrlPin, HIGH);
      _serialRef.print(message);
      digitalWrite(_ctrlPin, LOW);
    }

    // Send packet with ID and DATA. Return true if successful, return false if not.
    bool sendPacket(const int &id, const String &data) {
      digitalWrite(_ctrlPin, HIGH);
      String idString = idToString(id);
      if (!idString.empty()) {
        _serialRef.print("(" + idString + ")");
        digitalWrite(_ctrlPin, LOW);
        return true;
      } else {
        return false;
      }
      
    }
};
