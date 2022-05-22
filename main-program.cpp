// Include standard library for the program to display and request text
#include <iostream>
// Include this project's central point for further discussion
#include "src/functionality-catalog.h"
// Use standard namespace for current ease of use
using namespace std;


/* Implement beginning of program with required main routine.
 *  - Can keep it simple by just always using "int main(int argc, char *argv[]) {}" like below
 *  - Both "int main() {}" and "int main(int, char**) {}" can be used to fulfill compilation requirement
 *     - "int main() {}" is used when you don't care about receiving command line arguments
 *     - "int main(int, char**) {}" allows you to pass arguments from command line as a list of c-strings (array
 *       of characters).
 *        - The names for the int and char** parameters are flexible, but standard convention is "int argc"
 *          (argument count) and "char *argv[]" or "char **argv" (interpret as list of c-strings).
 *  - Return type is always an integer to return program's exit status to executing shell (like BASH, powershell,
 *    command prompt, etc.). This allows for scripts and supervising programs to act based off of return statuses.
 */
int main(int argc, char *argv[]) {
   // Print text to console via C++'s cout
   cout << "Welcome to the C++ reference program!\n" << endl;//

   // Declare and initialize a variable
   bool verboseIntroduction = true;

   // Run code contained in braces if expression inside parentheses is true
   if (verboseIntroduction) {
      // Run function showing basic C++ concepts. This can be skipped by changing verboseIntroduction's value to false.
      BasicFunctionality();
   }

   // Enter menu for showing targeted C++ concepts
   FunctionalityCatalog(argc, argv);

   return 0;
}