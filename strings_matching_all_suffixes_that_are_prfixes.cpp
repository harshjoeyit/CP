
/*
Your task is, for any prefix of string s which matches a suffix of string s, 
print the number of times it occurs in string s as a substring.

example 
prefixes that are suffixes too

for ABACABA
A, ABA, ABACABA

for ABABAB
AB, ABAB, ABAB

for ABCD
ABCD
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i=1, l=0, r=0; i<n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);       
        // segment should not stretch out of the array while copying previous values so (r-i+1)
        
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        
        // i + z[i] - 1 = rightmost index of the segment
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
      string s;
      cin >> s;
      auto z = z_function(s);
      int n = z.size();
      // stores frequency of the each prefix(that occurs as a substring) of length i (0, n)  
      vector<int> freq(n+1, 0);
      // sotres the all lengths fro which a suffix if a prefix too 
      vector<int> valid_len;              
      
      for(int i=n-1; i >=0 ; i--) {
            // found a suffix that is prefix
            if(z[i] == n-i) {
                  valid_len.push_back(n-i);
            }
            // storing freq for every length
            if(z[i] > 0) {
                  freq[z[i]] += 1;
            }
      }
      // n is also a valid length
      valid_len.push_back(n);

      // if there exists a substring of length i matching with prefix of length i, 
      // then there must exit a substrin of length i-1 matching with prefix of length i-1
      for(int i=n-2; i >=0; i--) {
            freq[i] += freq[i+1];
      }
      
      cout << valid_len.size() << endl;
      for_each(valid_len.begin(), valid_len.end(), [&](int &l){ cout << l << " " << (freq[l]+1) << "\n"; });
      
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}