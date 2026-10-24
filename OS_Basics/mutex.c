#include <stdio.h>
#include <pthread.h>

long counter = 0;
pthread_mutex_t lock;

void* count_cycles(void* arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1, NULL, count_cycles, NULL);
    pthread_create(&t2, NULL, count_cycles, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final synchronized counter value: %ld\n", counter);
    pthread_mutex_destroy(&lock);
    return 0;
}
