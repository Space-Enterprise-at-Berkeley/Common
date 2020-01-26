// ~~~~~~~~~~~~~~~~~~ Packet definitions ~~~~~~~~~~~~~~~~~~
#define startChar '('
#define endChar ')'
#define packetTimeoutMillis 500
// This includes '(', ID and ')'.
#define packetMaxLength 100

// Convert ID to guaranteed length 2 string. 
// Return "" if malformed.
String idToString(int id) {
  if (id >= 0 && id < 10) {
    return "0" + String(id);
  } else if (id >= 10 && id <= 99) {
    return String(id);
  } else {
    return "";
  }
}

// Parse packet. Return "" if malformed.
String readPacket(Stream &serial, ) {
  
}

// Read RS485 packet. Return "" if malformed.
String sendRSPacket(Stream &serial, int {
  
}
