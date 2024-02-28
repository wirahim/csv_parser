#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <Arduino.h>

class csv_parser {
private:
    String& csvString; // Reference to the CSV string
    int startIndex; // Index from which to find the ","
    int commaIndex; // Index until when to read the new token

public:
    // Constructor: Initializes the reference member variable and sets initial indexes
    csv_parser(String& read_csvmsg);
    // Destructor
    ~csv_parser();
    // Reads the next token from the CSV string until a comma is encountered
    void read(String& returnString);

    // Overloaded method: Reads the next token from the CSV string until a comma is encountered and returns it
    String read();

    // Method to allocate all tokens in the provided array
    // Returns the number of tokens allocated
    int allocateTokens(String tokens[], int size);
};

#endif
