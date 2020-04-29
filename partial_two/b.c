// (1). --------- b.c file: gcc -o b b.c  ----------
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("this is %d in %s\n", getpid(), argv[1]);
}
