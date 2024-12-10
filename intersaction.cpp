#include <iostream>

using namespace std;


void findIntersection(int arr1[], int n1, int arr2[], int n2) {
    cout << "Intersection of the two arrays is: ";

    for (int i = 0; i < n1; i++) {
        bool found = false;
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                
                if (!found) {
                    cout << arr1[i] << " ";// If the element is found, print it
                    found = true; 
                }
                break;
            }
        }
    }
    cout << endl;
}

int main() {
    int arr1[] = {5, 6, 7, 8, 1, 2};
    int arr2[] = {3, 4, 9, 6, 7,1};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    findIntersection(arr1, n1, arr2, n2);

    return 0;
}

