/*
break string in k parts where earch path length is between [a, b];
make a tree of recursive solution, 
we find overlapping subproblems with current steps(t) ans string length processed(en+i)

could have also be done by reversing the string then we wont need a stack
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long int 
const int mxN = 1000;
int dp[mxN][mxN];
int a, b, k, n;
string s;
stack<pair<int, int>> stck;

bool solve(int st, int en, int t) {
    if(t > k || en >= n)
        return 0;
    if((en == n-1) && (t == k)) {
        stck.push({st, en});
        return 1;
    }

    for(int i = a; i <= b; i++) {

        if(en+i <= n-1) {
            if(dp[en+i][t+1] == 0)
                continue;
            else if(dp[en+i][t+1] = solve(en+1, en+i, t+1)) {
                // when solve() = 1 i.e dp[en+i][t+1] = 1
                // its possible so push {st, en} it in the stack 
                stck.push({st, en});
                return true;
            }
        }
        else 
            break;
    }
    return 0;
}

signed main() {
    cin >> k >> a >> b;
    cin >> s;
    n = s.length();
    // cout << n << endl;
    for(int i = 0; i < mxN; i++) {
        for(int j = 0; j < mxN; j++) {
            dp[i][j] = 1;
        }
    }

    if(solve(-1, -1, 0)) {
        stck.pop();
        while(!stck.empty()) {
            auto p = stck.top();
            stck.pop();

            for(int i = p.first; i <= p.second; i++)
                cout << s[i];
            cout << endl;
        }
    } else 
        cout << "No solution" << endl;
}