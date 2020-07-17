#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// O(log(n))
void maxHeapify(int arr[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest]) {
		largest = l;
	}
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}
}

// O(n) - read complexity proof
void buildMaxHeap(int arr[], int n) {
	// n/2-1 is the first parent that can be max heapifed 
	// af this all the elements are child/leaf
	for (int i = n / 2 - 1; i >= 0; i--)
		maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n) {
	buildMaxHeap(arr, n);
	for (int i = n - 1; i > 0; i--) {
		// arr[0] is the largest element	
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}


int main() {
	int arr[] = {7, 2, 8, 1, 4, 3, 6};
	int n = sizeof(arr) / sizeof(arr[0]);

	// to sort in increasing order - maxHeap
	// to sort in descending order - minHeap
	heapSort(arr, n);
	cout << "Sorted array is \n";
	printArray(arr, n);
}
