

#include<bits/stdc++.h>
using namespace std;

// Find longest fibonacci-like sub-sequence in the array 
// Ex - 2 6 8 14 22  

// ~ O(n^3), space O(n)
int lenLongestFibSubseq(vector<int>& a) {
    unordered_set<int> ust(a.begin(), a.end());
    int ans = 0, n = a.size();
    int maxEl = a[n-1];
    
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            
            int s = a[i] + a[j];
            // optimization
            if(s >= maxEl) {  
                break;
            }
            
            int x1 = a[i], x2 = a[j], x3 = x1 + x2;
            int curr = 2;
            // optimization - x3 <= maxEl
            while(ust.count(x3) && x3 <= maxEl) {
                curr += 1;
                x1 = x2;
                x2 = x3;
                x3 = x1 + x2;
            }
            if(curr >= 3) {
                ans = max(ans, curr);
            }
        }
    }
    
    return ans;
}


// O(n^2), space O(n^2)

int lenLongestFibSubseq(vector<int>& a) {

    int n = a.size();
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(n));
    
    for(int i = 2; i<n; i++) {
        
        // Just two classic pointer to find the 2-sum
        int st = 0, en = i-1;        
        while(st < en) {
            int sum = a[st] + a[en];
    
            if(sum > a[i]) {
                en -= 1;
            
            } else if(sum < a[i]) {
                st += 1;
            
            } else {
                // important state transition
                dp[en][i] = dp[st][en] + 1;
                ans = max(ans, dp[en][i]);
                en -= 1;
                st += 1;
            }
        }
    }
    
    return ans == 0 ? 0: ans + 2;
}

int main() {

}