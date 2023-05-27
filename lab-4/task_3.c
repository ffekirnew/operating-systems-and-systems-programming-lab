#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void task_for_child() {
  printf("Child process executing...\n");
  sleep(5);
  printf("Child process completed.\n");
}

void task_for_parent() {
  printf("Parent process executing...\n");
  sleep(2);
  printf("Parent process terminating.\n");
  exit(0); // Terminate the parent process
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
