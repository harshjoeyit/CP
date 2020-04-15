/*
https://www.geeksforgeeks.org/find-excel-column-name-given-number/

 26             Z
 51             AY
 52             AZ
 80             CB
 676            YZ
 702            ZZ
 705            AAC

*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int

void solve2() {
    string s;
    cin >> s;
    int n = 0;
    
    reverse(s.begin(), s.end());
    for(int i=0; i<s.length(); i++) {
        int rem = s[i] - 'A';
        rem++;
        n += pow(26, i) * rem;
    }
    cout << n << endl;
}

void solve1() {
    int n;
    cin >> n;

    string s = "";

    while(n > 0) {
        int rem = (n-1)%26;
        s.push_back((rem + 'A'));
        n = n - rem;
        n = n/26;
    }
    reverse(s.begin(), s.end());

    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
         solve1();
         solve2();
    }
}