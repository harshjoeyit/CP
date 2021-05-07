#include<bits/stdc++.h>
using namespace std;

/*
    1.1 Find minimum window in str that contains all the chars of pat
*/
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

/*
    1.2 Using Binary Search (find only size)
*/

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


/*
    Find min window in str that contains ALL THE UNIQUE chars present in it
    https://www.geeksforgeeks.org/smallest-window-contains-characters-string/
*/
/*
    2.0 Hashing - find freq of char of each substring and compare its size with uniq chars in string
*/

/*
    2.1 Sliding Window and hashing 
*/
string findSubString(string str) {
    unordered_set<char> uniq;
    unordered_map<char, int> cnt;
    for(auto c: str) {
        uniq.insert(c);
    }
    
    int l = 0, minLen = str.length(), ansL = 0;

    for(int i=0; i<str.length(); i++) {
        cnt[str[i]]++;
        while(cnt.size() >= uniq.size()) {
            int currWindow = i-l+1;
            if(currWindow < minLen) {
                minLen = currWindow;
                ansL = l;
            }
            int ch = str[l];
            cnt[ch]--;
            l++;

            if(cnt[ch] == 0) {
                cnt.erase(ch);
            }
        }
    }
    return str.substr(ansL, minLen);
}

/*
    Another implentation
*/
string findSubString(string str) {
    int n = str.length(), dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }
 
    int count = 0, start = 0, ans_start = -1, min_len = INT_MAX;
    int curr_count[MAX_CHARS] = { 0 };

    for (int j = 0; j < n; j++) {
        // Count occurrence of characters of string
        curr_count[str[j]]++;
        // If any distinct character matched, then increment count
        if (curr_count[str[j]] == 1) {
            count++;
        }
        // if all the characters are matched
        if (count == dist_count) {
            // Try to minimize the window i.e.
            while (curr_count[str[start]] > 1) {
                curr_count[str[start]]--;
                start++;
            }
            // Update window size
            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                ans_start = start;
            }
        }
    }

    return str.substr(ans_start, min_len);
}

/*
    number of substrings containing at least one occurrence of all these characters a, b and c.
    string contains only a, b, c
    https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
*/
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

int main() {
}