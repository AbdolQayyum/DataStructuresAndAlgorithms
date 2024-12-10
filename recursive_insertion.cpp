#include <iostream>
using namespace std;

// Structure for a node in the binary search tree
struct bst {
    int id;        // Value of the node
    bst *left;     // Pointer to the left child
    bst *right;    // Pointer to the right child
};

// Global pointer to the root of the tree
bst *root = NULL;

// Function to insert the root node
void insert_root(bst *curr) {
    root = curr;  // Set the current node as the root
}

// Recursive insertion in BST
void recursive_insert(bst *root, bst *curr) {
    if (curr->id < root->id) {
        // If the current node's value is less, move to the left subtree
        if (root->left == NULL) {
            root->left = curr;  // Insert if the left child is empty
        } else {
            recursive_insert(root->left, curr);  // Recursively insert in the left subtree
        }
    } else {
        // If the current node's value is greater or equal, move to the right subtree
        if (root->right == NULL) {
            root->right = curr;  // Insert if the right child is empty
        } else {
            recursive_insert(root->right, curr);  // Recursively insert in the right subtree
        }
    }
}

// Function to create a new node
bst* create_node(int value) {
    bst *newNode = new bst;
    newNode->id = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal (LNR) to verify the structure of the tree
void inorder(bst *root) {
    if (root != NULL) {
        inorder(root->left);             // Traverse the left subtree
        cout << root->id << " > ";       // Print the node value
        inorder(root->right);            // Traverse the right subtree
    }
}

int main() {
    // Inserting the root node
    bst *node1 = create_node(50);
    insert_root(node1);

    // Inserting additional nodes recursively
    bst *node2 = create_node(30);
    bst *node3 = create_node(70);
    bst *node4 = create_node(20);
    bst *node5 = create_node(40);
    bst *node6 = create_node(60);
    bst *node7 = create_node(80);

    // Recursive insertion
    recursive_insert(root, node2);
    recursive_insert(root, node3);
    recursive_insert(root, node4);
    recursive_insert(root, node5);
    recursive_insert(root, node6);
    recursive_insert(root, node7);

    // In-order traversal to display the tree structure
    cout << "In-order traversal: ";
    inorder(root);  // Should display: 20 > 30 > 40 > 50 > 60 > 70 > 80 >
    cout << endl;

    return 0;
}

