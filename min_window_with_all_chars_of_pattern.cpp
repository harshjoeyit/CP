
/*
IMP PIR
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long


// Using Binary Search (find only size)

// check if all chars of pat are present in s
bool search_window(int i, int j, string s, string pat) {
    if(j - i + 1 < pat.length()) {
        return false;
    }
    unordered_map<char, bool> present;
    int cnt = 0;

    for(int k = i; k <= j; k++ ) {
        present[s[k]] = true;
    }
    for(int i = 0; i < pat.length(); i++ ) {
        if(present[pat[i]])
            ++cnt;
    }
    return cnt == pat.length();
}

// search all substrings of given wind_size 
bool current_window(int wind_size, string s, string pat) {
    int n1 = s.length();

    for(int i = 0; i < n1-wind_size; i++ ) {
        if(search_window(i, i + wind_size, s, pat)) {
            return true;
        } 
    }
    return false;
}

// bin-search on window size 
int min_window_size(int l, int h, string s, string pat) {
    int ans = -1;
    while(l <= h) {
        int mid = l + (h-l)/2;

        if(current_window(mid, s, pat)) {
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans+1;           
    // returns 0 if the if substring is not found in the string 
}

void minWindowSize() {
    string pat = "abcde";
    string s = "alllllllelcdlballllllclldl";
    cout << s.size() << endl; 
    cout << min_window_size(0, s.length()-1, s, pat )<<endl;
}



// Using window sliding (find substring, window)

// find smallest window in str that contains all the chars of pat
// all chars means repitions too 
string find_window(string s, string pat) {
    
    if(s.length() < pat.length()) {
        return "";
    }  

    const int mxN = 256;
    vector<int> shash(256, 0), phash(256, 0);

    for(int i=0; i<pat.length(); i++) {
        ++phash[pat[i]];
    }

    int count = 0, l = 0, ansLeft = -1, minLen = INT_MAX;

    for(int j=0; j<s.length(); j++) {
    
        shash[s[j]]++;

        if (phash[s[j]] != 0 && shash[s[j]] <= phash[s[j]]) {
            // if char is present in pat 
            // if char present then do we have enough in our shash 
            count++;
        }   

        if(count == pat.length()) {
            // s[l...i] has all chars of pat, 
			// buts lets try to reduce the window from the right side 
            while (shash[s[l]] > phash[s[l]] || phash[s[l]] == 0) {
                if (shash[s[l]] > phash[s[l]]) {
                    shash[s[l]]--; 
                }
                l++; 
            }
            // optimal window
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



// Similar problems ...
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

// Return the number of substrings containing at least one 
// occurrence of all these characters a, b and c.

// string contains only a, b, c

int numberOfSubstrings(string s) {
    int n = s.length();
    int count[3] = {0, 0, 0};
    int ans = 0 , i = 0; 
    
    for (int j = 0; j < n; ++j) {
        ++count[s[j] - 'a'];
        while (count[0] && count[1] && count[2])
            --count[s[i++] - 'a'];
        
        // important observation here is `i` number of substring are added 
        ans += i;
    }
    return ans;
}

// ...


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
