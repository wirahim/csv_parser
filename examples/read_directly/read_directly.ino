#include "csv_parser.h"
String test_csv_string = "update,http://www.somedomain.com/firmware.bin";


void setup() {
  // put your setup code here, to run once:
  csv_parser parser(test_csv_string);
  Serial.begin(115200);
  String validator = parser.read(); 
  String URL = parser.read();
  Serial.print(validator);
  Serial.print(" ");
  Serial.println(URL);
}

void loop() {
  // put your main code here, to run repeatedly:

}
