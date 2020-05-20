#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int arg, char **argv) {
    uint lineCount = 0, wordCount = 0, charCount = 0;
    char *fileName = argv[1];
    char buffer;
    char whitespace = 0;
    int fd = open(fileName, O_RDONLY);

    if (fd < 0) {
        printf("The file cannot be opened\n");
        exit(1);
    }

    while(read(fd, &buffer, 1)) {
        charCount++;
        if (buffer == '\n') {
            lineCount++;
        }
        if ((buffer == ' ' || buffer == '\n' || buffer == EOF) && whitespace == 0) {
            whitespace = 1;
            wordCount++;
        } else if (buffer != ' ' && buffer != '\n' && buffer != EOF) {
            whitespace = 0;
        }
    }
    
    close(fd);
    printf("Line Count: %d\tWord Count: %d\tcharCount: %d\tFile: %s\n", lineCount, wordCount, charCount, fileName);
    exit(0);
}