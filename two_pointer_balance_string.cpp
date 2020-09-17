
/*
https://leetcode.com/problems/replace-the-substring-for-balanced-string/

Balance String 

A string is said to be balanced if each of its characters appears n/4 times where n is the length of the string.

Return the minimum length of the substring that can be replaced with any other string of 
the same length to make the original string s balanced.

Return 0 if the string is already balanced.
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int balancedString(string s) {
        unordered_map<int, int> count;
        for(auto c: s) {
            count[c] += 1;
        }
        // int the beginning all chars are outside the window and window is of 0 length
        // the window is b/w [l ,r]
        // we are concered whether all the chars 
        // outside the window are  n/4 or not 

        int n = s.length();
        int ans = n, l = 0, k = n/4;
        
        for(int r=0; r<n; r++) {
            // window moves forward, this char is removed from window 
            count[s[r]]--;
            while (l < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
                // when this while runs it means that means 
                // it is a valid substring to remove 
                // but can we reduce it even more, from the left?
                ans = min(ans, r - l + 1);
                count[s[l++]]  += 1;
            }
        }
        return ans;
    }
    
};

int main() {
    string s;
    cin >> s;
    cout << balancedString(s);
}