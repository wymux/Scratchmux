#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ITERATION 1000000000
#define NUM_THREADS 8

double pi = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *calculate_pi(void *thread_id) {
    long id = (long) thread_id;
    double local_pi = 0;
    short int sign = id % 2 ? 1 : -1;

    for (unsigned int i = id; i < ITERATION; i += NUM_THREADS) {
        local_pi += (sign / (2.0 * i + 1));
        sign = -sign;
    }

    local_pi *= 4;
    
    pthread_mutex_lock(&mutex);
    pi += local_pi;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    for (long i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, calculate_pi, (void *) i);
        if (rc) {
            printf("Error creating thread %ld\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    fprintf(stdout, "%.15f\n", pi);

    return 0;
}
