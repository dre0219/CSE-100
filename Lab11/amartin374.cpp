#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
typedef pair <int, int> IP;//An integer duo
vector <IP> adj[1000];//Adjacents
bool VISITED[1000]; //Have to consider whats been visited in MST (Minimum Spanning Tree)
int key[1000];//Define key, reccomended since its first in pairing
int parent[1000];//The parent array


//Used the pseudocode on PRIMS
void prims(int n){
    priority_queue<IP, vector<IP>, greater<IP> >Q;//Create a priority queue that holds the respective vertices in there place
    Q.push(pair <int,int> (0,0));
    
    for(int i=0; i<n; i++){
        key[i]=999999999; //Once we insert the source as 0 utilizing Q, initialize all keys to infinity or in this instance a big number
        parent[i] = 0;
        }
    
        do{
        int u = Q.top().second;  //MIN KEY VERTEX. u = min() from KEY VALUE
        Q.pop();
        VISITED[u]=true; // Visited Method
        
        for(int i=0; i < adj[u].size(); i++){
            int v = adj[u][i].first; //A= A u (U,PARENT(u));
            int w = adj[u][i].second; //A= A u (U,PARENT(u));
            
            //Vertex, Weight, and Adjacents
            if(!VISITED[v] && key[v]>w){ //. A condition for considering the smaller weight
                key[v]=adj[u][i].second;
                Q.push(pair<int,int>(w,v));
                parent[v]=u;
            }
        }//count++;
    }
    while(!Q.empty()); // While (count < n && count > 0);
  
    //Print LOOP parent
    for(int i=1; i<n; i++)
    cout<<parent[i]<<endl;   
}

int main(){
    int n, m, u, v, w;
    cin >> n;
    cin >> m;
    
    //Creating the graph
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    prims(n);
    return 0;
}