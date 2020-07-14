#include<bits/stdc++.h>
using namespace std;

#define int long long 

void print(int a[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << a[i] << " ";
    cout << "\n";
}

// partition [l, r]
int Partition(int a[], int l, int r) {                  
    int pivot = r;
    int pindex = l;

    for(int i=l; i<=r-1; i++) {
        if(a[i] <= a[pivot]) {
            swap(a[i], a[pindex]);
            ++pindex;
        }
    }
    swap(a[r], a[pindex]);
    return pindex;
}
int randPartition(int a[], int l, int r) {
    int len = r-l+1;
    int i = l + (rand() % len);
    swap(a[i], a[r]);

    return Partition(a, l, r);
}

// worst case - O(n*n), average - O(n)
int kthSmallestUsingPartition(int arr[], int l, int r, int k)  { 
    if (k > 0 && k <= r - l + 1) { 
        int pos = randPartition(arr, l, r); 

        if (pos - l == k - 1) {
            return arr[pos]; 
        }
        // If position is more, recur for left subarray
        if (pos - l > k - 1) {
            return kthSmallestUsingPartition(arr, l, pos-1, k);
        } 
        // pos-l+1 is the length already covered new k = k-length covered 
        // so go for remaining length with remaining k
        return kthSmallestUsingPartition(arr, pos+1, r, k - (pos-l+1)); 
    } 
    
    //  for invalid k
    return INT_MAX;             
} 
  
// O(n + k*log(n))
int kthSmallestUsingMinHeap(int a[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // O(n) time to build heap
    for(int i=0; i<n; i++) {
        minHeap.push(a[i]);
    }
    // removing the k-1 smaller elements
    // k*log(n) time to remove
    for(int i=0; i<k-1; i++) {
        minHeap.pop();
    }
    // topmost in the kth smallest
    return minHeap.top();
}

// O(k + (n-k)*Logk)
int kthSmallestUsingMaxHeap(int a[], int n, int k) {
    priority_queue<int> maxHeap;
    // pushing first k elements
    // o(k) time to create heap of k elements
    for(int i=0; i<k; i++) {
        maxHeap.push(a[i]);
    }
    // heap has only k elements at all the time
    // pushing (n-k) elements on worst case 
    // on the heap of at most k elements 
    for(int i=k; i<n; i++) {
        // remove the larger elements from the heap 
        // if the smaller is found
        if(a[i] < maxHeap.top()) {
            maxHeap.pop();
            maxHeap.push(a[i]);
        }
    }
    // the topmost is the kth smallest
    return maxHeap.top();
}

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << kthSmallestUsingPartition(a, 0, n-1, k) << endl;
    cout << kthSmallestUsingMinHeap(a, n, k) << endl;
    cout << kthSmallestUsingMaxHeap(a, n, k) << endl;
}

signed main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    srand(time(0));
    int t;
    cin >> t;
    while(t--)
        solve();
}