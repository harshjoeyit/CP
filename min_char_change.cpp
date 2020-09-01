#include<bits/stdc++.h>
using namespace std;

// change min char upper to lower and vice-versa,
// so that string starts with 0 or more Uppercase letters 
// and ends with zero or more lowercase letters 
// which means it may have only upper or lower case letters only

int main() {
    string s;
    cin >> s;
    int ans, cnt;
    ans = cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' and s[i] <= 'z') ++cnt;
        if(s[i] >= 'A' and s[i] <= 'Z' and cnt >= 1) {
            // ans is only incremented when 
            // there is at least one lowecase letter is 
            // infront of uppercase letter
            ++ans;
            --cnt;
        }
    }    
    cout << ans << endl;
}   