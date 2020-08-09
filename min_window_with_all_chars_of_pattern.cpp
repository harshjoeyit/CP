
/*
IMP PIR
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mxN = 256;

// find smallest window in str that contains all the chars of pat
// all chars means repitions too 
string find_window(string s, string pat) {
    int n = s.length();
    int m = pat.length();

    if(n < m) {
        // return blank string
        return "";
    } 

    // depends on the char present in the string 
    const int mxN = 256;
    int hashPat[mxN] = {0};
    int hashStr[mxN] = {0};

    for(int i=0; i<m; i++) {
        ++hashPat[pat[i]];
    }

    int l = 0, ansLeft = -1, minLen = INT_MAX;
    int count = 0;

    for(int j=0; j<n; j++) {
    
        hashStr[s[j]]++;

        // checking 
        // if char is present in pat and has count hashPat[s[j]]
        // so count of that char is hashStr[s[i]] is less than or equal to required
        if (hashPat[s[j]] != 0 && hashStr[s[j]] <= hashPat[s[j]]) {
            count++;
        } 

        // all chars are present in current window 
        // whenever this runs it means that current string hash has more 
        // or equal char required that are in pat
        if(count == m) {
            //minimize window from left
            // either count of char is greater than required or the char is not present in pat
            while ( hashStr[s[l]] > hashPat[s[l]] || hashPat[s[l]] == 0) {
                
                if (hashStr[s[l]] > hashPat[s[l]]) {
                    hashStr[s[l]]--; 
                    // delete this char from window, and the condition is still fulfilled
                }
                // move the left pointer to right 
                l++; 
            }
            // update window size 
            // we can work even without right pointer, only left pointer and length does the job 
            int wind = j - l + 1; 
            if (minLen > wind) { 
                minLen = wind; 
                ansLeft = l; 
            } 
        }
    }

    if(ansLeft == -1) {
        return "";
    }

    return s.substr(ansLeft, minLen);
}


// brute force approach 
bool matchHash(vector<int> &tHash, vector<int> &sHash) {
      for(int i=0; i<256; i++) {
            if(sHash[i] < tHash[i]) {
                  return false;
            }
      }
      return true;
}
string minWindow(string s, string t) {
      if(s.length() == 0 || t.length() == 0 || s.length() < t.length()) {
            return "";
      }

      vector<int> tHash(256, 0), sHash(256, 0);
      for(auto &c: t) {
            tHash[c] += 1;    
      } 

      int slen = s.length();
      int tlen = t.length();
      int left=0, ansL=0, ansR=-1, ansLen=slen;

      for(int i=0; i<slen; i++) {
            sHash[s[i]] += 1;
            if(i >= tlen-1) {
                  while(matchHash(tHash, sHash)) {
                        if(i - left + 1 < ansLen) {
                              ansLen = i - left + 1;
                              ansL = left;
                              ansR = i;
                        }
                        sHash[s[left]] -= 1;
                        left++;
                  }
            }
      }
      if(ansR == -1) {
            return "";
      }      
      return s.substr(ansL, ansLen);
}



void solve() {
    string s, t;
    cin >> s >> t;

    // better algo
    cout << find_window(s, t) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}
