#include <stdio.h>

int main() {
    int num = 2;  // Example value for num
    int result = 0;

    // Switch-case based on the value of num
    switch (num) {
        case 1:
            result = num + 10;  // Perform operation when num is 1
            break;
        case 2:
            result = num * 2;   // Perform operation when num is 2
            break;
        case 3:
            result = num - 5;   // Perform operation when num is 3
            break;
        default:
            result = num;       // Default case, no operation
            break;
    }

    return 0;  // End of the program
}

