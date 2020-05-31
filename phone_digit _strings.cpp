#include<bits/stdc++.h>
using namespace std;

string num;
map<char, string> mp;
void fillmap() {
        mp['0'] = "";
        mp['1'] = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
}

void go(int i, string ans) {
        if(i == num.length()) {
                cout << ans << " ";
                return;
        }
        for(int k=0; k<mp[num[i]].length(); k++) {
                ans.push_back(mp[num[i]][k]);
                go(i+1, ans);
                ans.pop_back();
        }
}

int main() {
        fillmap();
        cin >> num;
        go(0, "");
}