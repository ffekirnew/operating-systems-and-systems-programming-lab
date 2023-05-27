#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void task_for_child() {
  printf("Child process:\n");
  printf("\tPID: %d\n", getpid());
  printf("\tParent PID: %d\n", getppid());

  sleep(10); // Let the child process stay longer
}

void task_for_parent() {
  wait(NULL); // Wait for the child process to complete

  printf("Parent process:\n");
  printf("\tPID: %d\n", getpid());
  printf("\tParent PID: %d\n", getppid());

  sleep(10); // Let the parent process stay longer
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
