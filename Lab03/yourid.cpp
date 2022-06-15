#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
int max(int x, int y) { return (x > y)? x : y;}

int max(int x, int y, int z) { return max(max(x, y), z);} //Overloading max function

int find_max_crossing_subarray(int arr[], int low, int mid,int high){
  int sum = 0;
  int left_sum = INT_MIN;  //Elements on left of mid
  for (int i = mid; i >= low; i--){
    sum += arr[i];
    left_sum = max(sum,left_sum);
  }

  sum = 0;
  int right_sum = INT_MIN;   //Elements on right of mid
  for (int i = mid +1; i <= high ; i++){
    sum += arr[i];
    right_sum = max(sum,right_sum);
  }
  return max(left_sum + right_sum,left_sum,right_sum);
}
int find_maximum_subarray(int arr[], int low, int high){
  if (high == low){
    return arr[low];
  }
  int mid = (low + high)/2;		//Converted the pseudo case into the max function.
  return max(max(find_maximum_subarray(arr,low,mid),find_maximum_subarray(arr,mid+1,high)),find_max_crossing_subarray(arr,low,mid,high));
}

//Main
int main(){
  int m;	//taking inputs
  cin >> m;
  int arr[m];
  for (int i =0; i < m; i++){
    cin >> arr[i];
  }
  int max_sum = find_maximum_subarray(arr,0,m-1);
  cout << max_sum;	//Printing results
  return 0;
  }