#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2
#define NUM_INCREMENTS 1000000
// Shared variable
int counter = 0;
// Function executed by each thread to increment the counter
void *increment(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        counter++; // Increment the counter
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    // Display the final value of the counter
    printf("Final counter value: %d\n", counter);
    return 0;
}
