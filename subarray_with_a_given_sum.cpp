#include <bits/stdc++.h>
using namespace std;

/*
O(n) space method 
Use a map to store the prefix sums and 
check, just like when we do counting of subarrays with a sum
*/


/*
O(1) Space method 
Use Two pointers 
*/

const int mxN = 1e6+2; 
int a[mxN], n, s, st, en;

// for non-neg values only
// for neg values use count subarrays option

void solve() {
    cin >> n >> s;
    st = 0, en = 0;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(i > 1) {
            // a[i] stores sum a[0...i]
            a[i] += a[i-1];
        }
        if(a[i] >= s && en == 0) {
            en = i;
        }
    }
    
    bool f = 0;
    while(en <= n) {
        if(a[en] - a[st] == s) {
            // subarray from st+1, en has sum = s
            f = 1;
            break;
        } else if(a[en] - a[st] > s) {
            // decrease the window
            ++st;
        } else if(a[en] - a[st] < s) {
            // increase the window
            ++en;
        }
    }   
    if(f == 1) {
        cout << st+1 << " " << en << "\n";                // print range where the sum is found - 1 indexed  
    } else {
        cout << -1 << "\n";
    }
}


// ..........................................................................................
// Finding Min length subarray with a given sum 

// Using lower bound (nlogn)
int minSubArrayLen(int s, vector<int>& nums) {    
    auto prefix = nums;
    int n = prefix.size();
    
    for(int i=1; i<n; i++) {
        prefix[i] += prefix[i-1];
    }
    
    int ans = 2*n;
    
    for(int i=0; i<n; i++) {
        int sum = prefix[i] + s - nums[i];
        
        auto it = lower_bound(prefix.begin(), prefix.end(), sum);
        if(it == prefix.end()) {
            break;
        }
        
        int len = it - (prefix.begin() + i) + 1;
        ans = min(ans, len);
    }
    
    return (ans == 2*n) ? 0 : ans;
}


// Two pointers 
int minSubArrayLen(int s, vector<int>& nums) {
    int ans = 2*nums.size(), n = nums.size();
    int st = 0, en = 0, curr = 0;
    
    while(en < n) {
        curr += nums[en];
        while(curr >= s) {
            ans = min(ans, en - st + 1);
            curr -= nums[st];
            st += 1;
        }
        en += 1;
    }
    
    return (ans == 2*n) ? 0 : ans;
}

// ...................................................................................

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) 
	    solve();
	
	return 0;
}