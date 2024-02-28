#include "csv_parser.h"

// Constructor definition: Initializes the reference member variable and sets initial indexes
csv_parser::csv_parser(String& read_csvmsg) : csvString(read_csvmsg), startIndex(0), commaIndex(0) {}

// Reads the next token from the CSV string until a comma is encountered
void csv_parser::read(String& returnString) {
    // Find the next comma in the CSV string
    commaIndex = csvString.indexOf(',', startIndex);

    if (commaIndex != -1) {
        // Extract the token from the CSV string
        String token = csvString.substring(startIndex, commaIndex);
        returnString = token; // Set the return string to the extracted token
        startIndex = commaIndex + 1; // Update the start index for the next token
    } else {
        // If no comma is found, extract the last token in the CSV string
        String lastToken = csvString.substring(startIndex);
        returnString = lastToken; // Set the return string to the last token
    }
}

// Overloaded method definition: Reads the next token from the CSV string until a comma is encountered and returns it
String csv_parser::read() {
    String token;
    read(token); // Utilize the existing read method to read into a string reference
    return token; // Return the extracted token
}

// Destructor definition
csv_parser::~csv_parser() {
    // Destructor body
    // No explicit cleanup needed in this case
}

// Method to allocate all tokens in the provided array
// Returns the number of tokens allocated
int csv_parser::allocateTokens(String tokens[], int size) {
    int count = 0; // Counter to keep track of allocated tokens

    // Iterate until the end of the CSV string or until the array is full
    while (startIndex < csvString.length() && count < size) {
        // Find the next comma in the CSV string
        commaIndex = csvString.indexOf(',', startIndex);

        if (commaIndex != -1) {
            // Extract the token from the CSV string
            tokens[count++] = csvString.substring(startIndex, commaIndex);
            startIndex = commaIndex + 1; // Update the start index for the next token
        } else {
            // If no comma is found, extract the last token in the CSV string
            tokens[count++] = csvString.substring(startIndex);
            break; // No more tokens left, exit the loop
        }
    }

    return count; // Return the number of tokens allocated
}
