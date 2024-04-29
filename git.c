#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h> 

int main() {
    int pipefd[2]; // Array to hold the file descriptors for both ends of the pipe
    pid_t pid;
    char buf[1024]; // Buffer to hold the data being sent through the pipe
    const char *message = "Hello from parent to child through a pipe!\n";
    // Create a pipe
    pipe(pipefd);
    // Fork a child process
    pid = fork();

    if (pid == 0) {
        // Child process
        close(pipefd[1]);  // Close the unused write end
        // Read data from pipe
        read(pipefd[0], buf, sizeof(buf));
        printf("Child received: %s", buf);
        close(pipefd[0]);  // Close the read end
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        close(pipefd[0]);  // Close the unused read end
        // Write data to pipe
        write(pipefd[1], message, strlen(message) + 1); // Include the null terminator
        close(pipefd[1]);  // Close the write end
        wait(NULL);  // Wait for the child to finish
        exit(EXIT_SUCCESS);
    }
    return 0;
}
