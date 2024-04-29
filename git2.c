#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    // Open FIFO for write only
    fd = open(myfifo, O_WRONLY);
// Write data to FIFO
    const char *data = "Hello, FIFO!";
    write(fd, data, strlen(data)+1);
    // Close FIFO
    close(fd);
    return 0;}
