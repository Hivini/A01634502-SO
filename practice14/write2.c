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

    Student *students[10];
    for (int i = 0; i < 10; i++) {
        students[i] = (Student *) malloc(sizeof(Student));
        students[i]->id = i;
        students[i]->semester = 2;
        sprintf(students[i]->firstName, "%s%d", "Test", i + 1);
        sprintf(students[i]->lastName, "%s%d", "Student", i + 1);
    }

    if ((destination = creat(fileName, 0600)) < 0) {
        printf("Error creating %s file.\n", fileName);
        return 2;
    }

    for (int i = 0; i < 10; i++) {
        if (write(destination, students[i], sizeof(Student)) < 0) {
            printf("Error writing to the file %s\n", fileName);
            return 4;
        }
    }

    close(destination);
    for (int i = 0; i < 10; i++) {
        free(students[i]);
    }
    return 0;
}