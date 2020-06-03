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

int main() {
    int src;

    Student *student;
    student = (Student *) malloc(sizeof(Student));

    if ((src = open("class.bin", O_RDWR)) < 0) {
        printf("Error creating %s file.\n", "class.bin");
        return 2;
    }

    read(src, student, sizeof(Student));
    printf("My student is %d, %d, %s, %s\n", student->id, student->semester, student->firstName, student-> lastName);

    sprintf(student->lastName, "%s>%d", "Santos", 2);
    for (int i = strlen(student->lastName); i < 20; i++) {
        student->lastName[i] = 0;
    }
    printf("%s", student->lastName);
    
    lseek(src, -1*sizeof(Student), SEEK_CUR);
    write(src, student, sizeof(Student));

    close(src);
    free(student);
    return 0;
}