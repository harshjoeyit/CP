#include<bits/stdc++.h>
using namespace std;

vector<string> gray(int n) {
    --n;
    vector<string> a = {"0", "1"};
    vector<string> b;

    while(n--) {
        for(auto s: a) {
            b.push_back("0" + s);
        }
        reverse(a.begin(), a.end());
        for(auto s: a) {
            b.push_back("1" + s);
        }

        swap(a, b);
        b.clear();
    }

    return a;
}

int main() {
    int n;
    cin >> n;
    auto ans = gray(n);
    for(auto s: ans) {
        cout << s << endl;
    }
}