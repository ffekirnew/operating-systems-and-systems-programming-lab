#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
// #include "common.h"

int main(int argc, char *argv[]) {
    char *str = argv[1];
    int i = 100;


    while (i) {
        printf("%s\n", str);
        i -= 1;
    }

    return (0);
}