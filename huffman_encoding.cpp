/*
	https://www.youtube.com/watch?v=co4_ahEDCho

	NOTE: After Encoding the total size of the message is not just "The Encoded Message" but we also have send the table 
	used for encoding along with the message. So, 
	"Total" size = Size of "Encoded Messsage" + Size of "Table"

	NOTE: Huffman Encoding is a greedy algorithm, works on the principle of OPTIMAL MERGE PATTERN
*/

#include<bits/stdc++.h>
using namespace std;

// min heap node
struct Node { 
	char d;
	int f; 
	struct Node *l, *r; 

	Node (char _d, int _f): 
    d(_d), f(_f), l(NULL), r(NULL) { } 
}; 


struct MinHeapNode { 
	int s;
	struct Node** array; 

	MinHeapNode(int _s): s(_s), array(new Node*[_s]) { }
}; 


void minHeapify(struct MinHeapNode* minHeap, int i) { 
	int smallest = i; 
	int l = 2*i + 1; 
	int r = 2*i + 2; 

	if (l < minHeap->s && minHeap->array[l]->f < minHeap->array[smallest]->f) 
		smallest = l; 

	if (r < minHeap->s && minHeap->array[r]->f < minHeap->array[smallest]->f) 
		smallest = r; 

	if (smallest != i) { 
		swap(minHeap->array[smallest], minHeap->array[i]); 
		minHeapify(minHeap, smallest); 
	} 
} 


struct Node* extractMin(struct MinHeapNode* minHeap) { 
	struct Node* temp = minHeap->array[0]; 
	minHeap->array[0] = minHeap->array[minHeap->s - 1]; 
	--minHeap->s; 
	minHeapify(minHeap, 0); 
	return temp; 
} 


void insertMinHeap(struct MinHeapNode* minHeap, struct Node* Node) { 
	++minHeap->s; 
	int i = minHeap->s - 1; 
	// (i-2)/2 is parent node of i
	while (i && Node->f < minHeap->array[(i-1)/2]->f) { 
		minHeap->array[i] = minHeap->array[(i-1)/2]; 
		i = (i-1)/2; 
	} 
	minHeap->array[i] = Node; 
} 


void buildMinHeap(struct MinHeapNode* minHeap) { 
	int n = minHeap->s - 1; 
	int i; 
	for (i = (n - 1) / 2; i >= 0; --i) 
		minHeapify(minHeap, i); 
} 


void printArr(int arr[], int n) { 
	int i; 
	for (i = 0; i < n; ++i) 
		cout<< arr[i]; 

	cout<<"\n"; 
} 


int isLeaf(struct Node* root) { 
	return !(root->l) && !(root->r); 
} 


struct MinHeapNode* createAndBuildMinHeap(char d[], int f[], int s) { 
	struct MinHeapNode* minHeap = new MinHeapNode(s); 

	for (int i = 0; i < s; ++i) 
		minHeap->array[i] = new Node(d[i], f[i]); 

	minHeap->s = s; 
	buildMinHeap(minHeap); 

	return minHeap; 
} 


struct Node* buildHuffmanTree(char d[], int f[], int s) { 
	struct Node *l, *r, *top; 
	struct MinHeapNode* minHeap = createAndBuildMinHeap(d, f, s); 
 
	while (minHeap->s > 1) { 
		l = extractMin(minHeap); 
		r = extractMin(minHeap); 

		top = new Node('$', l->f + r->f); 
		top->l = l; 
		top->r = r; 

		insertMinHeap(minHeap, top); 
	} 
	return extractMin(minHeap); 
} 


void getCodes(struct Node* root, string &code, vector<string> &codes) { 
	if (root->l) { 
		code.push_back('0');
		getCodes(root->l, code, codes); 
		code.pop_back();
	} 

	if (root->r) { 
		code.push_back('1');
		getCodes(root->r, code, codes);
		code.pop_back(); 
	} 

	if (isLeaf(root)) { 
		cout << root->d << ": " << code << endl;
		codes.push_back(code); 
	} 
} 


void HuffmanCodes(char d[], int f[], int s, vector<string> &codes) { 
	struct Node* root = buildHuffmanTree(d, f, s); 
	string code = "";
	getCodes(root, code, codes); 
} 


vector<string> generateHuffman(string str,vector<int> freq,int N) { 
	int s = N;
	char arr[s];
	int f[s];
	vector<string> codes;

	for(int i = 0; i < s; i++) {
		arr[i] = str[i];
		f[i] = freq[i];
	}

	HuffmanCodes(arr, f, s, codes); 
	return codes;
} 

int main() {
	auto ans = generateHuffman("abcdef", {5, 9, 12, 13, 16, 45}, 6);
	// for(auto c: ans) {
	// 	cout << c << endl;
	// }
}