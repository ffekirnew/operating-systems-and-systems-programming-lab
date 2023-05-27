#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool flag[2] = {false, false};
int turn = 0;

void enter_region(int process) {
    int other = 1 - process;
    flag[process] = true;
    turn = process;

    while (flag[other] && turn == process) {
        // Busy-waiting, continue looping until it is safe to enter
    }
}

void leave_region(int process) {
    flag[process] = false;
}

void critical_section(int process) {
    printf("Process %d is in the critical section.\n", process);
    // Perform critical section operations

    // Sleep to simulate the process being in the critical section
    sleep(3);
}

void process(int process) {
    // Non-critical section

    enter_region(process);

    // Critical section
    critical_section(process);

    leave_region(process);

    // Remainder section
    printf("Process %d completed.\n", process);
}

int main() {
    int pid = fork();

    if (pid == 0) {
        // Child process
        process(1);
    } else {
        // Parent process
        process(0);
    }

    return 0;
}
