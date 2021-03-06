## C++ Topics Left to Implement
- [ ] Basic Variables
- [ ] Math operations
- [ ] Bit level topics
- [ ] Consts, structs, enums
    - Bit manipulation, alignment, packing, unions
- [ ] If and Switch statements
    - Logical operators
    - Ternary operator
- [ ] Loops
    - while loop
    - do while loop
    - infinite loops
    - for loop
    - for each (C++11)
    - continue and break
- [ ] Arrays and Vectors
    - Iterators
- [ ] References and Pointers (PBV & PBR)
    - Memory allocation
    - Function pointers
- [ ] Functions
    - Basic, const correctness
- [ ] String Manipulation
    - Encodings like ASCII, UTF-8, UTF-16
- [ ] Streams
    - [endl vs \n](https://www.geeksforgeeks.org/endl-vs-n-in-cpp/)
    - Files
- [ ] Scope
- [ ] Namespaces
- [ ] Data Structures
    - Linked List, Stack, Queue, BST
- [ ] Exceptions and Error Handling
- [ ] Classes/[OOP](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)
    - [ ] Basic Syntax and Forms
    - [ ] Constructor and Destructor
      - Initialization lists
    - [ ] Overloading
    - [ ] Operator Overloading
    - [ ] Inheritance and Overriding
    - [ ] Class Scoping
    - [ ] Abstract classes (interfaces)
    - [ ] friend keyword
    - [ ] Design Patterns?
- [ ] Preprocessor Directives
- [ ] Templates
- [ ] IPC Mechanisms?
- [ ] [Optimizations?](https://www.geeksforgeeks.org/basic-code-optimizations-in-c/?ref=rp)
- [ ] Boost Library
- [ ] Signal handling
- [ ] STL (Standard Template Library)
- [ ] Multithreading (since C++11)
- [ ] C++ 11 Features
    - [ ] constexpr
    - [ ] [range for loop](https://en.cppreference.com/w/cpp/language/range-for)
    - [ ] [lambda expressions](https://en.cppreference.com/w/cpp/language/lambda)
    - [ ] nullptr expressing empty pointer
    - [ ] [List initialization](https://en.cppreference.com/w/cpp/language/list_initialization)
    - [ ] [explicit overriding keyword](https://www.geeksforgeeks.org/override-keyword-c/)
    - [ ] final keyword
    - [ ] delete keyword with classes
    - [ ] default keyword with classes
    - [ ] scoped vs unscoped enums
    - [ ] auto keyword
    - [ ] static_assert
    - [ ] delegating constructors
    - [ ] variadic templates
    - [ ] alias templates with `using`
    - [ ] `&&` references for [rvalue](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2004/n1690.html) and move semantics
        - [non-const intentions](https://www.delftstack.com/howto/cpp/double-ampersand-in-cpp/#:~:text=In%20C%2B%2B11%2C%20the%20double%20ampersand%20sign%20refers%20to,ampersand%20sign%20and%20another%20with%20the%20double%20ampersand.)
        - [forward referencing](https://blog.petrzemek.net/2016/09/17/universal-vs-forwarding-references-in-cpp/)
- [ ] C++ 14 Features
    - [ ] generic lambdas (use auto as type for parameters)
    - [ ] binary literals
       - `int x = 0b1011101;`
    - [ ] digit separators
       - `unsigned long long l2 = 18'446'744'073'709'550'592llu; // C++14`
       - `unsigned long long l3 = 1844'6744'0737'0955'0592uLL; // C++14`
       - `unsigned long long l4 = 184467'440737'0'95505'92LLU; // C++14`
- [ ] C++ 17 Features
    - [ ] Nested namespaces
       - `namespace X::Y { ??? } instead of namespace X { namespace Y { ??? } }`
    - [ ] [Fold expressions](https://www.codingame.com/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/fold-expressions)
    - [ ] [Golang style init if/switch statements](https://www.codingame.com/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/init-statement-for-ifswitch)
    - [ ] [constexpr if statements](https://www.codingame.com/playgrounds/2205/7-features-of-c17-that-will-simplify-your-code/constexpr-if)
    - [ ] [multiple function return values](https://www.educative.io/edpresso/how-to-return-multiple-values-from-a-function-in-cpp17)
- [ ] C++ 20 Features
    - [ ] Modules
    - [ ] Concepts (extension of templates)
    - [ ] Coroutines
    - [ ] Three-way spaceship operator
    - [ ] Designated Initializers
    - [ ] starts_with() and ends_with()
    - [ ] map.contains(key)