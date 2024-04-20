#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 2
#define NUM_INCREMENTS 1000000

int counter = 0;
void *increment(void *arg) {
    for (int i = 0; i < NUM_INCREMENTS; i++) {
        counter++; // Increment the counter without synchronization
    }
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];

    clock_t start_without_mutex_and_threads = clock();

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, increment, NULL);
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_t end_without_mutex_and_threads = clock();

    double time_without_mutex_and_threads = ((double)(end_without_mutex_and_threads - start_without_mutex_and_threads)) / CLOCKS_PER_SEC;

    printf("Execution time without mutex : %f seconds\n", time_without_mutex_and_threads);

    return 0;
}
