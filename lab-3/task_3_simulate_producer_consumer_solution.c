#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 20 // Size of the shared buffer

int buffer[BUFFER_SIZE]; // Shared buffer
int count = 0;           // Number of items in the buffer

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;       // Mutex for buffer access
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for the producer
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for the consumer

void *producer_thread() {
  for (int i = 0; i < 100; i++) {
    pthread_mutex_lock(&mutex); // Acquire the lock

    // Wait if the buffer is full
    while (count == BUFFER_SIZE)
      pthread_cond_wait(&producer_cond, &mutex);

    // Add an item to the buffer
    buffer[count] = i;
    count++;

    printf("Producer produced item: %d\n", i);

    // Signal the consumer to wake up
    if (count == 1)
      pthread_cond_signal(&consumer_cond);

    pthread_mutex_unlock(&mutex); // Release the lock

    sleep(1);
  }

  return NULL;
}

void *consumer_thread() {
  for (int i = 0; i < 100; i++) {
    pthread_mutex_lock(&mutex); // Acquire the lock

    // Wait until if buffer is empty
    while (count == 0)
      pthread_cond_wait(&consumer_cond, &mutex);

    // Remove an item from the buffer
    int item = buffer[count - 1];
    count--;

    printf("Consumer consumed item: %d\n", item);

    // Signal the producer to wake up
    if (count == BUFFER_SIZE - 1)
      pthread_cond_signal(&producer_cond);

    pthread_mutex_unlock(&mutex); // Release the lock

    sleep(1);
  }

  return NULL;
}

int main() {
  pthread_t producer_thread_id, consumer_thread_id;

  // Create the producer thread
  if (pthread_create(&producer_thread_id, NULL, producer_thread, NULL) != 0) {
    printf("Failed to create the producer thread.\n");
    return 1;
  }

  // Create the consumer thread
  if (pthread_create(&consumer_thread_id, NULL, consumer_thread, NULL) != 0) {
    printf("Failed to create the consumer thread.\n");
    return 1;
  }

  // Wait for the threads to finish
  pthread_join(producer_thread_id, NULL);
  pthread_join(consumer_thread_id, NULL);

  return 0;
}
