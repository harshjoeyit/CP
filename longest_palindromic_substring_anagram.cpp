
/*
https://www.geeksforgeeks.org/longest-substring-whose-characters-can-be-rearranged-to-form-a-palindrome/

find longest substring that is a plaindromic anagram 
i.e longest substring that can be rearranged to become palindrome
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    unordered_map<int, int> index;

    int mask = 0;
    index[0] = -1;
    int ans = 1;

    for (int i = 0; i < s.length(); i++) {
        int bit = s[i] - 'a';
        mask ^= (1 << bit);
        
        if(index.count(mask)) {
            ans = max(ans, i - index[mask]);
            continue;
        }

        for (int j = 0; j < 26; j++) {
            int temp = mask ^ (1 << j);
            if(index.count(temp)) {
                ans = max(ans, i - index[temp]);
            }
        }

        if(index.count(mask) == 0) {
            index[mask] = i;
        }
    }

    cout << ans << endl;
}