#include<bits/stdc++.h>
using namespace std;

// change min char(upper to lower and vice-versa 
// so that string starts with 0 or more upper and
//  ends with lower or may have only upper ansd lower )

int main() {
    string s;
    cin >> s;
    int ans, cnt;
    ans = cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' and s[i] <= 'z') ++cnt;
        if(s[i] >= 'A' and s[i] <= 'Z' and cnt >= 1) {
            ++ans;
            --cnt;
        }
    }    
    cout << ans << endl;
}   