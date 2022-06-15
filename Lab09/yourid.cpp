#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
/* Constructing a Huffman tree in which each
leaf of the tree corresponds to a letter in the given alphabet*/

using namespace std;
struct MinHeapNode{
char info;
unsigned freq;
// Each left and right child
MinHeapNode *left, *right;
	MinHeapNode(char info, unsigned freq){
	left = right = NULL;
	this -> info = info;
	this -> freq = freq;}
};



// To see the comparison between the two heap nodes
struct compare {
	bool operator()(MinHeapNode* l, MinHeapNode* r){
	return (l -> freq > r -> freq);}
};




// Here we're printing the Huffman codes from the root of the tree
void printCodes(struct MinHeapNode* root, char ans , string str){
if (!root)
return;
	if (root -> info != '$'){
	if(ans == root -> info)
	cout << root-> info << ":" << str << "\n";}
printCodes(root -> left, ans, str + "0");
printCodes(root -> right, ans, str + "1");
}




/* The main function that builds a Huffman Tree and
print codes by traversing the built Huffman Tree*/
void HuffmanCodes(char info[], int freq[], int size){
struct MinHeapNode *left, *right, *top;
// We make a min heap and then insert all the characters from the info[] array
priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
for (int i = 0; i < size; ++i)
minHeap.push(new MinHeapNode(info[i], freq[i]));

	// Iterate while size of heap does not equal(!=) to 1. 
	while (minHeap.size() != 1) {
	// Extract the two minimum frequent items from min heap
	left = minHeap.top();
	minHeap.pop();
	right = minHeap.top();
	minHeap.pop();
	top = new MinHeapNode('$', left ->  freq + right -> freq);
	top -> left = left;
	top -> right = right;
	minHeap.push(top);}
		/* Finally we print the Huffman codes using
		the Huffman tree that is built above*/
		for(int i=0; i<6; ++i){
		printCodes(minHeap.top(), info[i], "");}
}



// Main driving code
int main(){
char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
int freq[6];
int size = sizeof(arr) / sizeof(arr[0]);
for(int i=0; i<size; i++)
cin >> freq[i];
HuffmanCodes(arr, freq, size);
return 0;
}
