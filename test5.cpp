#include<bits/stdc++.h>
using namespace std;

string solve() {
    string s;
    getline(cin, s);
    int n;
    cin >> n;

    stringstream ss;
    ss << s;

    string word;
    // check
    while (ss >> word) {
        if(word.length() > n) {
            return "Not Possible";
        }
    }

    ss.clear();
    ss << s;

    string ans = "", curr = "";

    while(ss >> word) {
        // -1 for extra space added in curr
        if(curr.length() + word.length() - 1 > n) {
            ans += curr + "\n";
        }
        curr += word + " ";
    }

    return ans;
}

int main() {
      auto ans = solve();
      cout << ans;
}