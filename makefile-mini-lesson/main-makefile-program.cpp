#include <iostream>
#include "directory-one/repeater-interface.h"
#include "directory-two/sum-squares.h"

int main(void) {
   BeginRepeatStringProcess();

   int requestedNumberForSquareSums = 0;
   long funcResult = 0;
   std::cout << "Enter a number greater than 0 but less than 20: ";
   std::cin >> requestedNumberForSquareSums;

   if (requestedNumberForSquareSums == 0) {
      std::cout << "Please enter a number greater than 0 next time.";
   } else {
      std::cout << "The sum of squares from 0 to " << requestedNumberForSquareSums << " is "
                << SumSquaresToXNumber(requestedNumberForSquareSums) << std::endl;
   }

   return 0;
}