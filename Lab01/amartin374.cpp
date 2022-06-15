#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

//Insertion sort funciton in order to sort the numbers.
void Sorting(int arr[], int n){  
    int x, i, y;  
    for (x = 1; x < n; x++){  
        i = arr[x];  
        y = x - 1; 
        //Moving the numbers
        while (y >= 0 && arr[y] > i){  
            arr[y + 1] = arr[y];
            y = y - 1;  
        }  
        arr[y + 1] = i;
    }  
}  
 












//An array function in order to print out the size of n
void Array(int arr[], int n){  
    int s; 
    for (s = 0; s < n; s++){  
       cout <<arr[s] << ";";
    }
cout<<"\n"; 
}

  













//The main driving code
int main(){  
int n;
cin>>n;
    int arr[n];  
for(int x=0; x<n; x++){
cin>>arr[x];
}
for(int x=0; x<n; x++){
    if(x>0){  
    Sorting(arr, x+1);  
    Array(arr, x+1);  
        }
    } 
    return 0; 
}  