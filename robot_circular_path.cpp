
/*
Given a sequence of moves for a robot, check if the sequence is circular or not.
A sequence of moves is circular if first and last positions of robot are same. A move can be on of the following.
    
G - Go one unit
L - Turn left
R - Turn right
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 

// single move written anti-clockwise
vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void solve() {
    string s;
    cin >> s;
    
    pair<int, int> move = dirs[0];
    int i = 0;
    pair<int, int> pos = {0, 0};
    
    for(auto c: s) {
        if(c == 'G') {
            pos.first += move.first;
            pos.second += move.second;
        } 
        else if(c == 'L') {
              // go anti-clockwise
            i = (i + 1) % 4;
            move = dirs[i];
        } 
        else if(c == 'R') {
              // go clockwise 
            i = (i - 1 + 4) % 4;
            move = dirs[i];
        }
    }
    
    if(pos.first == 0 && pos.second == 0) {
        cout << "Circular\n";
    } else {
        cout << "Not Circular\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}