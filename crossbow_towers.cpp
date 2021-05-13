/*
    https://www.spoj.com/problems/DEFKIN/

    Towers with corssbows are installed on a grid (rows * cols)
    A tower protects every cell row and col in which it is installed.
    No tower shares its row or col with other tower.

    Find the largest rectangle area that is unprtected.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int rows, cols, towers;
    cin >> rows >> cols >> towers;

    vector<int> towerRow, towerCol;
    for(int i=0; i<towers; i++) {
        int x, y;
        cin >> x >> y; 
        x--, y--;
        towerRow.push_back(x);
        towerCol.push_back(y);
    }
    towerRow.push_back(-1);
    towerRow.push_back(rows);
    towerCol.push_back(-1);
    towerCol.push_back(cols);

    sort(towerRow.begin(), towerRow.end());
    sort(towerCol.begin(), towerCol.end());

/*
    find maximum width, height that is unprotected by towers
    the row/col between two protected row/col are unprotected 
    For ex if row 3, 7 are proteted, then rows 4,5,6 are unprotected
*/
    int maxW = 0, maxH = 0;
    for(int i=1; i<towerRow.size(); i++) {
        maxW = max(maxW,towerRow[i] - towerRow[i-1] - 1);
    }

    for(int j=1; j<towerCol.size(); j++) {
        maxH = max(maxH, towerCol[j] - towerCol[j-1] - 1);
    }
    cout << maxH * maxW << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}