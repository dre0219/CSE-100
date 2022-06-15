#include<iostream>
#include<climits>
using namespace std;

void display(int arr[], int a){
for(int i=0; i<a; i++){
	cout<<arr[i]<<";";
	}
}

int partition(int arr[], int start, int end){
	int pivot= arr[end];
	int partitionIndex = start;
	
	for(int i=start; i<=end; i++){
		if(arr[i]<pivot){
			swap(arr[i], arr[partitionIndex]);
			partitionIndex++;
		}
	}
	swap(arr[end], arr[partitionIndex]);
	return partitionIndex;
}

void Quicksort(int arr[], int start, int end){
	if(start<end){
		int partitionIndex=	partition(arr, start, end);
		Quicksort(arr, start, partitionIndex-1);
		Quicksort(arr, partitionIndex+1, end);
	}
}


int main(){
int a;
cin>>a;
int arr[a];
for(int i=0; i<a; i++){
	cin>>arr[i];
	}
Quicksort(arr, 0, a-1);
display(arr , a);
}
