#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
	for(int i=0; i< n-1; i++){// for total number of passes
		for(int j=0; j< n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void selectionsort(int arr1[], int n){
	for(int i=0; i<n-1; i++){
		int minIndex=i;
		
		for(int j=i+1; j<n;j++){
			if(arr1[j] < arr1[minIndex]){
				minIndex=j;
			}
		}
		swap(arr1[i],arr1[minIndex]);
	}
}

void insertionsort(int arr[], int n){
	for(int i=1; i<n;i++){
		int key= arr[i];
		int j= i-1;
		
		while(j>=0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = key;
		
	}
	
}


int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = low-1;
	
	for(int j= low; j< high; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	
	swap(arr[i+1], arr[high]);
	return i+1;
}

void quicksort(int arr[], int low, int high){
	if(low<high){
		int pi= partition(arr, low,high);
		
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}

void heapify(int arr[], int n, int i){
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;
	
	if(largest < n && arr[left] > arr[largest]){
		largest=left;
	}
	
	if(largest < n && arr[right] > arr[left]){
		largest = right;
	}
	
	if(largest != i){
		swap(arr[i], arr[largest]);
		heapify(arr,n , largest);
	}
}

void heapsort(int arr[], int n){
	for(int i= n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

int main(){
	
	int arr[] ={22,45,64,11,8,19,66};
	int arr1[] ={22,45,64,11,8,19,66};
	int n= sizeof(arr) / sizeof(arr[0]);
	
//	bubblesort(arr,n);
	selectionsort(arr1,n);
//	insertionsort(arr,n);
quicksort(arr,0,n-1);
	
//	cout<<"Bubble Sorted Array is :" << endl;
//	for(int i=0;i<n; i++){
//		cout << arr[i] << " " << endl;
//		
//	}
	
	cout<<"selection Sorted Array is :" << endl;
	for(int i=0;i<n; i++){
		cout << arr1[i] << " " << endl;
	}
	
//		cout<<"Insertion Sorted Array is :" << endl;
//	for(int i=0;i<n; i++){
//		cout << arr[i] << " " << endl;
//		
//	}

		cout<<"Quick Sorted Array is :" << endl;
	for(int i=0;i<n; i++){
		cout << arr[i] << " " << endl;
		
	}
	
	
}
