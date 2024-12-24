#include <iostream>
#include <iomanip>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
};

// Function to get the height of a node
int getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1; // New node is initially added at height 1
    return newNode;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    // Perform rotation
    x->right = y;
    y->left = T;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    // Perform rotation
    y->left = x;
    x->right = T;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Function to print the tree in a 2D format
void printTree(Node* root, int space = 0, int height = 10) {
    if (root == nullptr)
        return;

    // Increase distance between levels
    space += height;

    // Print right child first
    printTree(root->left, space);

    // Print current node
    cout << endl;
    for (int i = height; i < space; i++)
        cout << " ";
    cout << root->data;

    // Print left child
    printTree(root->right, space);
}

// Insert a node into the AVL tree
Node* insert(Node* root, int value) {
    // Step 1: Perform regular BST insertion
    if (root == nullptr) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        return root; // Duplicate values are not allowed
    }

    // Step 2: Update the height of the current node
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // Step 3: Get the balance factor
    int balance = getBalanceFactor(root);

    // Step 4: Perform rotations to balance the tree
    // Left-Left Case
    if (balance > 1 && value < root->left->data) {
        cout << "\nBalancing tree: Right rotation performed on node " << root->data << "\n";
        return rightRotate(root);
    }

    // Right-Right Case
    if (balance < -1 && value > root->right->data) {
        cout << "\nBalancing tree: Left rotation performed on node " << root->data << "\n";
        return leftRotate(root);
    }

    // Left-Right Case
    if (balance > 1 && value > root->left->data) {
        cout << "\nBalancing tree: Left-Right rotation performed on node " << root->data << "\n";
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right-Left Case
    if (balance < -1 && value < root->right->data) {
        cout << "\nBalancing tree: Right-Left rotation performed on node " << root->data << "\n";
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // Return the unchanged root pointer
}

// Main function
int main() {
    Node* root = nullptr;
    int value;

    cout << "Enter values to insert into the AVL tree (enter -1 to stop):\n";
    while (true) {
        cout << "Enter value: ";
        cin >> value;
        if (value == -1) break;

        root = insert(root, value);
        cout << "\nTree after inserting " << value << ":\n";
        printTree(root);
        cout << "\n------------------------------------------\n";
    }

    cout << "\nFinal AVL Tree:\n";
    printTree(root);

    return 0;
}

