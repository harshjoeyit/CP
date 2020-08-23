
/*
Split the given array into K continuous sub-arrays 
such that maximum sum of all sub arrays is minimum
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5+10;
int n, k, a[mxN];

bool checkMidPossible(int mid) {                
    // check if the array can be split with mid
    int cnt = 0, s = 0;                        
    
    for(int i=0; i<n; i++) {
        // any array values must be less than equal to mid
        if(a[i] > mid)                                                        
            return 0;
        s += a[i];
        if(s > mid) {
            ++cnt;
            s = a[i];
        }
    }
    // for the last subarray that remain uncounted
    ++cnt;                                      
    
    if(cnt <= k)                
        return 1;               
    return 0;
}

int split() {
    int low = 1, high = 0, ans = 0, mid;             
    for(int i=0; i<n; i++)
        high += a[i];
    
    while(low <= high) {
        mid = (low + high)/2;
        // mid = maximmum of sum of the all subarray sums

        if(checkMidPossible(mid)) {             
            // split cnt is <= k          
            ans = mid;
            high = mid-1;
        } else {                                
            // means subarray can be divided into more than k parts with mid
            low = mid+1;
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