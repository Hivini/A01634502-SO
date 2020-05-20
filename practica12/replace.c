#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int arg, char **argv) {
    char *searchWord = argv[1];
    char *replaceWord = argv[2];
    char *fileName = argv[3];
    char word[100];
    int i = 0;
    char character;
    char whitespace;

    int fd = open(fileName, O_RDONLY);
    if (fd < 0) {
        printf("The file cannot be opened\n");
        exit(1);
    }

    while(read(fd, &character, 1)) {
        if ((character == ' ' || character == '\n' || character == EOF) && whitespace == 0) {
            whitespace = 1;
            word[i] = '\0';
            i = 0;
            if (strcmp(word, searchWord) == 0) {
                printf("%s \n", replaceWord);
            } else {
                printf("%s \n", word);
            }
            
        } else if (character != ' ' && character != '\n' && character != EOF) {
            whitespace = 0;
            word[i++] = character;
        }
    }
    word[i] = '\0';
    printf("%s \n", word);
    close(fd);
    exit(0);
}