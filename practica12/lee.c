#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int arg, char **argv) { 
    char *fileName = argv[1];
    char buffer;
    int fd = open(fileName, O_RDONLY);
    if (fd < 0) {
        printf("The file cannot be opened\n");
        exit(1);
    }
    while(read(fd, &buffer, 1)) {
        printf("%c", buffer);
    }
    printf("\n");
    close(fd);
    exit(0);
}
