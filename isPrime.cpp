// this is an optimized algorithm to determine prime numbers
#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Include for the bool type

bool isPrimeOptimized(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    // All prime numbers greater than 3 can be expressed in the form 6k ± 1
    for (int i = 5; i * i <= number; i = i + 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    printf("Enter a number: ");
    if (scanf("%d", &number) == 1) {
        if (isPrimeOptimized(number)) {
            printf("%d is a prime number\n", number);
        } else {
            printf("%d is not a prime number\n", number);
        }
    } else {
        printf("Invalid input. Please enter an integer.\n");
    }
    return 0;
}
