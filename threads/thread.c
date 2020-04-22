#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

int val = 5;
pthread_mutex_t mutex;
void * hello(void *id) {
    pthread_mutex_lock(&mutex);
    printf("Hello world! %ld, %d\n", (long)id, val);
    val += val;
    pthread_mutex_unlock(&mutex);
}

int main() {
    pthread_t threads[NUM_THREADS];
    for (long i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, hello, (void *) i);
    }
    pthread_exit(NULL);
}