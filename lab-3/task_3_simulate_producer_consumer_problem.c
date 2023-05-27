#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

// Common code (producer and consumer must agree on the buffer to be used)
#define BUFFER_SIZE 20

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
pthread_cond_t producer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for the producer
pthread_cond_t consumer_cond = PTHREAD_COND_INITIALIZER; // Condition variable for the consumer

// Producer logic
void *produce() {
  int next_produced;

  for (next_produced = 0; next_produced < BUFFER_SIZE; next_produced++) {
    while ((in + 1) % BUFFER_SIZE == out); // do nothing
 
    printf("Producer produced item: %d\n", next_produced);

    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
    
    if (out != in)
      pthread_cond_signal(&consumer_cond);
    
    sleep(1);
  }

  return NULL;
}

// Consumer logic
void *consume() {
  int next_consumed;

  while (true) {
    while (in == out);

    next_consumed = buffer[out];
    printf("Consumer consumed item: %d\n", next_consumed);
    out = (out + 1) % BUFFER_SIZE;

    if (in - out == BUFFER_SIZE - 1)
      pthread_cond_signal(&producer_cond);

    sleep(1);
  }

  return NULL;
}


int main(int argc, char *argv[]) {
  pthread_t producer_thread_id;
  pthread_t consumer_thread_id;

  if (pthread_create(&producer_thread_id, NULL, produce, NULL) != 0) {
    printf("Failed to create the producer thread.\n");
    return 1;
  }

  // Create the consumer thread
  if (pthread_create(&consumer_thread_id, NULL, consume, NULL) != 0) {
    printf("Failed to create the consumer thread.\n");
    return 1;
  }

  pthread_join(producer_thread_id, NULL);
  pthread_join(consumer_thread_id, NULL);

  return 0;
}
