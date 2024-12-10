#include <iostream>
using namespace std;

struct bst {
    int id;
    bst* left = NULL;
    bst* right = NULL;
};

bst* root = NULL;

// Iterative Insert Function
void insert_node(int a) {
    bst* curr = new bst;
    curr->id = a;

    if (root == NULL) {
        root = curr;
    } else {
        bst* p = root;
        bst* q;

        while (p != NULL) {
            q = p;
            if (curr->id > q->id) {
                p = p->right;
            } else {
                p = p->left;
            }
        }

        if (curr->id > q->id) {
            q->right = curr;
        } else {
            q->left = curr;
        }
    }
}

// Inorder Traversal
void Inorder(struct bst* root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->id << " > ";
        Inorder(root->right);
    }
}

// Preorder Traversal
void Preorder(struct bst* root) {
    if (root != NULL) {
        cout << root->id << " > ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

// Postorder Traversal
void Postorder(struct bst* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->id << " > ";
    }
}

// Search Function
bool search_node(bst* root, int key) {
    bst* p = root;
    while (p != NULL) {
        if (p->id == key) {
            return true;
        } else if (key > p->id) {
            p = p->right;
        } else {
            p = p->left;
        }
    }
    return false;
}

// Min Function
bst* min() {
    bst* p = root;
    bst* p2 = NULL;
    while (p != NULL) {
        p2 = p;
        p = p->left;  // Smallest value is in the leftmost node
    }
    return p2;
}

// Max Function
bst* max() {
    bst* p = root;
    bst* p2 = NULL;
    while (p != NULL) {
        p2 = p;
        p = p->right;  // Largest value is in the rightmost node
    }
    return p2;
}

int main() {
    // Iterative Insertion
    insert_node(3);
    insert_node(5);
    insert_node(7);
    insert_node(10);
    insert_node(20);

    // Perform Traversals
    cout << "Inorder Traversal: ";
    Inorder(root);  
    cout << "NULL" << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);  
    cout << "NULL" << endl;

    cout << "Postorder Traversal: ";
    Postorder(root);  
    cout << "NULL" << endl;

    // Search for a node
    int searchKey = 7;
    if (search_node(root, searchKey)) {
        cout << "Node with ID " << searchKey << " found in the tree." << endl;
    } else {
        cout << "Node with ID " << searchKey << " not found in the tree." << endl;
    }

    // Find minimum value
    bst* minNode = min();
    if (minNode != NULL) {
        cout << "Minimum value in the tree: " << minNode->id << endl;
    }

    // Find maximum value
    bst* maxNode = max();
    if (maxNode != NULL) {
        cout << "Maximum value in the tree: " << maxNode->id << endl;
    }

    return 0;
}

