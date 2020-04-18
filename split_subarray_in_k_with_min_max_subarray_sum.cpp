
/*
Split the given array into K sub-arrays 
such that maximum sum of all sub arrays 
is minimum
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;
int n, k, a[mxN];

bool checkMidPossible(int mid) {                // check if the array can be split with mid
    int cnt = 0, s = 0;                         // counting the split arrays
    
    for(int i=0; i<n; i++) {
        if(a[i] > mid)                          // any array values must be less than equal to mid                              
            return 0;
        s += a[i];
        if(s > mid) {
            ++cnt;
            s = a[i];
        }
    }
    ++cnt;                                      // for the last subarray that remain uncounted
    
    if(cnt <= k)                
        return 1;               
    return 0;
}

int split() {
    int s = 1, e = 0, ans = 0, mid;             // mid = maximmum of sum of the all subarray sums
    for(int i=0; i<n; i++)
        e += a[i];
    
    while(s <= e) {
        mid = (s+e)/2;

        if(checkMidPossible(mid)) {             // split cnt is <= k          
            ans = mid;
            e = mid-1;
        } else {                                // means subarray can be divided into more than k parts with mid
            s = mid+1;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int maxSum = split();
    cout << maxSum << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}