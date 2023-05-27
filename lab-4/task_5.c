#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void task_for_child() {
  for (int i = 1; i <= 10; i += 2) {
    printf("Child: %d\n", i);
    sleep(1);
  }
}

void task_for_parent(int pid) {
  //  wait(NULL); // Wait for the child process to complete

  printf("Parent process executing...\n");
  sleep(3);
  printf("Killing the child process now.\n");
  kill(pid, SIGQUIT);
  printf("Child process is killed, successfully. Now terminating.\n");
}

int main() {
  int pid = fork();

  if (pid == 0) {
    task_for_child();
  } else {
    task_for_parent(pid);
  }

  return 0;
}
