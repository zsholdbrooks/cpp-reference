#include <iostream>
#include "repeater-interface.h"
#include "subdirectory-one/repeat-print.h"
using namespace std;


void BeginRepeatStringProcess(void) {
   string requestedString = "";
   int requestedRepeatNumber = 0;

   cout << "Enter what string you would like repeated: ";
   cin >> requestedString;
   // Since this is for an example, exceptions and wrong types are not handled.
   cout << "Enter how many times you would like the string repeated: ";
   cin >> requestedRepeatNumber;

   // Use direct call to function for text display
   cout << RepeatString(requestedString, requestedRepeatNumber) << endl;
}