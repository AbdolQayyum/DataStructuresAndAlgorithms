#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int array[size];
    
    cout << "Enter array elements:" << endl;
    
    for (int i = 0; i < size; i++) { 
        cin >> array[i];
    }

    cout << "Array elements are:" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << array[i] << endl;
    }
    
    int sum = 0;
    int product = 1;
    
    for(int i = 0; i < size; i++) {
        sum += array[i];
        product *= array[i];
    }
    
    cout << "Sum of array elements: " << sum << endl;
    cout << "Product of array elements: " << product << endl;

    return 0;
}

