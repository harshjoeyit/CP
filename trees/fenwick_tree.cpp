#include<bits/stdc++.h> 
using namespace std; 

int getSum(int tree[], int i) {  
    int s = 0;
    for(++i; i > 0; i -= i&-i)
        s += tree[i];
    return s;
} 

void update(int tree[], int n, int i, int x) { 
    for(++i; i <= n; i += i&-i)
        tree[i] += x;
} 

int rangeSum(int tree[], int l, int r) {
    return (getSum(tree, r) - getSum(tree, l-1));
}   

int *constructtree(int arr[], int n) {
	int *tree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		tree[i] = 0; 

	for (int i=0; i<n; i++) 
		update(tree, n, i, arr[i]); 

	return tree; 
} 


int main() {
	int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *tree = constructtree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "<< getSum(tree, 5) << endl; 

    cout << "range sum: " << rangeSum(tree, 3, 6) << endl;

	// Let use test the update operation 
	freq[3] += 6; 
	update(tree, n, 3, 6); //Update BIT for above change in arr[] 
	cout << "Sum of elements in arr[0..5] after update is " << getSum(tree, 5) << endl; 



//.. another example


    int *tree2 = new int[11];       // constructed on some array[10]

    for(int i = 0;  i < 11; i++)
        cout << tree2[i] << " ";
    cout << endl;

    update(tree2, 10, 3, 1);
    update(tree2, 10, 5, 1);
    update(tree2, 10, 0, 1);

    for(int i = 0;  i < 11; i++)
        cout << tree2[i] << " ";
    cout << endl;

    cout << rangeSum(tree2, 1, 5) << endl;
    cout << rangeSum(tree2, 0, 3) << endl;
    cout << rangeSum(tree2, 0, 9) << endl;
} 



//..................fenwick tree for 1 based indexed array..........



// int getSum(int tree[], int i) {  
//     int s = 0;
//     for(i; i > 0; i -= i&-i)
//         s += tree[i];
//     return s;
// } 

// void update(int tree[], int n, int i, int x) { 
//     for(i; i <= n; i += i&-i)
//         tree[i] += x;
// } 

// int rangeSum(int tree[], int l, int r) {
//     return (getSum(tree, r) - getSum(tree, l-1));
// }  

// int main(){

//     int n = 6;
//     int a[n+1];

//     for(int i = 1; i <= n; i++)
//         cin >> a[i];

//     int *tree = new int[n+1]; 
//     for(int i = 1; i <= 6; i++)
//         update(tree, n, i, a[i]);
    
//     cout << rangeSum(tree, 2, 5) << endl;
// }
