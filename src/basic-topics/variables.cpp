#include <iostream>
#include "basic-topics.h"
// Don't use a namespace for the sake of normalizing syntax without namespaces

void IntroduceVariables() {
   /* Print text to console via C++'s cout. Despite looking slightly different from the Hello World functionality,
    * this line still displays text the same way.
    *  - "std::" serves as an explicit call to C++'s standard cout functionality
    *  - Previously, "std::" was unnecessary due to having "using namespace std;" near the top of the file.
    *  - Thus if you use "using namespace std;", both "cout" and "std::cout" are equivalent expressions.
    */
   std::cout << "Let's introduce variables" << std::endl;   
}