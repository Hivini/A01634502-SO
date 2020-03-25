#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main()
{
    int pid = fork();
    if (pid == 0) {
        printf("Soy el hijo!\n");
    }
    else {
        printf("Soy el padre!\n");
        printf("Child pid %d\n", pid);
    }
    return 0;
} 