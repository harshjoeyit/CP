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

void print(vector<int> pi) {
    for(auto x: pi)
        cout << x << " ";
    cout << endl;
}
// Counting the number of occurrences of each prefix of s in s
void count_each_prefix(string s) {
    vector<int> pi = prefix_function(s);
    int n = pi.size();

    vector<int> ans(n + 1);
    for (int i = 0; i < n; i++)
        ans[pi[i]]++;                       // count of how many times prefix of a certain length occurs as a suffix 
    for (int i = n-1; i > 0; i--)
        ans[pi[i-1]] += ans[i];             // if there exists suffix of length l then there also exists suffix of length l-1 in that suffix 
    
    for (int i = 0; i <= n; i++)            // adding all the prefixs too to the count
        ans[i]++;
    
    print(ans);
}

int main() {
    string s, pat;
    cin >> s;
    print(prefix_function(s));
    // count_each_prefix(s);
    // for couting each type of prefix of t in s make string (t + "#" + s) and do the same
    // output ans[i] till length of i <= t; 
    cin >> pat;
    pattern_match(s, pat);
}