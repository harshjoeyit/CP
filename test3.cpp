#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int low = 0, high = n-1, mid;
    while(low < high) 
    { 
        int mid = low + (high - low)/2; 
        if (arr[mid] == arr[high]) 
            high--; 
        else if(arr[mid] > arr[high]) 
            low = mid + 1; 
        else
            high = mid; 
    } 
    cout << arr[high] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}