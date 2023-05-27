#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void task_for_child() {
  for (int i = 1; i <= 10; i += 2) {
    printf("Child: %d\n", i);
    sleep(1);
  } 
}

void task_for_parent() {
  //  wait(NULL); // Wait for the child process to complete

  for (int i = 2; i <= 10; i += 2) {
    printf("Parent: %d\n", i);
    sleep(1);
  }
}

int main() {
  int pid = fork();

  if (pid == 0) {
    task_for_child();
  } else {
    task_for_parent();
  }

  return 0;
}
