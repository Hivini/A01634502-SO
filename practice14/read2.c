#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s {
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(int argc, char **argv) {
    int src;
    char *stChar = argv[1];
    int stNumber = atoi(stChar);
    if (stNumber < 0 || stNumber > 9) {
        printf("The user specified does not exist.\n");
        return 1;
    }

    Student *student;
    student = (Student *) malloc(sizeof(Student));

    if ((src = open("class.bin", O_RDONLY)) < 0) {
        printf("Error creating %s file.\n", "class.bin");
        return 2;
    }

    lseek(src, sizeof(Student) * stNumber, SEEK_CUR);
    read(src, student, sizeof(Student));
    printf("My student is %d, %d, %s, %s\n", student->id, student->semester, student->firstName, student-> lastName);

    close(src);
    free(student);
    return 0;
}