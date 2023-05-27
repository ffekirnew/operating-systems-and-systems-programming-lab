#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

int counter = 0; // Global counter variable

void *thread_task() {
  for (int i = 0; i < 10; i++) {
    printf("\n Thread Global counter (shared variable) = %d", counter); // Print the current value of the global counter
    
    counter++; // Increment the global counter
    //
    printf("\n Thread Local counter i = %d, Thread ID = %lu", i, pthread_self());
    // Print the local counter value and thread ID
    
    sleep(1); // Pause execution for 1 second
  }
  printf("\n"); // Print a new line
  return 0;
}

int main() {
  pthread_t my_thread_desc;  // Variable to hold thread descriptor
  int my_thread_status;     // Variable to hold thread creation status
  
  my_thread_status = pthread_create(&my_thread_desc, NULL, thread_task, NULL);
  // Create a new thread using pthread_create function
  // Pass the thread descriptor variable, NULL (default thread attributes),
  // the function to be executed by the thread (thread_task), and NULL as arguments
  
  if (my_thread_status == 0) {
    printf("Thread created successfully. \n");
  } else {
    printf("Unable to create thread \n");
  }

  for (int i = 0; i < 10; i++) {
    printf("\n Main global counter = %d", counter);
    // Print the current value of the global counter
    
    counter++; // Increment the global counter
    printf("\n Main local counter i = %d, my ID = %lu", i, pthread_self());
    // Print the local counter value and thread ID
    
    sleep(1); // Pause execution for 1 second
  }

  printf("\n"); // Print a new line
  return 0;
}
