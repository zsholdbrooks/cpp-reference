# Hello World C++ Program
*If you want to just jump in without explanation, jump to the [simplified instructions](#i-dont-know-what-to-do-in-windows-im-confused-just-tell-me-what-to-do)*.

Unfortunately, this is one of the hardest and easiest steps in beginning to program any language, particularly with C or C++ given the nature of both languages. Just getting to being able to compile and run the basic "Hello World" program can be frustrating due to the amount of setup necessary for success.

C++ is a compiled programming requiring a developer tool called a "compiler" to run C++ code on your machine. This is in contrast to languages like Python (where you can run the code directly with the Python shell) and Java (which is both compiled and interpreted). Essentially, you cannot do something like `run hello-world.cpp` with your [hello-world.cpp](https://github.com/zsholdbrooks/cpp-reference/tree/main/hello-world/hello-world.cpp) file like in Python with `python hello-world.py`. C++ cannot be run directly since your computer's internal components can't just directly interpret your written words. The compiler program works as a translator so that it can take C++ code and recreate it in a format that your computer does understand.

Which compiler is used for C++ is up for some debate, but the most common is **g++**. Since g++ was not originally developed for Windows, the compiler is generally installed via MinGW or a couple of other indirect options. Sometimes, a compiler is installed alongside an Integrated Development Environment (IDE) like Visual Studio (not VS Code) and Visual C++ (a different compiler). For simplicity, I recommend installing Visual Studio Code and using Windows Subshell for Linux (WSL). Visual Studio Code is a simple and lightweight code editor that doesn't stress hard on project files like other IDEs.

Windows Subshell for Linux (WSL) enables you to use true Linux functionality on a Windows desktop without more complicated measures like VMs or installing a second OS. WSL is developed directly by Microsoft with growing efforts to improve its capabilities consistently over time. While it is not identical to a dedicated Linux computer, it is a very good option for cases like this. Since both VS Code and WSL are developed by Microsoft, there is an extension within VS Code that link the two together enabling easier development.

***tldr; C++ needs a program called a compiler to run your code. An IDE is essential for coding and should be used as well. I recommend using Visual Studio Code and WSL Ubuntu for beginning C++ development.***

------------------------------------------

## Prerequisites:
 - Have a usable console/terminal
    - Examples are *Bash* in Linux, *Ubuntu on Windows* on Windows (really just Bash in disguise), or *Powershell*/*Command Prompt* in Windows
    - (Recommended) Install WSL and use Ubuntu on Windows
 - The g++ compiler is installed
    - Compiler installation tends to be the most difficult part and is discussed below in its own section
 - Install an IDE
    - I recommend [Visual Studio Code](https://code.visualstudio.com/) by Microsoft. Installation is simple. There are further steps for VS Code recomended below.

------------------------------------------

## (Recommended) Install WSL and use Ubuntu
1. Go to Windows Start Menu, type in `powershell`, right click `Windows Powershell`, and select `Run as Administrator`.
2. Run `wsl --install -d Ubuntu` to prompt Windows to install WSL 2 and Ubuntu. Once it (hopefully) successfully installs, restart your computer.
3. When your computer has restarted, type in `ubuntu` in the Windows Start Menu and select the `Ubuntu` or `Ubuntu on Windows` app to open your Ubuntu Terminal.
    - Might want to right click it and pin it to the taskbar for easy access. 
4. Do setup steps it asks for initial setup like username and password. These will be different than your Windows username and password since it acts like a different Operating System.
5. Run `sudo apt-get install g++ make` and accept installation prompts.

### Setting Up WSL Environment within VS Code

1. Install Microsoft's [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) that includes C++ syntax parsing and WSL Remote Development
    - Click `Install` on the webpage, `Continue` on the first prompt, `Open in Visual Studio Code` on the browser prompt, and `Install` on the extension page that is shown in VS Code.
    - Note that you may need to close VS Code to allow certain extensions to install and load.
2. Open new instance of `Ubuntu on Windows` by either searching for it in the start menu or selecting the pinned program on the taskbar (if you optionally did this)
    - Upon opening the Ubuntu terminal, it will always place you within your user home directory. You will see this on the command line with something along the lines of `user@computer:~` where `~` is a shorthand for the directory path of your home.
3. Create a new directory for your code projects in your home folder and cd into it by running `mkdir projects && cd projects`
    - This is like creating a new folder in Windows file explorer and clicking on it to enter the folder/directory.
    - `mkdir` creates a new folder (makes a new directory) in your current working directory which is `~` at the moment
    - `cd` will change your directory to where you are working inside the directory/folder specified
    - `&&` glues the two commands together and runs them consecutively
4. Clone main directory by running `git clone https://github.com/zsholdbrooks/cpp-reference.git`
    - This downloads the full project to a new directory of `cpp-reference`
5. Open the C++ project by running `code cpp-reference`
    - Running this command uses the "Remote - WSL" VS Code plugin installed from the first step. It opens the cpp-reference directory within a new instance of VS Code.
6. Open the terminal window in VS Code by either functionally identical option below:
    - Option 1: Pressing the `Ctrl`, `Shift`, and `~` keys together (also seen as `Ctrl + Shift + ~`)
    - Option 2: Selecting the `Terminal` tab at the very top then select the `New Terminal` option
    - Note: This terminal is the same as a standalone *Ubuntu on Windows* terminal but just accessible inside VS Code.
7. Change into the `hello-world` folder of the project by running `cd hello-world`
    - The directory path inside the VS Code terminal prior to this command should be something like `~/projects/cpp-reference` since you opened the cpp-reference directory with VS Code despite not doing a deliberate *cd* into the directory.
8. Click on the `hello-world.cpp` file on the left section to open and look at the program's code.
    - You should have the `Explorer` tab open in VS Code on the left already. If not, click on the first icon at the far top left that looks like a piece of paper with a corner folded. You can hover over it with your cursor to see it say `Explorer` as well.
9. Compile the [hello-world.cpp](https://github.com/zsholdbrooks/cpp-reference/tree/main/hello-world/hello-world.cpp) code by running `g++ hello-world.cpp -o hello-world.out`
10. Finally, run the compiled program with `./hello-world.out` to see **Hello World!** displayed on the terminal window.
    - Note: Whenever you run a new compiled program in a folder, you must prefix it with `./` or else the terminal will try to look in another place instead of your current folder. Because of this, it will likely say `Command not found` if you forget the `./`
11. Once you are done looking at the code, you can run `cd ..` to go up a folder to the main project folder. Enjoy.

Good references
 - [Canonical's WSL Ubuntu Installation Guide](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-10#1-overview)
 - [Microsoft's WSL Installation Guide](https://docs.microsoft.com/en-us/windows/wsl/install#check-which-version-of-wsl-you-are-running)
 - [Microsoft's WSL Development Article](https://docs.microsoft.com/en-us/windows/wsl/setup/environment)

------------------------------------------

## Other Compiler Installation Methods
 - You can check if g++ is installed by running `g++ --version` in the console. It should give some kind of blurb about the OS and compiler version with open source license information. If it displays an error, g++ is not installed.
 - Install in `Ubuntu/Linux` or using `Ubuntu on Linux with WSL`
    - Run `sudo apt-get install g++ make` and accept installation prompts.
    - If installation fails, run `sudo apt-get update && sudo apt-get upgrade` and attempt installation command again. If g++ installation still fails, try Googling the error message and work from there.
 - Install in `Windows`:
    - (Recommended) If using `Ubuntu on Windows` and WSL, refer to Ubuntu installation instructions above 
    - Follow [Microsoft's VS Code MingW Guide](https://code.visualstudio.com/docs/cpp/config-mingw) to install Linux developer tools including the g++ compiler in Windows.
       - MinGW ends up being a port of the popular Linux developer tools to Windows.
    - Cygwin can also be installed, but MinGW is typically recommended.
       - Basically, Cygwin is an emulated Linux shell running on top of Windows.

------------------------------------------

## "I don't know what to do in Windows. I'm confused. Just tell me what to do!"
1. Press the `Windows Key`, start typing in `powershell` to start a program search, and select `Run as Administrator` on the start menu's right side window.
2. Run (type in highlighted text and hit the Enter key) `wsl --install -d Ubuntu` in Windows Powershell
3. Restart your computer when it finishes
4. Install [Visual Studio Code](https://code.visualstudio.com/)
5. Install [C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) as an add-on for VS Code
    - Click `Install` on the webpage, `Continue` on the first prompt, `Open in Visual Studio Code` on the browser prompt, and `Install` on the extension page that is shown in VS Code.
6. Press `Windows Key`, type in `ubuntu` and select program named `Ubuntu on Windows` (or it may just be `Ubuntu`)
7. Follow the prompts it gives you by typing in your responses and hitting `Enter`
8. Once Ubuntu is set up, run `sudo apt-get install g++ make` and accept installation prompts
9. Copy the full command block below, right click the Ubuntu window (Ubuntu doesn't accept `Ctrl + V` pastes), and hit `Enter`
     ```
     mkdir projects && git clone https://github.com/zsholdbrooks/cpp-reference.git projects/cpp-reference && code projects/cpp-reference
     ```
10. In the new VS Code window, select the `Terminal` tab at the very top then select the `New Terminal` option
11. Copy the below code block and right click the center of the terminal window in VS Code
    - You may need to click the bottom Terminal window to type in commands if you accidentally clicked elsewhere. It changes into hello-world folder and compiles the program.
    ```
    cd hello-world && g++ hello-world.cpp -o hello-world.out
    ```
12. Click on the `hello-world.cpp` file on the left section to open and look at the program's code that you just compiled.
    - You should have the `Explorer` tab open in VS Code on the left already. If not, click on the first icon at the far top left that looks like a piece of paper with a corner folded. You can hover over it with your cursor to see it say `Explorer` as well.
13. Run `./hello-world.out` in the Terminal window below to actually execute the program. You should see `Hello World!` appear in the terminal after running it.
    - Note: Whenever you run a new compiled program in a folder, you must prefix it with `./` or else the terminal will try to look in another place instead of your current folder. Because of this, it will likely say `Command not found` if you forget the `./`
14. Once you are done looking at the code, you can run `cd ..` to go up a folder to the main project folder. Enjoy.