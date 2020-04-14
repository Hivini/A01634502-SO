#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void processSignal(int s) {
    printf("Received signal %d\n", s);
}

void notKill(int s) {
    printf("Cannot kill me this way, try kill -9\n");
}

int main() {
    signal(10, processSignal);
    signal(15, notKill);
    while(1) {
        sleep(3);
        printf("Working...\n");
    }
    return 0;
}