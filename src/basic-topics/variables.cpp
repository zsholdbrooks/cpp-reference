#include <iostream>
#include "basic-topics.h"
// Don't use a namespace for the sake of normalizing syntax without namespaces

void IntroduceVariables(void);

void DiscussVariables() {
   // Introduce basic concepts of variables
   IntroduceVariables();

   // Introduce C++'s math operations

   // Walk through bit manipulations

   // Introduce constants, structs, and enumerations

   return;
}

void IntroduceVariables() {
   /* Print text to console via C++'s cout. Despite looking slightly different from the Hello World functionality,
    * this line still displays text the same way.
    *  - "std::" serves as an explicit call to C++'s standard cout functionality
    *  - Previously, "std::" was unnecessary due to having "using namespace std;" near the top of the file.
    *  - Thus if you use "using namespace std;", both "cout" and "std::cout" are equivalent expressions.
    */
   std::cout << "Let's introduce variables!" << std::endl;
   std::cout << "Start with looking at the " << __func__ << " function in " << __FILE__ << "\n" << std::endl;

   std::cout << "Variables allow your program to store and interact with values." << std::endl;
   std::cout << "C++ syntax requires you to define a type and name for each defined variable." << std::endl;
   std::cout << "Typical types within C++ are int (integers), double (decimal/floating point), bool (true/false), char (character), and string.\n" << std::endl;

   // Declare an integer variable
   int myInt;
   // Define & initialize the variable with a number
   myInt = 6;

   // Print out variable value
   std::cout << "The value of myInt is " << myInt << std::endl;
   // Reassign myInt's value
   myInt = -10;
   std::cout << "The new value of myInt is " << myInt << "\n" << std::endl;

   // Define new boolean variable with initial value of true
   bool myBool = true;
   std::cout << "The value of myBool is " << myBool << ". Note that a true value corresponds to a 1." << std::endl;
   myBool = false;
   std::cout << "The boolean false value maps to 0 as shown with myBool's new value of " << myBool << "\n" << std::endl;
   
   // Explain the character char type
   char myChar = 'H';
   std::cout << "The value of myChar is " << myChar << ". Note that a char is only a single character.\n" << std::endl;

   // Explain the double type
   std::cout << "A fraction or decimal is represented by type called a double." << std::endl;
   double piNum = 3.14159;
   std::cout << "The value of piNum is " << piNum << std::endl;

   // Discuss the difference between the decimal float and double data types
   std::cout << "\nNote that another lesser used data type to represent fractions is float, but typically double is used instead." << std::endl;
   std::cout << "The reason for this is that the double type is more numerically accurate than a float." << std::endl;
   std::cout << "The double type is more accurate since double variable takes up twice the space that a float occupies." << std::endl;
   std::cout << "Floats can be used in situations that decimals are needed but size constraints are present.\n" << std::endl;

   // Introduce strings
   std::string myString = "A string is a data type that can be used to store a series of characters to create a full sentence or phrase.";
   std::cout << myString << std::endl;
   std::cout << "Notice that the entire initial sentence was stored in one variable.\n" << std::endl;

   return;
}