
/*
find number of substring that can be changed to palindromes on shuffling

solution: 
For a substring to be palindromic atmost one character can appear odd times. 
You can represent the status for each of the 26 characters using 26 bits 
(if a character appears even times then it's status can be 0 and if it appears 
odd times it's status can be 1). For every point  find the number of palindromic 
substrings ending at this point. This can be done by hashing the prefix "mask".
At each point  you have to look for 27 different types of strings

string having all characters with even count i.e, mask would be 00......26 times
string having all characters with even count except 'a' i.e, mask would be 0000....1  Similary for characters upto 'z'.

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve() {
    string s;
    cin >> s;
    int x = 0;
    unordered_map<int , int> ump;
    int ans = 0;
    ump[0] = 1;
    
    for(auto c: s) {
        int val = c-'a';
        x ^= (1 << val);
        if(ump.count(x))
            ans += ump[x];
        for(int j=0; j<26; j++)
            if(ump.count(x^(1<<j)))
                ans += ump[x^(1<<j)];
        if(ump.count(x) == 0)
            ump[x] = 0;
        ump[x] += 1;
    }
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}