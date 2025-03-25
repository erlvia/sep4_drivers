
This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html

arduino for repeating uart commands
#include <Arduino.h>
void setup() {
  // Initialize UART0 and UART3 at 115200 baud rate
  Serial.begin(115200);
  Serial3.begin(115200);
}

void loop() {
  // Transfer data from UART0 to UART3
  if (Serial.available()) {
    char c = Serial.read();  // Read a character from UART0
    Serial3.write(c);        // Write the character to UART3
  }

  // Transfer data from UART3 to UART0
  if (Serial3.available()) {
    char c = Serial3.read();  // Read a character from UART3
    Serial.write(c);          // Write the character to UART0
  }
}




//AT commands
// AT+CWJAP="Den gamle daarlige router","vildfred"
//AT+CWJAP="Den gamle daarlige router","vildfred"
https://sep6a23.ew.r.appspot.com

AT+CIPDOMAIN="url"


AT+CIPDOMAIN="https://sep6a23.ew.r.appspot.com"


AT+CIPSTART="TCP","142.250.181.212",12345

AT+CIPSTART="TCP","172.18.96.1",23