#include<bits/stdc++.h>
using namespace std;

// online algorithm 
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

void pattern_match(string s, string pat) {
    vector<int> pi = prefix_function(pat + "#" + s);
    int pl = pat.length();
    int sl = s.length();
    for(int i = 2*pl; i < pi.size(); i++) {
        if(pi[i] == pl)
            cout << i - 2*pl << " ";
    }
    cout << endl;
}

int main() {
    string s, pat;
    cin >> s;
    cin >> pat;
    pattern_match(s, pat);
}