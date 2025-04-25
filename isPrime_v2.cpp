// this is a further optimized algorithm to determine prime numbers
#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Include for the bool type

bool isPrimeFurtherOptimized(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    if (number <= 5) { // Handle 5 as a special case after checking 2 and 3
        return true;
    }
    if (number % 5 == 0) {
        return false;
    }

    // All prime numbers greater than 5 can be expressed in the form 6k ± 1,
    // but we can be more precise by checking against a sequence that skips
    // multiples of 2, 3, and 5. The sequence is i, i+2, i+4, i+2, i+4, i+2, ...
    // which has a cycle of length 6 (differences of 2, 4).
    for (int i = 7; i * i <= number; i += 30) {
        if (number % i == 0 || number % (i + 4) == 0 ||
            number % (i + 6) == 0 || number % (i + 10) == 0 ||
            number % (i + 12) == 0 || number % (i + 16) == 0 ||
            number % (i + 18) == 0 || number % (i + 22) == 0 ||
            number % (i + 24) == 0 || number % (i + 28) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    printf("Enter a number: ");
    if (scanf("%d", &number) == 1) {
        if (isPrimeFurtherOptimized(number)) {
            printf("%d is a prime number\n", number);
        } else {
            printf("%d is not a prime number\n", number);
        }
    } else {
        printf("Invalid input. Please enter an integer.\n");
    }
    return 0;
}
