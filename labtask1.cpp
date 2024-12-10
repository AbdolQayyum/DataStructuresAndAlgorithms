#include <iostream>
using namespace std;

int main() {
    int start, stop;
    int sum = 0;

    
    cout << "Enter the start value: ";
    cin >> start;
    cout << "Enter the stop value: ";
    cin >> stop;


    // Calculate the sum of squares
    for (int X = start; X <= stop; ++X) {
        sum += X * X;
    }

    // result
    cout << "The sum of squares from " << start << " to " << stop << " is: " << sum << endl;

    return 0;
}

