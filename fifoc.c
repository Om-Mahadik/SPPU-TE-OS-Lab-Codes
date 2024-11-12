#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("fifo6.txt", O_RDONLY);
    int fd2 = open("fifo7.txt", O_WRONLY);
    if(fd == -1 || fd2 == -1) {
        perror("FIFO open failed");
        return 1;
    }

    char buffer[5000];
    while(1) {
        int len;
        read(fd, &len, 1);
        read(fd, buffer, len);
        buffer[len] = '\0';
        printf("Received: %s\n", buffer);

        int words = 0, lines = 0;
        for(int i = 0; buffer[i]; i++) {
            if(buffer[i] == ' ' || buffer[i] == '\n') words++;
            if(buffer[i] == '\n') lines++;
        }

        snprintf(buffer, sizeof(buffer), "Words: %d, Lines: %d", words, lines);
        write(fd2, &len, 1);
        write(fd2, buffer, strlen(buffer) + 1);
    }

    close(fd);
    close(fd2);
    return 0;
}
