#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buf[1024];
    const char *baseMessage = "Hello from parent to child through a pipe! Message ";
    // Create a pipe
    pipe(pipefd); 
    // Fork a child process
    pid = fork();
    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the unused write end
        // Read data from pipe
        while (read(pipefd[0], buf, sizeof(buf)) > 0) {
            printf("Child received: %s\n", buf);
        }
        close(pipefd[0]);  // Close the read end
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(pipefd[0]);  // Close the unused read end
        // Write multiple messages to pipe
        for (int i = 1; i <= 5; i++) {
            char message[1024];
            sprintf(message, "%s%d", baseMessage, i);
            write(pipefd[1], message, strlen(message) + 1);
            sleep(1); // simulate some delay
        }
        close(pipefd[1]);  // Close the write end
        wait(NULL);  // Wait for the child to finish
        exit(EXIT_SUCCESS);
    }

    return 0;
}

