#include<stdio.h>
#include<stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;



// The max for two numbers.
int max(int a, int b){
if(a>b)
	return a;
else
	return b;
}

// The max for three numbers.
int Max(int x, int y, int z){return max(max(x, y), z);}
int MaxSumSubarray(int x[], int size){
if(size ==1){
return x[0];
}



//Sum
int m = size/2;
int left_MMS = MaxSumSubarray(x, m);
int right_MMS = MaxSumSubarray(x+m, size-m);
int leftsum=INT_MIN; int sum=0;

for(int i=(m-1); i>=0; i--){
sum = sum + x[i]; 
leftsum = max(sum, leftsum);
}
sum=0;

int rightsum = INT_MIN;

for(int i=m; i<size; i++){
sum= sum+x[i];
rightsum = max(rightsum, sum); 
}

int crossingsum = leftsum + rightsum;
return Max(right_MMS, left_MMS, crossingsum);
}



// The main driving code.
int main(){
int a;
cin>>a;
int arr[a];

for(int i=0;i<a;i++){
cin>>arr[i];
}
int max_sum = MaxSumSubarray(arr, a);
cout<<max_sum;
} 
