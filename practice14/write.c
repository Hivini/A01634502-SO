#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s {
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main() {
    int destination;
    char *fileName = "class.bin";

    Student *student;
    student = (Student *) malloc(sizeof(Student));
    student->id = 20;
    student->semester = 2;
    sprintf(student->firstName, "%s", "Vinicio");
    sprintf(student->lastName, "%s", "Quintero");

    if ((destination = creat(fileName, 0600)) < 0) {
        printf("Error creating %s file.\n", fileName);
        return 2;
    }

    if (write(destination, student, sizeof(Student)) < 0) {
        printf("Error writing to the file %s\n", fileName);
        return 4;
    }
    close(destination);
    free(student);
    return 0;
}