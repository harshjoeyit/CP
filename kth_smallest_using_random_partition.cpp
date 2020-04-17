#include<bits/stdc++.h>
using namespace std;

#define int long long 

void print(int a[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int Partition(int a[], int l, int r) {                  // partition [l, r]
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

int kthSmallest(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) { 
    
        int pos = randPartition(arr, l, r); 

        if (pos - l == k - 1) 
            return arr[pos]; 
        if (pos - l > k - 1)                // If position is more, recur for left subarray 
            return kthSmallest(arr, l, pos - 1, k); 
  
        // pos-l+1 is the length already covered new k = k-length covered 
        return kthSmallest(arr, pos + 1, r, k - (pos-l+1) ); 
    } 
  
    return INT_MAX;             //   for k > n;
} 
  

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cout << kthSmallest(a, 0, n-1, k) << endl;

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