
/*
Exmaples of array - 
2 3 4 5 6 1
4 5 6 1 2 3
8 9 1 2 3 4 6 7
1 2 3
*/

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
    int l = 0, h = n-1, mid;
    while(l < h) 
    { 
        int mid = l + (h - l)/2; 
        if (arr[mid] == arr[h]) 
            h--; 
        else if(arr[mid] > arr[h]) 
            l = mid + 1; 
        else
            h = mid; 
    } 
    cout << arr[h] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}