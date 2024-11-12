#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd = open("fifo6.txt", O_WRONLY);
    int fd2 = open("fifo7.txt", O_RDONLY);
    if(fd == -1 || fd2 == -1) {
        perror("FIFO open failed");
        return 1;
    }

    char message[5000];
    while(1) {
        printf("Enter message: ");
        fgets(message, sizeof(message), stdin);

        int len = strlen(message);
        write(fd, &len, 1);
        write(fd, message, len);

        read(fd2, &len, 1);
        read(fd2, message, len);
        message[len] = '\0';
        printf("Processed: %s\n", message);
    }

    close(fd);
    close(fd2);
    return 0;
}
