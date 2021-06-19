/*
    https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

    Time Complexity
    T(n) =     n         *       ( T(n-1)        +            O(n) )
            for loop       recursive call       check if string is in dict
    T(n) = n*T(n-1) + O(n^2) 
    T(n) = n^3 + n!
    
    T(n) = O(n!)
*/


#include<bits/stdc++.h>
using namespace std;

void go(int i, string &s, string sent, unordered_set<string> &dict, vector<string> &ans) {
    int n = s.length();
    if(i == n) {
        sent.pop_back();
        ans.push_back(sent);
    }

    string word = "";
    for(int j=i; j<n; j++) {
        word.push_back(s[j]);
        if(dict.count(word)) {
            go(j+1, s, sent + word + " ", dict, ans);
        }
    }
}

vector<string> wordBreak(int n, vector<string> &dic, string s){
    vector<string> ans;
    unordered_set<string> dict;
    string sent = "";
    for(auto word: dic) {
        dict.insert(word);
    }
    go(0, s, sent, dict, ans);
    return ans;
}

int main() {
    string s = "catsanddog";
    int n = 5; 
    vector<string> dict = {"cats", "cat", "and", "sand", "dog"};
    
    auto ans = wordBreak(n, dict, s);
    for(auto s: ans) {
        cout << s << endl;
    }
}