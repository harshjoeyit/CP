
/*
similar problems 
- subarrays with at most/excatly k uniq numbers  
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

// O(n*n) approach 
// substring with at least k uniq characters 
int kUniqueSubstrings(string s, int k) {
    int n = (int)s.length();
    if(n < k) {
        return 0;
    }

    int ans = 0;
    unordered_set<char> st;

    // check for each substring 
    for(int i=0; i<n; i++) {
        st.clear();
        
        for(int j=i; j<n; j++) {
            st.insert(s[j]);    
            if(st.size() == k) {
                // add until the unique chars are k
                // thus we add all the substring that have k uniqu chars 
                // and start from j 
                ++ans;
            } else if(st.size() > k) {              // break if uniq chars > k
                break;
            }
        }
    }
    return ans;
}


// At most k different chars 
// O(n) apprach
int atMostKUnique(string &s, int k) {
    int n = (int)s.length();
    unordered_map<char, int> ump;
    int ans = 0, left = 0;

    for(int i=0; i<n; i++) {
        ump[s[i]] += 1;
        while (ump.size() > k) {
            // our window has more tha k unique chars 
            // so move left to correct pos 
            ump[s[left]] -= 1;
            if(ump[s[left]] == 0) {
                ump.erase(s[left]);
            }
            left += 1;
        }
        // our window has <= k uniq chars 
        ans += i - left + 1;
    }

    return ans;
}


// O(n) approach 
// exactly k uniq chars 
int kUniqueSubstringsFaster(string &s, int k) {
    return atMostKUnique(s, k) - atMostKUnique(s, k-1);
}


void solve() {
    string s;
    int k;
    cin >> s >> k;

    // slower 
    cout << kUniqueSubstrings(s, k) << "\n";

    // faster 
    cout << kUniqueSubstringsFaster(s, k) << "\n";
}

signed main() {
    solve();
}
