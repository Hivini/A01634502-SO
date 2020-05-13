#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

// Practica 11
int main(int argc, char **argv) {
    int origin, destination, line, readLine, writeLine;
    char buffer[512];
    char *originFilename = argv[1];
    char *dstFilename = argv[2];
    printf("%s %s\n", originFilename, dstFilename);

    if ((origin = open(originFilename, O_RDONLY)) < 0) {
        printf("The file %s doesn't exist of it's corrupted.\n", originFilename);
        return 1;
    }

    if ((destination = creat(dstFilename, 0666)) < 0) {
        printf("Error creating %s file.\n", dstFilename);
        return 2;
    }

    while((readLine = read(origin, buffer, sizeof(buffer))) != 0) {
        if (readLine < 0) {
            printf("Error reading the %s file.\n", originFilename);
            return 3;
        }
        writeLine = 0;
        do {
            if ((line = write(destination, &buffer[writeLine], readLine - writeLine)) < 0) {
                printf("Error writing to the file %s\n", dstFilename);
                return 4;
            }
            writeLine += line;
        } while (writeLine < readLine);
    }
    close(origin);
    close(destination);
}
