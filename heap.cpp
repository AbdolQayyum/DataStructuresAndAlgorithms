#include <iostream>
#include <stdexcept>
using namespace std;

class PriorityQueue {
private:
    int* heap;
    int capacity;
    int size;

    // Helper function to maintain the min-heap property during insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    // Helper function to maintain the min-heap property during deletion
    void heapifyDown(int index) {
        int leftChild, rightChild, smallest;
        while (true) {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor to initialize the priority queue with a fixed capacity
    PriorityQueue(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->heap = new int[capacity];
    }

    // Destructor to free the allocated memory
    ~PriorityQueue() {
        delete[] heap;
    }

    // Inserts an element into the priority queue and maintains the heap property
    void insert(int element) {
        if (size == capacity) {
            throw overflow_error("Priority Queue is full");
        }
        heap[size] = element;
        heapifyUp(size);
        size++;
    }

    // Returns the element with the highest priority (minimum element in a min-heap)
    int getHighestPriority() const {
        if (size == 0) {
            throw out_of_range("Priority Queue is empty");
        }
        return heap[0];
    }

    // Removes the element with the highest priority and maintains the heap property
    void deleteHighestPriority() {
        if (size == 0) {
            throw out_of_range("Priority Queue is empty");
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    // Checks if the priority queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to print the elements of the priority queue
    void printQueue() const {
        for (int i = 0; i < size; i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq(10);

    // Inserting elements into the priority queue
    pq.insert(10);
    pq.insert(20);
    pq.insert(5);
    pq.insert(7);
    pq.insert(9);

    cout << "Priority Queue elements: ";
    pq.printQueue();

    // Getting the element with the highest priority
    cout << "Highest priority element: " << pq.getHighestPriority() << endl;

    // Deleting the element with the highest priority
    pq.deleteHighestPriority();
    cout << "Priority Queue after deleting highest priority element: ";
    pq.printQueue();

    return 0;
}

