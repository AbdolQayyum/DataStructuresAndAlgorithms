#include <iostream>
#include <vector>

using namespace std;

vector<int> findOccurrences(const vector<int>& data, int target) {
    vector<int> indices;

    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i] == target) {
            indices.push_back(i);
        }
    }

    return indices;
}

int main() {
    
    int arr[] = {10, 30, 40, 60, 20,30 , 90};
    vector<int> data(arr, arr + sizeof(arr) / sizeof(int));
    
    int target = 20;

    vector<int> indices = findOccurrences(data, target);

    cout << "Indices where " << target << " occurs: ";
    
    for (size_t i = 0; i < indices.size(); ++i) {
        cout << indices[i] << " ";
    }

    return 0;
}

