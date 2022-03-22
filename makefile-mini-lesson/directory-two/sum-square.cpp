#include "sum-squares.h"

long SquareMyNumber(int);

long SumSquaresToXNumber(int lastSeriesNumber) {
   long sumOfSquares = 0;

   // Considering valid input to be greater than 0
   if (lastSeriesNumber < 1) {
      return 0;
   }

   for (int i = 1; i < lastSeriesNumber + 1; i++) {
      sumOfSquares += SquareMyNumber(i);
   }

   return sumOfSquares;
}

// Private helper function
long SquareMyNumber(int number) {
   // Cast to long for potentially large products
   long x = (long)number;
   return x * x;
}