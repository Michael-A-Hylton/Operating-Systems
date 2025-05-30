//gcc /home/michael-hylton/Desktop/Operating_Systems/project1re.c -o project1
#define _POSIX_SOURCE
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
char FullpthNameEnv[1024] = "";  // Initialize pathname environment
int isVariable;

// Function to remove a substring from a string
void removeSubStr(char *string, const char *sub) {
    printf("\nRemoving %s from %s\n", sub, string);
    char *match;
    int len = strlen(sub);
    while ((match = strstr(string, sub))) {
        memmove(match, match + len, strlen(match + len) + 1);  // Move remaining part
    }
}

// Function to handle input/output redirection
void redirectIO(char *infile, const char *outfile) {
    int inputFile, outputFile;

    // Input redirection
    if (infile != NULL) {
        inputFile = open(infile, O_RDONLY);
        if (inputFile < 0) {
            perror("Failed to open input file");
            exit(EXIT_FAILURE);
        }
        dup2(inputFile, STDIN_FILENO);
        close(inputFile);
    }

    // Output redirection
    if (outfile != NULL) {
        outputFile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outputFile < 0) {
            perror("Failed to open output file");
            exit(EXIT_FAILURE);
        }
        dup2(outputFile, STDOUT_FILENO);
        close(outputFile);
    }
}

int main() {
    isVariable = 1;
    char input[BUFFER_SIZE], currDir[256];
    char *token, *token2, *token3, *tokenize;
    char pthNameEnv[512] = "";
    char *whiteSpace = " ";

    while (isVariable) {
        getcwd(currDir, sizeof(currDir));
        printf("%s:~$ ", currDir);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Failed to read input");
            continue;
        }
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "quit") == 0) {
            printf("\nQuitting now...\n");
            isVariable = 0;
            break;
        }

        // Tokenize input
        token = strtok(input, whiteSpace);
        if (token != NULL) {
            token2 = strtok(NULL, whiteSpace);
            token3 = strtok(NULL, whiteSpace);
        }

        // Handle `cd` command
        if (strcmp(token, "cd") == 0) {
            if (token2 != NULL) {
                int chDirRes = chdir(token2);
                if (chDirRes == 0) {
                    printf("\nCurrent Directory: %s\n", getcwd(currDir, sizeof(currDir)));
                } else {
                    perror("cd failed");
                }
            } else {
                printf("cd command requires a directory argument.\n");
            }
        }

        // Handle `path` command
       else if (strcmp(token, "path") == 0) {
    if (token2 == NULL) {
        // No arguments given, display current path environment
        if (strlen(pthNameEnv) > 0) {
            printf("\nCurrent Directories: %s\n\n", pthNameEnv);
        } else {
            printf("\nCurrent Directories: (empty)\n\n");
        }
    } else if (strcmp(token2, "+") == 0) {
        // Appending a new path
        printf("\n\nAppending %s\n\n", token3);
        if (strstr(pthNameEnv, token3) == NULL) {
            strncat(pthNameEnv, token3, sizeof(pthNameEnv) - strlen(pthNameEnv) - 1);
            strncat(pthNameEnv, ":", sizeof(pthNameEnv) - strlen(pthNameEnv) - 1);
            printf("\n\nFull Path Environment: %s\n\n", pthNameEnv);
        } else {
            printf("\nPath already exists: %s\n", token3);
        }
    } else if (strcmp(token2, "-") == 0) {
        // Removing an existing path
        printf("\n\nRemoving Pathname %s\n\n", token3);
        char tempPath[BUFFER_SIZE];
        snprintf(tempPath, sizeof(tempPath), "%s:", token3);
        removeSubStr(pthNameEnv, tempPath);
        printf("New Pathname: %s\n\n", pthNameEnv);
    }
}

        // Handle I/O redirection
        else if (strchr(input, '<') || strchr(input, '>')) {
            char *inputFile = NULL, *outputFile = NULL;
            char *redirToken = strtok(input, whiteSpace);

            while (redirToken != NULL) {
                if (strcmp(redirToken, "<") == 0) {
                    inputFile = strtok(NULL, whiteSpace);
                } else if (strcmp(redirToken, ">") == 0) {
                    outputFile = strtok(NULL, whiteSpace);
                }
                redirToken = strtok(NULL, whiteSpace);
            }

            redirectIO(inputFile, outputFile);
        }

        // Handle external commands
        else {
            char *args[100];
            int i = 0;
            pid_t pid = fork();
            if (pid == 0) {
                tokenize = strtok(input, whiteSpace);
                while (tokenize != NULL) {
                    args[i++] = tokenize;
                    tokenize = strtok(NULL, whiteSpace);
                }
                args[i] = NULL;

                char *oneDirectory = strtok(pthNameEnv, ":");
                while (oneDirectory != NULL) {
                    char path[BUFFER_SIZE];
                    snprintf(path, sizeof(path), "%s/%s", oneDirectory, args[0]);
                    printf("Trying path: %s\n", path);  // Debugging statement
                    execv(path, args);
                    oneDirectory = strtok(NULL, ":");
                }
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            } else if (pid > 0) {
                int status;
                waitpid(pid, &status, 0);
            } else {
                perror("Failed to fork");
            }
        }

        // Maintain the full path name environment
        strncat(FullpthNameEnv, pthNameEnv, sizeof(FullpthNameEnv) - strlen(FullpthNameEnv) - 1);
    }

    return 0;
}
