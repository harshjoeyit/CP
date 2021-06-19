/*
    Remove Invalud Paranthesis
    https://leetcode.com/problems/remove-invalid-parentheses/submissions/
*/

#include<bits/stdc++.h>
using namespace std;

unordered_set<string> uniq;
int aptLen;

// find length of longest valid string after removing invalid paranthesis.
void aptLength(string &s) {
    int balance = 0;
    int extraClose = 0;
    
    for(auto c: s) {
        if(c == '(') {
            balance++;
        }
        else if(c == ')') {
            if(balance > 0) {
                balance--;
            } else {
                extraClose++;
            }
        }
    }
    
    int remove = extraClose + balance;
    aptLen = s.length() - remove;
}

void go(int i, string &s, string res, int balance) {
    int n = s.length();
    if(i == n) {
        if(res.length() == aptLen && balance == 0){
            uniq.insert(res);
        }
        return;
    }
    if(balance < 0) {
        return;
    }

    // skip
    go(i+1, s, res, balance);
    
    if(s[i] == '(') {
        // include 
        go(i+1, s, res + s[i], balance + 1);
    } 
    else if(s[i] == ')') {
        // include 
        go(i+1, s, res + s[i], balance - 1);
    } 
    else {
        // include this char
        go(i+1, s, res + s[i], balance);
    }
}

vector<string> removeInvalidParentheses(string s) {
    uniq.clear();
    aptLength(s);
    string res = "";
    go(0, s, res, 0);
    return vector<string>(uniq.begin(), uniq.end());
}

int main() {

}