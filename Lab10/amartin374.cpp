
#include <iostream>
#include <list>
#include <stack>
//Connecting a vertex from another vertex??
// StronglyCC=Strongly Connected Component
using namespace std;
class StronglyCC{ // Creating a class in which is called StronglyCC
int Vertex; // Declaring the vertex
list<int> *adjacent; // Declaring a list on an adjacent node
void SCCfillID(int vertex, bool traversed[], stack<int> &Stack); // Creating a function to fill in the node
// Have a function in order to use the DFS approach to the traverse
// The vertex node
void SSCDFS(int vertex, bool traversed[],int node,int arr[]);

public:// Creating the by default constructor
StronglyCC(int Vertex);
void ConnectedEdge(int vertex, int B);
void printSCCs(int node, int arr[]);// Components
StronglyCC getTranspose();// Using the transpose method to conncet the graph
};


StronglyCC::StronglyCC(int Vertex){// Define the function of the strongly connected class
this -> Vertex = Vertex;// We use the "this" method to traverse the vertex
adjacent = new list<int> [Vertex];// Traversing the adjacent vertex
}


void StronglyCC::SSCDFS(int vertex, bool traversed[], int node, int arr[]){// We definene the strongly connected to display the DFS tree vertex node
traversed [vertex] = true;// A node is traversed, in which it assigns that it is true
arr[vertex] = node;
// Iterating all the visited vertex in the list
list<int>::iterator i;
for (i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)
if (!traversed[*i])
SSCDFS(*i, traversed, node, arr);
}


StronglyCC StronglyCC::getTranspose(){
StronglyCC Z(Vertex);
for (int vertex = 0; vertex < Vertex; vertex++){
list<int>::iterator i;
	for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
	Z.adjacent[*i].push_back(vertex);
	}
}
return Z;
}


void StronglyCC::ConnectedEdge(int vertex, int B){
adjacent[vertex].push_back(B); 
}


void StronglyCC::SCCfillID(int vertex, bool traversed[], stack<int> &Stack){
traversed[vertex] = true;
list<int>::iterator i;
for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)
if(!traversed[*i])
SCCfillID(*i, traversed, Stack);
Stack.push(vertex);
}


void StronglyCC::printSCCs(int node, int arr[]){
stack<int> Stack;
bool *traversed = new bool[Vertex];
for(int i = 0; i < Vertex; i++)
traversed[i] = false;
for(int i = 0; i < Vertex; i++)
if(traversed[i] == false)

SCCfillID(i, traversed, Stack);
StronglyCC gT = getTranspose();
for(int i = 0; i < Vertex; i++)
traversed[i] = false;


while (Stack.empty() == false){
int vertex = Stack.top();
Stack.pop();

	if (traversed[vertex] == false){
	gT.SSCDFS(vertex, traversed, vertex, arr);
	int min=vertex;
		for(int i=0; i<node; i++){
			if(arr[i] == vertex){
			if(min > i)
			min=i;
				}
			}		


for(int i=0;  i<node; i++)
if(arr[i] == vertex)
arr[i]=min;
	}
}
}


int main(){
int node, edge;
cin>>node;
cin>>edge;

StronglyCC Z(node);
for(int i=0; i<edge; i++){
int x,y;
cin >> x >> y;
Z.ConnectedEdge(x,y);
}
	int arr[node];
	for(int i=0; i<node; i++){
	arr[i] = node+2;
	}

	Z.printSCCs(node, arr);
		for(int i=0; i<node; i++){
		cout << arr[i] << endl;
		}
return 0;
}
