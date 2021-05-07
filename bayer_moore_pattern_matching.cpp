#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

vector<int> findLastOccur(string &s) {
    vector<int> lastOcc(MAX_CHARS, -1);
    for(int i=0; i<s.length(); i++) {
        lastOcc[s[i]] = i;
    }
    return lastOcc;
}

// Using Bad heuristics 
void bayerMoore(string &s, string &pat) {
    int n = s.length(), m = pat.length(), shift = 0;
    auto lastOcc = findLastOccur(pat);

    while(shift <= n-m) {
        int j = m-1;

        // match pattern from behind 
        while(j >= 0 && pat[j] == s[j+shift])   j--;

        if(j < 0) {
            // matched 
            cout << "pattern found at: " << shift << "\n";
            /* Shift the pattern so that the next character in text aligns with the last
            occurrence of it in pattern. The condition s+m < n is necessary for
            the case when pattern occurs at the end of text */
            if(shift + m < n) {
                shift += m - lastOcc[s[shift + m]];
            } else {
                shift += 1;
            }
        } else {
            /* Shift the pattern so that the bad character in text aligns with the last occurrence of
            it in pattern. The max function is used to make sure that we get a positive shift.
            We may get a negative shift if the last occurrence of bad character in pattern
            is on the right side of the current character. */
            shift += max(1, j - lastOcc[s[shift + j]]);
        }
    }
}

// Read: Using Good Heuristics

int main() {
    string txt= "ABAAABCD";
    string pat = "ABC";
    bayerMoore(txt, pat);
}