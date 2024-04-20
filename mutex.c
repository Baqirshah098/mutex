#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2
#define NUM_INCREMENTS 1000000
// Shared variable
int counter = 0;
// Mutex lock
pthread_mutex_t lock;
// Function executed by each thread to increment the counter
void *increment(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        // Lock the mutex before accessing the counter
        pthread_mutex_lock(&lock);
        counter++; // Increment the counter
        // Unlock the mutex after accessing the counter
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    // Initialize the mutex lock
    pthread_mutex_init(&lock, NULL);
    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Final counter value: %d\n", counter);

    return 0;
}
