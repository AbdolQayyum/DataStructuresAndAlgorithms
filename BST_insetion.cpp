#include <iostream>
using namespace std;

struct bst {
    int id;
    bst *left = NULL;
    bst *right = NULL;
};

bst *root = NULL;

// Iterative insertion in BST
void insert(int value) {
    bst *newNode = new bst;  // Create a new node
    newNode->id = value;     // Assign value to the new node

    if (root == NULL) {
        // If the tree is empty, the new node becomes the root
        root = newNode;
    } else {
        // Start traversal from the root
        bst *child = root, *parent = NULL;

        // Traverse the tree to find the appropriate position for the new node
        while (child != NULL) {
            parent = child;  // Update parent to the current node
            if (newNode->id > parent->id) {
                // Move to the right child if the new node is greater
                child = child->right;
            } else {
                // Move to the left child if the new node is smaller or equal
                child = child->left;
            }
        }

        // After the loop, `child` is NULL, and `parent` is the node where we insert the new node
        if (newNode->id > parent->id) {
            // Insert as the right child
            parent->right = newNode;
        } else {
            // Insert as the left child
            parent->left = newNode;
        }
    }
}

void preorder(bst *root) {
    if (root != NULL) {
        cout << root->id << " > ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (LRN)
void postorder(bst *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->id << " > ";
    }
}

// In-order traversal (LNR)
void inorder(bst *root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->id << " > ";
        inorder(root->right);
    }
}

int main() {
    insert(50);
    insert(30);
    insert(20);
    insert(40);
    insert(70);
    insert(60);
    insert(80);

    cout << "In-order traversal: ";
    inorder(root);
    cout << endl;
    
       cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}

