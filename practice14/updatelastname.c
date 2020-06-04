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
    char *updatedLastName = argv[2];
    int stNumber = atoi(stChar);
    if (stNumber < 0 || stNumber > 9) {
        printf("The user specified does not exist.\n");
        return 1;
    }

    Student *student;
    student = (Student *) malloc(sizeof(Student));

    if ((src = open("class.bin", O_RDWR)) < 0) {
        printf("Error creating %s file.\n", "class.bin");
        return 2;
    }

    lseek(src, sizeof(Student) * stNumber, SEEK_CUR);
    read(src, student, sizeof(Student));
    printf("Previous last name: %s\n", student-> lastName);

    sprintf(student->lastName, "%s", updatedLastName);
    for (int i = strlen(student->lastName); i < 20; i++) {
        student->lastName[i] = 0;
    }
    lseek(src, -1*sizeof(Student), SEEK_CUR);
    write(src, student, sizeof(Student));
    printf("New last name: %s\n", student-> lastName);
    close(src);
    free(student);
    return 0;
}