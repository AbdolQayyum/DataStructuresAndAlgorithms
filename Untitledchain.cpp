#include <iostream>
#include <vector>

#define SIZE 7
using namespace std;

struct Node{
	
	Node* next;
	int data;
	
};

Node* chain[SIZE];

void init(){
	for(int i=0; i< SIZE; i++){
		chain[i] = NULL;
	}
}
	
void insertion(int value){
	int key = value % SIZE;
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;
		
		if(chain[key] == NULL){
			chain[key] = newNode;
		}else{
			//colloison occured 
			Node* temp= chain[key];
			
			while(temp->next != NULL){
				temp= temp->next;
			}
			temp->next = newNode;
		}
}	

void deletion(int value){
	int key = value % SIZE;
	Node* temp = chain[key];
	Node* prev = NULL;
	
	// traverse to find the node which is to be deleted
	
	while(temp != NULL && temp->data != value){
		prev = temp;
		temp = temp->next;
		
	}
	
	if(temp == NULL){
		cout << "Value not found" << endl;
	}
	
	if(prev == NULL){
		chain[key] = temp->next;
	}else{
		prev->next = temp->next;
		
	}
	
	delete temp;
	cout << "Value " << value << " deleted from the hash table.\n";
	
}

void display(){
	for(int i=0; i< SIZE; i++){
		cout << "Chain[" << i << "] -->" ;
		Node* temp= chain[i];
		while(temp != NULL){
			cout<< temp->data << "-->";
			temp=temp->next;
		}
		
		cout<< "NULL\n";
	}
}




int main(){
	
	init();
	
	int values[] = {25, 37, 18, 55, 68, 49, 21, 10};
	int n = sizeof(values) / sizeof(values[0]);
	
	for(int i=0; i<n;i++){
		insertion(values[i]);
	}
	
	cout << "Values before deletion :" << endl;
	display();
	
	deletion(25);
	deletion(55);
	
	cout << "values after deletion " << endl;
	
	display();
	
}
