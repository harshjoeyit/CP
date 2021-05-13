
/*
    https://www.spoj.com/problems/CHOCOLA/

    Given a chocolate bar of (rows*cols) size, break it into single square.
    Each breaking line horizontal or vertical has a cost. Find minimum cost to break the bar into squares.
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

void solve() {
    int rows, cols;
    cin >> rows >> cols;
    vector<int> x(rows-1), y(cols-1);

    // cost for horizontal breaking
    for(int i=0; i<rows-1; i++) {
        cin >> x[i];
    }
    // cost for vertical breaking
    for(int i=0; i<cols-1; i++) {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int i = rows-2, j = cols-2;
    int divRows = 1, divCols = 1;       // divRows = number of horizonatal divisions, divCols = number of vertical divisions
    int cost = 0;

    // we greedily take the largest breaking cost and break choclate along it 
    // this strategy works as the pieces continue to grow with each break.
    while(i >= 0 || j >= 0) {
        if(i >= 0 && j >= 0) {
            if(x[i] >= y[j]) {
                cost += x[i--] * divCols;
                divRows++;  
            } else {
                cost += y[j--] * divRows;
                divCols++;
            }
        } 
        else if(i >= 0) {
            cost += x[i--] * divCols;
            divRows++;
        } 
        else {
            cost += y[j--] * divRows;
            divCols++;
        }
    }
    cout << cost << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}