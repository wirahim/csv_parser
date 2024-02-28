#include "csv_parser.h"
String test_csv_string = "update,http://www.somedomain.com/firmware.bin";


void setup() {
  // put your setup code here, to run once:
  csv_parser parser(test_csv_string);
  Serial.begin(115200);
  String myTokens[2]; // Array to hold tokens
  int numTokens = parser.allocateTokens(myTokens, 2); // Call function to allocate tokens
  Serial.print(myTokens[0]);
  Serial.print(" ");
  Serial.println(myTokens[1]);
}

void loop() {
  // put your main code here, to run repeatedly:

}
