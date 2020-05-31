#include<bits/stdc++.h>
using namespace std;

string s;
int k;

// O(n)
string removeKdigits(string num, int k) {
    if(k == 0) {
        return num;
    }
    if(k == num.length()) {
        return "0";
    }
    string ans = "";
    int l = k;

    for(int i = 0; i < num.length(); i++) {
        while(k && ans.length() && ans.back() > num[i]) {           // always push the smaller number in the ans if possible
            k--;
            ans.pop_back();
        }
        ans += num[i];
    }
    
    ans.resize(num.length()-l);
    int x = 0;
    while(x < ans.length() && ans[x] == '0') {
        x++;
    }
    if(x == ans.length()) {
        return "0";
    }
    return ans.substr(x);

}

// O(n*n)
string removeKdigits() {
    while(k--) {
        int n = s.length();
        int j = n-1;
        for(int i=0; i<n-1; i++) {
            if(s[i] > s[i+1]) {
                j = i;
                break;
            }   
        }
        s.erase(j, 1);
    }
    // trim string for leading 0s
    while(s.length() > 1 && s[0] == '0') {
        s.erase(0, 1);
    }
    return s;
}

int main() {
    cin >> s >> k;
    cout << removeKdigits() << endl;
}