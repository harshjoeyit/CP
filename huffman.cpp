#include<bits/stdc++.h>
using namespace std;
#define H 50

// min heap node
struct MHNode { 
	char d;
	int f; 
	struct MHNode *l, *r; 
}; 

 
struct min_heap { 
	int s;
	int c; 
	struct MHNode** array; 
}; 


struct MHNode* newNode(char d, int f) 
{ 
	struct MHNode* temp = (struct MHNode*)malloc(sizeof(struct MHNode)); 
	temp->l = temp->r = NULL; 
	temp->d = d; 
	temp->f = f; 
	return temp; 
} 


struct min_heap* create_min_heap(int c) 
{ 
	struct min_heap* min_heap = (struct min_heap*)malloc(sizeof(struct min_heap)); 
	min_heap->s = 0; 
	min_heap->c = c; 
	min_heap->array = (struct MHNode**)malloc(min_heap->c * sizeof(struct MHNode*)); 
	return min_heap; 
} 


void min_heapify(struct min_heap* min_heap, int i) 
{ 
	int smallest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < min_heap->s && min_heap->array[l]->f < min_heap->array[smallest]->f) 
		smallest = l; 

	if (r < min_heap->s && min_heap->array[r]->f < min_heap->array[smallest]->f) 
		smallest = r; 

	if (smallest != i) { 
		swap(min_heap->array[smallest], min_heap->array[i]); 
		min_heapify(min_heap, smallest); 
	} 
} 


int issOne(struct min_heap* min_heap) 
{ 
	return (min_heap->s == 1); 
} 


struct MHNode* extractMin(struct min_heap* min_heap) 
{ 
	struct MHNode* temp = min_heap->array[0]; 
	min_heap->array[0] = min_heap->array[min_heap->s - 1]; 
	--min_heap->s; 
	min_heapify(min_heap, 0); 
	return temp; 
} 


void insertmin_heap(struct min_heap* min_heap, struct MHNode* MHNode) 
{ 
	++min_heap->s; 
	int i = min_heap->s - 1; 
	while (i && MHNode->f < min_heap->array[(i - 1) / 2]->f) 
	{ 
		min_heap->array[i] = min_heap->array[(i - 1) / 2]; 
		i = (i - 1) / 2; 
	} 
	min_heap->array[i] = MHNode; 
} 


void buildmin_heap(struct min_heap* min_heap) 
{ 
	int n = min_heap->s - 1; 
	int i; 
	for (i = (n - 1) / 2; i >= 0; --i) 
		min_heapify(min_heap, i); 
} 


void printArr(int arr[], int n) 
{ 
	int i; 
	for (i = 0; i < n; ++i) 
		cout<< arr[i]; 

	cout<<"\n"; 
} 


int isLeaf(struct MHNode* root) 
{ 
	return !(root->l) && !(root->r); 
} 


struct min_heap* createAndBuildmin_heap(char d[], int f[], int s) 
{ 
	struct min_heap* min_heap = create_min_heap(s); 

	for (int i = 0; i < s; ++i) 
		min_heap->array[i] = newNode(d[i], f[i]); 

	min_heap->s = s; 
	buildmin_heap(min_heap); 

	return min_heap; 
} 



struct MHNode* buildHuffmanTree(char d[], int f[], int s) 
{ 
	struct MHNode *l, *r, *top; 

	struct min_heap* min_heap = createAndBuildmin_heap(d, f, s); 
 
	while (!issOne(min_heap)) { 

		l = extractMin(min_heap); 
		r = extractMin(min_heap); 

		top = newNode('$', l->f + r->f); 

		top->l = l; 
		top->r = r; 

		insertmin_heap(min_heap, top); 
	} 

	return extractMin(min_heap); 
} 


void printCodes(struct MHNode* root, int arr[], int top) 
{ 
	if (root->l) { 
		arr[top] = 0; 
		printCodes(root->l, arr, top + 1); 
	} 

	if (root->r) { 

		arr[top] = 1; 
		printCodes(root->r, arr, top + 1); 
	} 

	if (isLeaf(root)) { 

		cout<< root->d <<": "; 
		printArr(arr, top); 
	} 
} 


void HuffmanCodes(char d[], int f[], int s) 
{ 
	struct MHNode* root 
		= buildHuffmanTree(d, f, s); 

	int arr[H], top = 0; 
	printCodes(root, arr, top); 
} 


int main() 
{ 

	int s;
	cin >> s;
	char arr[s];
	int f[s];

	for(int i = 0; i < s; i++)
		cin >> arr[i] >> f[i];

	HuffmanCodes(arr, f, s); 

	return 0; 
} 
