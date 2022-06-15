#include <iostream> 
using namespace std; 
  

void heapify(int a[], int x, int i){ 
    int greater = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    //Left variable larger than root
    if (l < x && a[l] > a[greater]) 
        greater = l; 
    //Right Variable larger than root 
    if (r < x && a[r] > a[greater]) 
        greater = r; 
    //Root is not the largest
    if (greater != i){ 
        swap(a[i], a[greater]); 
        //Recursively heapify affects the sub-tree 
        heapify(a, x, greater); 
    } 
} 
  
//The main fucntion in order to do heap sort
void heapSort(int arr[], int x){ 
    //Building heap (Rearranging the array) 
    for (int i = x / 2 - 1; i >= 0; i--) 
        heapify(arr, x, i); 
    //One by one extract an element
    for (int i=x-1; i>=0; i--){ 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
} 
void printArray(int arr[], int x){ 
    for (int i=0; i<x; ++i) 
        cout << arr[i] << ";"; 
} 
  
//The main driving code.
int main(){ 
	int x;
	cin>>x;
    int arr[x]; 
	for(int i=0; i<x; i++){
		cin>>arr[i];
	} 
    heapSort(arr, x); 
    printArray(arr, x); 
} 
