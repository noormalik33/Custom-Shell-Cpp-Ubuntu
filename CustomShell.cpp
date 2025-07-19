#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <string>
#include <string.h> // for strtok and strcmp
#include <stdlib.h>
using namespace std;

#define MAX_ARGS 100

// Task 1: Command Execution
void parse_command(char *cmd, char **args) 
{
    int i = 0;
    args[i] = strtok(cmd, " \t\n");
  
    while (args[i] != NULL && i < MAX_ARGS - 1) 
    {
        args[++i] = strtok(NULL, " \t\n");
    }
    
    args[i] = NULL;
}

// Task 4: Advanced Functional Requirements
int parse_pipes(char *line, char **commands) 
{
    int count = 0;
    commands[count] = strtok(line, "|");
    
    // Loop to Extract Commands
	while (commands[count] != NULL && count < MAX_ARGS - 1) 
    {
        commands[++count] = strtok(NULL, "|");
    }
    
    commands[count] = NULL;
    return count;
}

// Task 1: Command Execution
void execute_single_command(char *cmd) 
{
    char *args[MAX_ARGS]; // Task 1: Command Execution
    parse_command(cmd, args); // Task 1: Command Execution

    if (args[0] == NULL) 
    {
        cerr << "No command entered.\n";
        return;
    }

    // Task 2: Process Creation and Control
    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("Fork failed");
        return;
    } 
    
    else if (pid == 0) 
    {
        execvp(args[0], args);
        
        perror("Command not found");
        exit(1);
    } 
    
    else 
    {
        waitpid(pid, NULL, 0);
    }
}

// Task 4: Advanced Functional Requirements
void execute_piped_commands(char **commands, int n) 
{
    int in_fd = 0;
    int pipe_fd[2];

    for (int i = 0; i < n; i++) 
    {
        if (pipe(pipe_fd) == -1) 
        {
            perror("Pipe creation failed");
            return;
        }

        // Task 2: Process Creation and Control
        pid_t pid = fork();
        
        if (pid < 0) 
        {
            perror("Fork failed");
            return;
        } 
        
        else if (pid == 0) 
        {
            if (dup2(in_fd, 0) == -1) 
            {
                perror("dup2 input failed");
                exit(1);
            }

            if (i < n - 1) 
            {
                if (dup2(pipe_fd[1], 1) == -1) 
                {
                    perror("dup2 output failed");
                    exit(1);
                }
            }

            close(pipe_fd[0]);
            close(pipe_fd[1]);

            char *args[MAX_ARGS];
            parse_command(commands[i], args);
  
            execvp(args[0], args);

            perror("Command not found");
            exit(1);
        } 
        
        else 
        {
            waitpid(pid, NULL, 0);
            
            // Task 4: Advanced Functional Requirements
            close(pipe_fd[1]);
            in_fd = pipe_fd[0];
        }
    }
}

// Task 3: Lifecycle Management and Termination
int main() 
{
    cout << "Welcome to MyShell! Type 'quit' to exit.\n";

    while (true) 
    {
        cout << "MyShell> ";
        string line;

        if (!getline(cin, line)) 
        {
            cout << "\nNo more input. Exiting.\n";
            break;
        }

        if (line.empty())
            continue;

        if (line == "quit") 
        {
            cout << "Goodbye!\n";
            break;
        }

        char line_cstr[1024];
        strncpy(line_cstr, line.c_str(), 1023);  
        line_cstr[1023] = '\0';                  

        char *commands[MAX_ARGS];  // Task 4: Advanced Functional Requirements
        int num_cmds = parse_pipes(line_cstr, commands);  // Task 4: Advanced Functional Requirements

        if (num_cmds == 1)   // Task 1: Command Execution
        {
            execute_single_command(commands[0]);
        }
        
        else if (num_cmds > 1) // Task 4: Advanced Functional Requirements
        {
            execute_piped_commands(commands, num_cmds);
        }
        
        else 
        {
            cerr << "Invalid command.\n";
        }
    }

    return 0;
}
