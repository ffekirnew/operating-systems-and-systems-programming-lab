#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void task_for_child() {
  printf("Child process executing...\n");
  sleep(5);
  printf("Child process completed.\n");
}

int main() {
  printf("Parent process executing...\n");
  
  int pid = fork();

  if (pid == 0) {
    task_for_child();
  } else {
    sleep(1);
    printf("Killing the child process now.\n");
    kill(pid, SIGQUIT);
    printf("Child process is killed, successfully. Now terminating.\n");
  }
}
