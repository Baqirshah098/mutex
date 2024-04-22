#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_INCREMENTS 1000000
int counter = 0;
void *increment(void *arg) {
    int tid = *((int *)arg);
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        counter++; // Increment the counter
    }
    printf("Thread %d completed. Final counter value: %d\n", tid, counter);
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment, &thread_ids[i]);
    }
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Final counter value: %d\n", counter);

    return 0;
}
