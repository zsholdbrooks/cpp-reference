#include <string>
#include "repeat-print.h"
using namespace std;

string RepeatString(string targetString, int numberOfTimes, string delimiter) {
   string combinedStr = targetString;

   // Return passed string if not a sufficient number of times to repeat
   if (numberOfTimes < 2) {
      return combinedStr;
   }

   // Set up loop based upon target number of repeats. combinedStr already has the first instance, so start at 1.
   for (int i = 1; i < numberOfTimes; i++) {
      combinedStr += delimiter + targetString;
   }

   // Give back newly compounded string
   return combinedStr;
}