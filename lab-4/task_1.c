#include <stdio.h>
#include <unistd.h>

void task_for_child() {
  printf("Greetings, this is child.\n");
}


void task_for_parent() {
  printf("Greetings, this is parent.\n");
}


void main() {
  int pid = fork();

  if (pid == 0) {
    task_for_child();
  } else {
    task_for_parent();
  }
}
