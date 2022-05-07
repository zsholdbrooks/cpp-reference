# C++ Project Organization

As any project gets more sophisticated, it also tends to get larger. To be able to keep up with this growing functionality, capable organization is critical. Generally, functionality is grouped and written according to scope/context. The method to do this is often the subject of extreme debate within programming, but often the reasons and mechanisms are the same. Speaking from experience, proper organization allows you to maintain proper focus, minimize unintended errors, and just make your life easier. Header files and makefiles are those mechanisms for C++ programs to achieve this organization.

A bit of background is necessary to properly understand how these two mechanisms work together. When you start programming, everything seems kind of random and esoteric with methods/functions, memory, variables, and objects. Well, at the end of the day, it is all the same. Everything gets put together down into 0's and 1's. 

How does the program know what 0's and 1's are the ones they need? Context. Programs generally interpret different groups of binary data as symbols. These symbols will carry context in which and where they should be used. This might seem a bit abstract, but essentially everything is a symbol. Functions, variables, objects, etc are all symbols that have their own set of binary data that lie in your compiled program's data.

From a program's organizational standpoint, symbols can be used as a sort of set of rules and ledger. While the program is being compiled, the compiler tries to ensure all the symbols have their data and are actually usable. Compilation will fail if a compiler determines that even one symbol doesn't have all its data or isn't accessed correctly in a particular scenario.

What do I mean by symbols having their data? There are several ways that variables, functions, etc (symbols) can be named but not necessarily exist. This is generally done to have better organization (prototypes, talked about in [header files](#header-files)). Establishing prototypes is kind of like building the frame of a house without actually building the walls and filling it with furniture. Since it's not totally complete, we can't really use it.

How can a symbol not be usable? Obviously, it isn't usable if it isn't complete, but it can also be considered not usable if all the defined data is there. Certain parts of a program may attempt to reference other parts but may not have an established path to a symbol. In this case, you are often the programmer saying "I know this thing is there!", but the program doesn't know where because you haven't told it. It's like you want to go to someone's house and know it's there, but your GPS is telling you it doesn't know how because there are no roads to the house. You essentially have to build a road to it and show the part of the program that this symbol actually exists. It's kind of like the idea of "Out of sight, out of mind".

**tldr; C++ treats variables, functions, and objects like blobs of data called symbols during compilation. To compile a program successfully, all symbols must be complete, and all references to symbols must have a path to the symbol itself.**

# Header Files

Header (.h) files are a way to divide code into different files rather than having one giant file with thousands and thousands of lines of code. They can be a bit confusing once you start using them with include directives (the important lines at the very top of cpp files). Generally, header files are used as a place of organization by listing all of your relevant functions, variables, objects, and other C++ aspects.

The exact organization is not hard and fast, but for the sake of simplicity, you could have a bunch of cpp source files in a directory and have a single header file in the same directory that lists the functions from each source file. Notice that there are two subdirectories in the [current directory](https://github.com/zsholdbrooks/cpp-reference/tree/main/makefile-mini-lesson) named "directory-one" and "directory-two" that have code in them. This is effectively how these directories are organized. A single header file represents the cpp files in each directory. You can actually have multiple header files in the same directory, but don't worry about doing that until you get the hang of using this type of organization.

How do these header files work? Effectively, you are providing just a name/reference for everything you put in one of these header files. You are not supposed to actually implement them. This distinction is often discussed as declaration versus definition. Naming various things as **declarations** are what you are doing in header files. When declaring functions specifically, you create **prototypes** that will specify the function's name, return type, and parameter list. **Definitions** for these declared functions, variables, etc are done in the cpp files. These definitions will have the actual code and actions that are run when you call these functions or data that might be retrieved for variables.

Another point to consider with the definition and declaration discussion is that there can only be one definition of a particular thing. You can have as many of the exact same declarations of the same thing, but they will only really act as symbol references. Think about it. You might have multiple names, but you are still only one person. There is even more to this discussion, but this is a fair working idea behind what is happening. The declarations are just names while the definitions are the actual things that have the names.

Problems with redefinition errors begin to occur in C++ when you have multiple cpp source files trying to use the same header file. A scenario will occur where the compiler will attempt to create a second copy of the header file and will flag an error saying there is already a definition for this functionality. It can't distinguish the fact that it could actually be the exact same file it has already compiled. To avoid this problem, it is common practice to have **include guards** around the header file. Look at the first two and last lines of [repeater-interface.h](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/directory-one/repeater-interface.h). The first line of `#ifndef REPEATER_INTERFACE_H` is telling the compiler that if the REPEATER_INTERFACE_H symbol is not defined then compile the code until the corresponding `#endif` at the end of the file. Then, immediately, we define the REPEATER_INTERFACE_H symbol. Thus, if the compiler enters the file again, the existence of the REPEATER_INTERFACE_H symbol will cause the `#ifndef` to evaluate to false and not attempt to compile that code again.

Look at [repeater-interface.h](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/directory-one/repeater-interface.h) and [repeater-interface.cpp](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/directory-one/repeater-interface.cpp). Notice that the only file that is actually doing anything is *repeater-interface.cpp*. The idea is that the cpp files actually contain the actions while the header files only organize and centralize the actions like a reference sheet. Notice, too, that repeater-interface.cpp's second line is actually `#include "repeater-interface.h"`. It isn't just enough to name the two files the same. ***You must link the two together by having the cpp source file include the header file.***

Will the compiler just know that I have a function called *BeginRepeatStringProcess* in [repeater-interface.cpp](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/directory-one/repeater-interface.cpp) so that I can use it in my main program in [main-makefile-program.cpp](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/main-makefile-program.cpp)? No, you have to tell it where to look. This is why we use include (the **#include** things at the top of files) directives. Notice the line `#include "directory-one/repeater-interface.h"` at the top of main-makefile-program.cpp. We are telling the compiler that it should look in the directory-one directory for the repeater-interface.h header file. The compiler will look there and see that the header has declared the BeginRepeatStringProcess function.

What happens if that file or function isn't there? That is what symbol resolution and linking is during compilation. The function call in main-makefile-program.cpp acts as a reference to the BeginRepeatStringProcess symbol that is declared in repeater-interface.h and implemented in repeater-interface.c. If the compiler can't find the BeginRepeatStringProcess symbol at some point in the process, it doesn't exist in the context that you are trying to use it. This means that you must either create an explicit path to BeginRepeatStringProcess by using a proper include directive with the right header path, or that the function may not be implemented/defined.

Again, there isn't necessarily a specific way you have to organize your header and source files. Some projects have all their header files in one place while others have them coupled with the cpp source files. The most important part is that you have a proper `#include` directive at the top of your cpp file to the correct location of the header file (even if it isn't in the same directory).

(Another relevant thought) Note that during compilation, header files are really not directly compiled. The code from header files will be pulled in via the cpp source file includes. This means that header files will not appear on the command line while compiling with g++.

# Makefile
A good conceptual way to view how makefiles work is by thinking about cooking dinner. Maybe you want to cook a dish with chicken, broccoli, and rice. Can you cook them all together? Yes, but you could also cook everything separate and allow each component to have its own distinct characteristics. You may want to brine the chicken, season it with a dry rub, and bake it. With the broccoli, you might just want to keep it simple and just steam the it. With the rice, you could dice up some carrots and make some fried rice. After cooking each part of your dinner, you'll put them all on one plate as a whole meal.

Makefiles essentially allow you to break the process of a project's compilation down into individual parts. As you progress through the makefile process, you will end up with distinct object files from each source file. You will later take these individual object files and combine them together to complete the full program. This is very much like how you can distinctly separate the chicken, broccoli, and rice during cooking. Each one may have its own technique and set of necessary steps to create a portion of the larger meal.

One difference between cooking dinner and using makefiles, though, is that certain object files will cross reference other object files. During compilation, a process will occur called ***linking*** where the compiler will go through and attempt to resolve the paths between symbols. Since we want the object files to remain independent of one another despite having dependent code, we tell the compiler not to attempt linking until the very end. We're basically telling the compiler, "Hey, we know you might not know what that thing there is, but don't worry about it yet." The object files are not even really executable code yet, so this is a valid practice.

Once we get to the very end and have all the object files for all the cpp files compiled, we compile the main cpp program file along with all of these precompiled object files. It is here that the compiler will actually do the linking. When successful, we will have a consolidated program that we can run on our computer.

**tldr; Makefiles are set up to compile individual pieces of code that act as fragments of the full program. Some fragments depend on other specific fragments, so the makefile first will gather all the pieces before trying to put them all together. In the end, a full program will be put together from these fragments while creating paths between each fragment that depends on each other.**

## Makefiles from a technical side
Since you are able to split a project into a bunch of different files, you need to compile every source (cpp) file every time you wish to compile the full program. If you download a fresh project with something like 20 cpp files, you will either have to run *g++* 20 times or several very long commands. To solve this problem, the GNU tool **make** uses a designated **makefile** for building the project by simply running `make` in the terminal.Make will also detect object files that can be reused by comparing timestamps to shorten compilation time (which is really nice on large projects). Despite these benefits, makefiles can be rather intimidating to set up since makefiles almost seem like it is its own programming language.

Makefiles can generally be treated as extensions of Unix shell scripting with a specific organization. It may look a bit foreign, but the makefile ends up running the same commands you would in the terminal. The organization looks as follows:
```make
target: dependency1 dependency2
    command1
    command2
```

Targets in makefiles end up being the entry points when running your `make` command. Since makefiles are intended for use in compilation, targets are expected to represent files and can have dependencies on other files. Since makefiles are still scripts, you can use variables. Variables in makefiles are often used to either shorten or standardize commands. Here are a few other points of consideration while setting up makefiles:
 - Commands in makefiles are preceded by tabs, not spaces
 - Comments are preceded by a `#` and potentially spaces before that for alignment alongside commands
 - Variables are used in commands by doing `$(variable)`
 - There are typical conventions using makefiles in C and C++
    - C uses `CC` as the variable for the compiler and something like `CFLAGS` for compiler flags
    - C++ uses `CXX` as the compiler variable and something like `CXXFLAGS` for compiler flags
 - Makefiles will interpret space separated words as a list
    - Lists of files are often interpreted this way and can be manipulated in this form

Consider this example using actual commands:
```make
# Set up compiler variables
CXX := g++
# Tell compiler to compile files without attempting to link symbols
CXXFLAGS := -c

# Tell make that all is not a file name but just a command
.PHONY: all

# Use all as the main entry point while telling make to compile both dependencies first
all: dependency-one.o dependency-two.o
    # Compile program containing main along with dependency object files to ensure everything is linked
    $(CXX) main-program.cpp dependency-one.o dependency-two.o

# Compile the first dependency target that will result in a dependency-one.o file
dependency-one.o:
    # Compile only the code from dependency-one.cpp without linking it to other files
    $(CXX) $(CXXFLAGS) dependency-one.cpp

# Compile the second dependency target that will result in a dependency-two.o file
dependency-two.o:
    # Compile only the code from dependency-two.cpp without linking it to other files
    $(CXX) $(CXXFLAGS) dependency-two.cpp
```
Allow me to break this example down:
 - We have 3 targets in the makefile example of all, dependency-one.o, and dependency-two.o
    - dependency-one.o and dependency-two.o are both expected to result in a file
    - Since "all" is listed by `.PHONY`, the all target is interpreted as just a command rather than a file
       - This is important since make may get confused if you happen to have a file named *all* in the same directory
       - If a file named *all* happens to be in the same directory as the makefile, make may refuse to run thinking that the file is up to date despite us not wanting make to do anything with that file.
 - The "all" target has two target dependencies that will be executed before the commands in "all" will be run.
 - Both dependency-one.o and dependency-two.o are compiled with *g++* and its *-c* flag
    - The *-c* flag tells g++ to build just the file without attempting to reference other files
    - This allows us to compile each source file as fragments called object files (.o files) without linking them together.
 - Once the 2 dependencies are completed, "all" will run and use g++ to compile the main source file with the 2 dependency object (.o) files.
    - Note that `$(CXX) main-program.cpp dependency-one.o dependency-two.o` lacks the -c flag. This is where we will do the linking since we have all the dependencies compiled into digestible fragments.

Other points of consideration while using makefiles:
 - Targets can be called individually like running `make dependency-one.o` to only execute the dependency-one.o target. This will also include all its dependencies.
 - The first target serves as the default target, so `make` and `make all` would be equivalent with the makefile in the above example.
 - Often, there will be other command targets in make files for ease of use like *clean*

# Makefile Example
To see a proper example of how a makefile looks like, look at the [makefile](https://github.com/zsholdbrooks/cpp-reference/blob/main/makefile-mini-lesson/makefile) in this example directory. This makefile is a bit more complex and more like what you will see out on the internet. Since makefiles generally scale into much larger projects, they leverage shortcuts like patterns to make them more efficient and reusable.

I recommend stepping through the example like this:
1. If you are in the main project folder (should say something like ~/projects/cpp-reference if you went the WSL/VS Code route), do `cd makefile-mini-lesson` to enter this directory.
    - Note that running `make` will run the makefile in your current working directory
2. Run `make hello` to get a feel for how things work. You can look hello target code underneath the "Non-compilation Makefile Functionality" header. It's simple and just to illustrate that you can use terminal commands in makefiles.
3. Run `make pattern-substitution` while looking at the pattern-substitution target code to see how patterns are used in makefiles. Patterns are generally used to manipulate files according to the name's format like how C++ source files end with .cpp and header files end with the .h extension. Several makefile substitute functions are also demonstrated here.
4. Running `make demonstrate-wildcard` will show the difference between using asterisks (*) and make's wildcard operator. Using asterisks is common in cases like running `ls *.cpp` where you might want to see all the cpp files in your current directory. The asterisk just acts as a placeholder for any character and any number of characters. There are some problems with how make interprets the asterisk though, so using the wildcard operator is a more robust method.
5. Finally, run `make` or `make all` and step through each target while referencing the examples in the [section](#makefiles-from-a-technical-side) above.
    - This will actually build the project in this directory, so you can also run `./example.out` if you'd like to look through that C++ code as well.

# Automatic Variables
Automatic variables are automatically generated variables that will correspond to something like the make target `$@` or target prerequisites `$^` for each specific context. Reference the GNU makefile manual's [automatic variable cheatsheet](https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html) to interpret them as needed in makefiles.