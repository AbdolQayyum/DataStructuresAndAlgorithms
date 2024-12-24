#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap; // Dynamic array to store the heap

    // Function to heapify up (for insertion)
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        if (index > 0 && heap[index] > heap[parent]) {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    // Function to heapify down (for removal)
    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    // Insert a new element into the priority queue
    void push(int value) {
        heap.push_back(value); // Add the new element at the end
        heapifyUp(heap.size() - 1); // Fix the heap property
        displayHeap(); // Show heap after insertion
    }

    // Remove and return the element with the highest priority
    int pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty!" << endl;
            return -1;
        }
        int root = heap[0]; // Root is the highest priority element
        heap[0] = heap.back(); // Replace root with the last element
        heap.pop_back(); // Remove the last element
        heapifyDown(0); // Fix the heap property
        displayHeap(); // Show heap after removal
        return root;
    }

    // Get the element with the highest priority
    int top() {
        if (!heap.empty())
            return heap[0];
        cout << "Priority queue is empty!" << endl;
        return -1;
    }

    // Check if the priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Display the heap elements
    void displayHeap() {
        cout << "Heap elements: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Insert elements into the priority queue
    cout << "Inserting elements..." << endl;
    pq.push(10);
    pq.push(20);
    pq.push(15);
    pq.push(30);
    pq.push(5);

    cout << "Top element (highest priority): " << pq.top() << endl;

    // Remove elements in priority order
    cout << "Removing elements..." << endl;
    while (!pq.isEmpty()) {
        cout << "Removed: " << pq.pop() << endl;
    }

    return 0;
}

