#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

int main()
{
    int pid = fork();
    if (pid == 0) {
        printf("Execucion del hijo\n");
        execlp("ls", "ls", "-a", "/", NULL);
    }
    else {
        printf("Soy el padre!\n");
    }
    return 0;
}