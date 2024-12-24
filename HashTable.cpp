#include <iostream>
#include <list>
#include <vector>

using namespace std;

class LinearProbingHashTable{
	vector<int> table;
	int size;
	
public:
	
	LinearProbingHashTable(int s) : size(s){
		table.resize(size, -1);
	}
	
	int hashFunction(int key){
		return key % size;
	}
	
	void insert(int key){
		int index= hashFunction(key);
		while(table[index] != -1){
			index = (index + 1) % size;
		}
		table[index] = key;
	}
	
	void display() {
    for (int i = 0; i < size; i++) {
        cout << i << " -> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
    	}
    }
};

class ChainingHashTable{
	
	vector<list<int>> table;
	int size;
	
public:	
	ChainingHashTable(int s) : size(s){
		table.resize(size);
	}
	
	int hashFunction(int key){
		return key % size;
	}
	
	void insert(int key){
		int index= hashFunction(key);
		table[index].push_back(key);
	}
	
	void deleteKey(int key){
		int index= hashFunction(key);
		table[index].remove(key);
	}
	
	void display(){
		for(int i=0; i< size; i++){
			cout << i << "->";
			for(int val : table[i]){
				cout << val << "->";
			}
			cout << "NULL" << endl;
		}
	}
	
};

int main(){
	
	cout << "Linear Probing Hash Tabel " << endl;
	LinearProbingHashTable lpHashTable(10);
	vector<int> linearProbingKeys = {25, 37, 18, 55, 68, 49, 21, 10};
	for(int key : linearProbingKeys){
		lpHashTable.insert(key);
	}
	
	lpHashTable.display();
	cout << endl;
	

    cout << "Chaining Hash Table:" << endl;
    ChainingHashTable chainingHashTable(5);
    vector<int> chainingKeys = {15, 25, 35, 45, 10, 20, 30, 40};
    for (int key : chainingKeys) {
        chainingHashTable.insert(key);
    }
    chainingHashTable.display();
    cout << endl;

    
    cout << "Chaining Hash Table After Deletions:" << endl;
    chainingHashTable.deleteKey(25);
    chainingHashTable.deleteKey(45);
    chainingHashTable.display();

    return 0;

	
}
