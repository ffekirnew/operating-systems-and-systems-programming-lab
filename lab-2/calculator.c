#include <stdio.h>

/**
 * add - add two numbers.
 * @a: the first integer
 * @b: the second integer
 * returns: an integer, the sum of the two numbers.
*/
int add(int a, int b) {
    return (a + b);
}


/**
 * add - add two numbers.
 * @a: the first integer
 * @b: the second integer
 * returns: an integer, the product of the two numbers.
*/
int mul(int a, int b) {
    return (a * b);
}

/**
 * main - entry point to the program.
 * returns: 0 for success, 1 for failure.
*/
int main() {
    int choice, num1, num2, result;

    printf("\nWhat do you want to do:\n");
    printf("\t1. Addition\n");
    printf("\t2. Multiplication\n");
    printf("\t3. Exit\n=> ");

    scanf("%d", &choice);

    if (choice < 3 && choice > 0) {
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter second number: ");
        scanf("%d", &num2);

        result = (choice == 1) ? add(num1, num2) : mul(num1, num2);

        printf("Result: %d\n", result);
        return (0);
    } 

    else if (choice == 3) {
        printf("You are exiting.\n");
        return (0);
    }

    else {
        printf("Invalid choice. Please try again.\n");
        return (1);
    }
}
