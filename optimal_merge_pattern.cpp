#include<bits/stdc++.h>
using namespace std;

int n;

void min_heapify(int a[], int i) {
	int l = 2 * i;
	int r = 2 * i + 1;
	int smallest = i;
	
	if(l < n && a[l] < a[smallest])
		smallest = l;
	
	if(r < n && a[r] < a[smallest])
		smallest = r;
		
	if(smallest != i) {
		swap(a[smallest], a[i]);
		min_heapify(a, smallest);
	}
}

int extract_min(int a[]) {
	int x = a[1];
	swap(a[1],a[n]);
	n--;
	min_heapify(a, 1);
	return x;
}

void build_min_heap(int a[]) {
	for(int i = n/2; i >= 1; i--)
		min_heapify(a, i);
}

void insert_key(int a[], int key) {
	++n;
	a[n] = a[1];
	a[1] = key;
	min_heapify(a, 1);
}

void print(int a[], int l, int h) {	
	for(int i = l; i <= h; i++)
		cout << a[i] << " ";
	cout << endl;
}

int optimal_merge_pattern(int a[]) {
	int op_cost = 0;
	build_min_heap(a);

	while(n >= 2) {
		int v1 = extract_min(a);
		int v2 = extract_min(a);
		op_cost += v1+v2;
		insert_key(a, v1+v2);
	}
	return op_cost;
}


int main() {
	int a[1000];
	cin >> n;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	cout << "optimal cost: " << optimal_merge_pattern(a) << endl;
}



