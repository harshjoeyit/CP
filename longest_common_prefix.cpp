long
/*
longest common prefix 

1. using trie - 
https://leetcode.com/problems/longest-common-prefix/discuss/647717/Try-TRIE-!!-Interviewer-likes-the-approach-to-build-prefixes.

*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// 2. brute force approach 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() == 0) {
            return "";
        }
        if(strs.size() == 1) {
            return strs[0];
        }
        
        int minsize = INT_MAX;
        for(auto s: strs) {
            minsize = min(minsize, (int)s.size());
        }
        
        for(int j=0; j<minsize; j++) {
            for(int i=0; i<strs.size()-1; i++) {
                if(strs[i][j] != strs[i+1][j]) {
                    return strs[0].substr(0, j);
                }
            }
        }
                                    
        return strs[0].substr(0, minsize);
    }
};


// 3. using divide and conquer 
string common(string s1, string s2)
{
    string result;
    int i = 0;
    
    while(s1[i] && s2[i])
    {
        if(s1[i] == s2[i])
            result.push_back(s1[i]);
        else
            break;    
        
        i++;
    }
    
    return result;
}

string helper(vector<string>& strs, int left, int right)
{
    // If only one string simply return that.
    if(left == right)
        return strs[left];
    
    // If more than one string recurse by dividing the array into 2 parts. 
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        
        // This is the left part of the array and the answer to this sub-problem is common prefix l_s
        string l_s = helper(strs, left, mid);
        
        // This is the right part of the array and the answer to this sub-problem is common prefix r_s
        string r_s = helper(strs, mid + 1, right);
        
        // Now we need to find the common between the left sub-problem answer l_s and the right sub-problem 
        // answer r_s.
        return common(l_s, r_s);
        
    }
    
    return "";
}

string longestCommonPrefix(vector<string>& strs) {
    
    if(strs.size() == 0)
        return "";
    
    return helper(strs, 0, strs.size() - 1);
        
}