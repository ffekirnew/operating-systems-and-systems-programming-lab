#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

sem_t empty, full, mutex;

void* producer(void* arg) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        item = i + 1;

        sem_wait(&empty);  // Wait for an empty slot in the buffer
        sem_wait(&mutex);  // Acquire the mutex to protect the buffer

        buffer[in] = item;
        printf("Producer produced item: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);  // Release the mutex
        sem_post(&full);   // Signal that the buffer is no longer empty
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;

    for (int i = 0; i < NUM_ITEMS; i++) {
        sem_wait(&full);   // Wait for a filled slot in the buffer
        sem_wait(&mutex);  // Acquire the mutex to protect the buffer

        item = buffer[out];
        printf("Consumer consumed item: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);  // Release the mutex
        sem_post(&empty);  // Signal that the buffer is no longer full
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}
