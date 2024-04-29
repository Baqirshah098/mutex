#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[1024];
    // Open FIFO for read only
    fd = open(myfifo, O_RDONLY);
    // Read data from FIFO
    read(fd, buf, sizeof(buf));
    // Print the read message
    printf("Received: %s\n", buf);
    // Close FIFO
    close(fd);
    return 0;}
