//?https://leetcode.com/problems/longest-consecutive-sequence/
#include<bits/stdc++.h>
using namespace std;

// T.C - O(n) and S.C - O(n)
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> ump;
    for(int i = 0; i < nums.size(); i++) {
        if(ump.find(nums[i]) != ump.end())
            continue;
        int len1 = 0;
        int len2 = 0;
        
        if(ump.find(nums[i] - 1) != ump.end())
            len1 = ump[nums[i] - 1];
        if(ump.find(nums[i] + 1) != ump.end()) {
            len2 = ump[nums[i] + 1];
        }
        int newStreakLength = 1 + len1 + len2;
        if(ump.find(nums[i]) != ump.end()) {
        newStreakLength = len1 + 1;
    }
        ump[nums[i]] = newStreakLength;
        ump[nums[i] - len1] = newStreakLength;
        ump[nums[i] + len2] = newStreakLength; 
    }
    int ans = 0;
    for(auto p : ump) {
        ans = max(ans, p.second);
    }
    return ans;
    
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a)
        cin >> x;
    cout << longestConsecutive(a) << endl;; 
    
}