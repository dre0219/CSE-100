#include <iostream>
#include <limits.h>
using namespace std;
//BF = Bellman Fords variable
//PF = Print Function 
void InitSingleSource(int *d, int a){
        for(int i = 0; i < a; i++){
        d[i] = INT_MAX; 
        }
    d[0] = 0;
}

void RELAX(int **x, int *g, int a, int b){
    int i;
    int j;
    for(i = 1; i < a; i++){ 
        for(j = 0; j < b; j++){ 
           int u = x[0][j];
           int v = x[1][j];
           int w = x[2][j];
            if(g[u] != INT_MAX){
                if(g[v] > g[u] + w){
                g[v] = g[u] + w;
                }
            }
        }
    }
}



void PF(int *d, int a){
    cout << "TRUE" <<endl;
    for(int i = 0; i < a; i++){
        if(d[i] < INT_MAX)
            cout << d[i] <<endl; 
        if(d[i] == INT_MAX) 
            cout << "INFINITY" <<endl;
    }
}



void BF(int ** x, int a, int b){
    int condition = 1;
    int i, j;
    int d[a];
    bool reachable = true;
    InitSingleSource(d, a);
    
    RELAX(x, d, a, b);    
    for(j = 0; j < b; j++) { 
      int u = x[0][j];
      int v = x[1][j];
      int w = x[2][j];
        if(d[u] != INT_MAX) {
            if(d[x[1][j]] > d[x[0][j]] + x[2][j])
            condition = 2;
        } 
    }
    switch(condition){
        case 1:
            PF(d, a);
        break;
        case 2:
            cout << "FALSE" << endl;
        break;
        default:
            NULL;
    }
}



int main(){
    int i, j;
    int a = 0;
    int b = 0;
    int u = 0;
    int v = 0;
    int w = 0;
    cin >> a;
    cin >> b;
    int **x;
    x = new int *[3]; 
    for(i = 0; i < a; i++) {
        x[i] = new int[b]; 
    }

    for(i = 0; i < b; i++) {
        cin >> u >> v >> w; 
        x[0][i] = u; 
        x[1][i] = v;
        x[2][i] = w;
    }
    BF(x, a, b);
    return 0;
}