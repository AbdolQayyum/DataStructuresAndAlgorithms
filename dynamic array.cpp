#include <iostream>
#include <vector>

using namespace std;

class DynamicArray {
private:
    vector<int> arr;

public:

    void add(int value) {
        arr.push_back(value);
    }

    void deleteByValue(int value) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == value) {
                // Shift elements left to fill the gap
                for (int j = i; j < arr.size() - 1; j++) {
                    arr[j] = arr[j + 1]; 
                }
                arr.pop_back(); // For Remove the last element
                i--; 
            }
        }
    }


    void printArray() const {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
};

int main() {
    DynamicArray dynamicArray;

    
    dynamicArray.add(10);
    dynamicArray.add(20);
    dynamicArray.add(30);
    dynamicArray.add(40);

    cout << "Array: ";
    dynamicArray.printArray(); 

    dynamicArray.deleteByValue(20);
    cout << "Array after deleting 20: ";
    dynamicArray.printArray(); 

  
    return 0;
}

