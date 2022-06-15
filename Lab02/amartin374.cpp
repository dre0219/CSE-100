#include<stdio.h>
#include<stdlib.h>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;



//Functions
void mergeSort(int *v, int p, int q, int r);
void merge(int *v, int p, int r);
void merge(int *v, int p, int q, int r){

int x, y;
int i = 0;
int n1 = q - p + 1;
int n2 = r - q;
int L[n1+1], R[n2+1];


for (y = 0; y < n1; y++)
L[y] = v[p + y];

for (x = 0; x < n2; x++)
R[x] = v[q +1 + x];
y = x = 0;
i = p;

while (y < n1 && x < n2){
if ((L[y] <= R[x])){
v[i] = L[y];
y++;
}



else{
v[i] = R[x];
x++;
}
i++;
}



while (y < n1){
v[i] = L[y];
y++;
i++;
}


while (x < n2){
v[i] = R[x];
x++;
i++;
}

}




//Middle
void mergeSort(int *v, int p, int r) {

int q;
if (p < r) {
q = (p + r) / 2;
mergeSort(v, p, q);
mergeSort(v, q + 1, r);
merge(v, p, q, r);
}
}





void printArray(int *arr, int n) {
for (int y = 0; y < n; y++)
cout<< arr[y]<<";";
}






//Main driving code
int main(){
int n;
cin>>n;
int *a = new int[n];

for(int y=0;y<n;++y)
cin>>a[y];
mergeSort(a,0,n-1);
printArray(a, n);
}
