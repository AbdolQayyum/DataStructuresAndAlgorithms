#include <iostream>
using namespace std;

struct Node{
	int data;
	int height;
	Node* left;
	Node* right;
};

int getHeight(Node* node){
	if(node == NULL){
		return 0;
	}
	return node->height;
}

Node* createNode(int value){
	Node* newNode = new Node();
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->height = 1;
	return newNode;
}

int getBalanceFactor(Node* node){
	if(node == NULL){
		return 0;
	}
	return getHeight(node->left) - getHeight(node->right);
}

Node* rightRotate(Node* y){
	Node* x= y->left;
	Node* T= x->right;
	
	//perform rotation
	x->right = y;
	y->left = T;
	
	//update heights
	y->height = max(getHeight(y->left),getHeight(y->right))+1;
	x->height = max(getHeight(x->left),getHeight(x->right))+1;
	
	return x;
}

Node* leftRotate(Node* x){
	Node* y= x->right;
	Node* T = y->left;
	
	y->left = x;
	x->right = T;
	
	x->height= max(getHeight(x->left),getHeight(x->right)) + 1;
	y->height = max(getHeight(y->left), getHeight(y->right)) +1;
	
	return y;
}

Node* insert(Node* root, int value){
	if(root == NULL){
		return createNode(value);
	}
	
	if(value < root->data){
		root->left = insert(root->left, value);
	}else if(value > root->data){
		root->right = insert(root->right, value);
	}else {
		return root;
	}
	
	root->height = max(getHeight(root->left), getHeight(root->right)) +1;
	
	int balance = getBalanceFactor(root);
	
	if(balance > 1 && value < root->left->data){
		cout << "Right Rotation Performed" << root->data << endl;
		return rightRotate(root);
	}
	
	if(balance < -1 && value > root->right->data){
		cout << "left Rotation performed" << root->data << endl;
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
    
    return root;
}

void printTree(Node* root, int space=0, int height=10){
	if(root == NULL){
		return;
	}
	space = space + height;
	
	printTree(root->left, space);
	
	cout << endl;
	
	for(int i = height; i< space;i++){
		cout << " ";	
	}
	cout << root->data;
	
	printTree(root->right,space);
	
}




int main(){
	
	Node* root = NULL;
	int value;
	
	cout << "Enter values to insert in AVL :" << endl;
	while(true){
	
	cout << "Enter Value: ";
	cin >> value;
	if(value == -1){
		break;
	}
	
	root = insert(root, value);
	cout<<"Tree after inserting " << value << endl;
	printTree(root);
}

cout << "Final AVL Tree" << endl;
printTree(root);

	 
	
}
