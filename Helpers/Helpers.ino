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
