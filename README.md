# Custom-Shell-Cpp-Ubuntu
A custom Linux shell implemented in C++ for Ubuntu, showcasing OS concepts like process creation, process control, and inter-process communication (IPC) with support for command execution, parameters, and pipelined commands.

Custom Shell in C++ 🖥️🚀
Overview 🌟
This project implements a custom command-line shell in C++, designed to emulate core functionalities of a Unix-like shell. The shell demonstrates fundamental operating system concepts, including process creation, process control, and inter-process communication (IPC). It provides a user-friendly interface for executing commands, supports pipelining, and ensures robust error handling and graceful termination. 🛠️💻
Project Description 📖✨
Overview 🌐
The Custom Shell in C++ is a powerful command-line interface (CLI) that mirrors the functionality of Unix-like shells, serving as both a practical tool and an educational showcase of operating system principles. Built with POSIX system calls, it handles command execution, process management, and inter-process communication with efficiency and clarity. The shell presents a custom myshell> prompt, allowing users to input commands ranging from simple utilities (e.g., ls, date) to complex pipelines (e.g., ls | sort | wc). It runs persistently until the user issues the quit command, ensuring a controlled exit with proper resource cleanup. 🚀🔧
Purpose and Motivation 🎯🔍
This project aims to bridge theoretical operating system concepts with practical implementation. Shells are the heart of user interaction in Unix-like systems, translating commands into system operations. By developing this shell, the project explores:

Process Management 🛠️: Creating isolated child processes using fork() and execvp().
Inter-Process Communication 🔗: Enabling data flow through pipelines with pipe() and dup2().
Command Parsing ✂️: Tokenizing input to extract commands, arguments, and operators.
Error Handling 🛡️: Ensuring robust responses to invalid inputs and system failures.

It serves as an educational tool, a development sandbox, and a portfolio piece, demonstrating proficiency in system programming and C++. 📚💪
Architecture and Implementation 🏗️⚙️
The shell is built in C++ with a modular design, leveraging POSIX system calls for portability across Unix-like systems (e.g., Linux, macOS). Its core components include:

Command Parsing 📜✂️:

Reads input via fgets() and tokenizes it with strtok() to separate commands, arguments, and pipeline operators (|).
Supports up to 16 arguments and two pipes per command.
Validates input to handle empty commands and detect quit for termination. ✅


Process Creation and Execution 🔄🚀:

Uses fork() to spawn child processes and execvp() to execute commands in isolated contexts.
The parent process synchronizes with children using waitpid() for sequential execution. ⏱️
Supports commands with arguments (e.g., ls -l /tmp) via dynamic argument arrays.


Pipelining 🔗🌊

Implements pipelines using pipe() for unidirectional IPC and dup2() to redirect standard input/output.
For example, in ls | wc, ls output is piped to wc input via file descriptors.
Manages multiple child processes for multi-stage pipelines (e.g., ls | sort | wc). 🔄


Error Handling and Robustness 🛡️🚨:

Checks system call failures (e.g., fork(), pipe(), execvp()) and reports errors with perror().
Handles invalid commands gracefully, ensuring the shell remains operational. 🔄
Closes unused pipe descriptors to prevent resource leaks. 🧹


Termination 🛑:

Runs in a continuous loop, accepting commands until quit is entered.
Exits cleanly with a farewell message, releasing all resources. 🎉



Key Features 🌟🔥

Command Execution 📜: Supports standalone commands (e.g., ls, date) and commands with arguments (e.g., ls -l, cp source dest). ✅
Pipelining 🔗: Handles single and multi-stage pipelines (e.g., ls | wc, ls | sort | wc). 🌊
Process Isolation 🛡️: Runs each command in a separate process for stability.
User-Friendly Interface 🖥️: Clear myshell> prompt and intuitive command flow.
Robust Error Handling 🚨: Manages invalid inputs and system errors effectively.
Controlled Termination 🛑: Exits gracefully on quit with resource cleanup.

Technical Specifications 📋⚙️

Language: C++ (Standard C++11 or later) 🖌️
System Calls: fork(), execvp(), pipe(), dup2(), waitpid(), close(), perror() 🔧
Input Limits:
Maximum input length: 256 characters 📏
Maximum arguments per command: 16 🔢
Maximum pipeline stages: 3 (2 pipes) 🔗


Dependencies: POSIX-compliant environment, Standard C++ Library 📚
Operating Systems: Unix-like (e.g., Linux, macOS) 🐧

Significance and Use Cases 📈🌍
This shell is valuable for:

Education 🎓: Teaches process management, IPC, and system programming concepts.
Development 🛠️: Provides a platform for testing command execution and pipelines.
Portfolio 💼: Showcases C++ and system programming skills for academic or professional purposes.
Extensibility 🚀: Serves as a foundation for advanced shell features like redirection or job control.

It offers insights into the inner workings of shells like bash or zsh, making it a powerful learning and development tool. 🌐
Limitations and Future Enhancements ⚠️🚀

Current Limitations:
Supports only two pipes per command. 🔗
No built-in commands (e.g., cd, exit). 🛠️
Lacks redirection (>, <) and background execution (&). 📥
Input and argument limits restrict complex commands. 📏


Planned Enhancements:
Add built-in commands (e.g., cd, export). ✅
Implement redirection and background processes. 📤
Support unlimited pipeline stages. 🔗
Introduce command history and tab completion. ⌨️
Optimize memory and error handling. 🧹



Requirements 🛠️📋

Operating System: Unix-like (Linux, macOS, etc.) 🐧
Compiler: g++ (C++11 or later) 🖌️
Dependencies: Standard C++ library, trà POSIX system calls (e.g., unistd.h, sys/wait.h) 📚

Installation 📦🔧

Clone or download the repository:git clone <repository-url>
cd custom-shell


Compile the source code:g++ -o myshell myshell.cpp


Run the shell:./myshell



Usage 🎮🚀

Launch the shell with ./myshell. 🖥️
At the myshell> prompt, enter commands:
Simple commands: ls, date, pwd 📜
Commands with arguments: ls -l, cp file1 file2 ✅
Pipelined commands: ls | wc, ls | sort | wc 🔗


Exit with quit. 🛑

Example Commands
myshell> ls
myshell> ls -l | wc
myshell> cat file.txt | sort | uniq
myshell> quit

Contributing 🤝🌟
Contributions are welcome! Submit a pull request or open an issue to propose improvements or report bugs. Let’s make this shell even better! 🚀
Contact 📬✨
For questions, feedback, or collaboration, reach out to:

Email: noormalik56500@gmail.com ✉️
LinkedIn: https://www.linkedin.com/in/noormalik56500/ 🔗

Acknowledgments 🙏🎉
This shell was developed to demonstrate operating system concepts, inspired by Unix shell principles and POSIX system calls. Thank you to the open-source community for inspiration and resources! 🌍
