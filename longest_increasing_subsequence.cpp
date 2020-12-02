#include<bits/stdc++.h>
using namespace std;

// >> variations 

// bridges 
// maximum sum subsequence 
// maximmum chain length - elements are pairs (a, b), (c, d) chain is formed when b < c , given a < b and d > c alwauys 
// bitonic sequence

// O(n*n)
int LIS() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp(n, 1);
    int lis = 1;

    for(int i = 1; i < n; i++) {   
        for(int j = 0; j < i; j++) {
            if(v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        lis = max(lis, dp[i]);
    }
    return lis;
}

// O(nlog(n))
int LIS2(vector<int> a) {
    vector<int> v;
    for (int i = 0; i < a.size(); i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if (it != v.end()) 
            *it = a[i];
        else 
            v.push_back(a[i]);
    }
    return v.size();
}



// Couting number of longest increasing subsequence 

// O(n*n)
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    
    // cnt[i][len] = number of increasing sequence of length len ending at i  
    vector<vector<int>> cnt(n, vector<int>(n+1, 0));
    for(int i=0; i<n; i++) {
        cnt[i][1] = 1;
    }
    
    int lis = 1;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                int len = dp[j] + 1;
                dp[i] = max(dp[i], len);
                // add sequences 
                cnt[i][len] += cnt[j][len-1];
            }
        }
        lis = max(lis, dp[i]);
    }
    
    // finally count all the subsequence of length lis, ending at any index
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += cnt[i][lis];
    }
    return ans;
}




// > Similar Problem 
// find largest bitonic sequence, (first increasing and then decreasing or only inc or only dec)
// >  Solution 
// find lis array from left 
// find list array from right 
// find max(left[i] + right[i] - 1)

// printing the longest bitonic sequence 
void printBitonic() {
        int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    
    vector<int> inc(n, 1);
    vector<int> dec(n, 1);
    vector<int> incPath(n, 0);
    auto decPath = incPath;

    for(int i=0; i<n; i++) {
        incPath[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if(a[i] > a[j] && inc[j] + 1 > inc[i]) {
                inc[i] = inc[j] + 1;
                incPath[i] = j;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if(a[i] > a[j] && dec[j] + 1 > dec[i]) {
                dec[i] = dec[j] + 1;
                decPath[i] = j;
            }
        }
    }

    int ans = 1, j = 0;
    for (int i = 0; i < n; i++) {
        int curr = inc[i] + dec[i] - 1;
        if(curr > ans) {
            ans = curr;
            j = i;
        }
    }

    cout << ans << endl;
    stack<int> temp;

    int st = j;
    while (incPath[st] != st) {
        temp.push(a[st]);
        st = incPath[st];
    }
    vector<int> res;
    
    while(!temp.empty()) {
        res.push_back(temp.top());
        temp.pop();
    }
    res.pop_back();

    st = j;
    while(decPath[st] != st) {
        res.push_back(a[st]);
        st = decPath[st];
    }

    for(auto val: res) {
        cout << val << " ";
    }
}