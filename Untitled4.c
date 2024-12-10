#include <stdio.h>

int main() {
    int sum = 0;            // Sum variable for for loops and do-while
    int i, j;               // Loop counters
    int counter = 1;        // For do-while loop
    int switchInput = 0;    // Input for switch-case
    int category = 0;       // Result of category based on score
    int score;              // Final score from sum for nested if-else

    // Nested for loops to calculate the sum of products of loop variables
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 2; j++) {
            sum += i * j;    // Multiply i and j, and add to sum
        }
    }

    // Do-while loop: adding numbers from 1 to 5
    do {
        sum += counter;  // Add counter value to sum
        counter++;
    } while (counter <= 5);

    // Ask for switch input (pretend this is from a calculation in your actual code)
    switchInput = sum % 3;  // Modulo operation to generate a value for switch case

    // Switch-case to handle different categories of the sum
    switch (switchInput) {
        case 0:
            category = 1;    // Category 1
            break;
        case 1:
            category = 2;    // Category 2
            break;
        case 2:
            category = 3;    // Category 3
            break;
        default:
            category = 0;    // Default category
            break;
    }

    // Nested if-else to determine score category
    score = sum + category;  // Final score is sum plus category

    if (score >= 30) {
        if (score >= 40) {
            if (score >= 50) {
                printf("Your score is high: %d\n", score); // Score is high
            } else {
                printf("Your score is moderate-high: %d\n", score); // Score is moderate-high
            }
        } else {
            printf("Your score is moderate: %d\n", score); // Score is moderate
        }
    } else {
        if (score >= 20) {
            printf("Your score is low: %d\n", score); // Score is low
        } else {
            printf("Your score is very low: %d\n", score); // Score is very low
        }
    }

    return 0;
}

