#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int shmId = shmget(400, 100, 0644 | IPC_CREAT);
    int childs[5];
    for (int i = 0; i < 5; i++) {
        int pid = fork();
        childs[i] = pid;
        if (pid != 0) {
            shmId = shmget(400, 100, 0644);
            int *nums = (int *)shmat(shmId, NULL, 0);
            nums = &nums[i * 10];
            for (int j = 0; j < 10; j++) {
                nums[j] = i + '0';
            }
            return 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        waitpid(childs[i], 0, 0);
    }
    int *nums = (int *) shmat(shmId, NULL, 0);
    printf("Contenido de nums %d\n", *nums);
    return 0;
}