#include<bits/stdc++.h>
using namespace std;
#define int long long 

// the matrix is binary (0, 1 only)
// we find the have to find the maximum area of rectangle with all the ones 
// solution is based on JUDGE algo for max area histogram 
// https://www.youtube.com/watch?v=g8bSdXCG-lA


int niceMaxRectangleArea(vector<int> &heights) {
    heights.push_back(0);
    int n = heights.size();
    stack<int> s;
    int area, maxArea = 0, i = 0;
    
    while (i < n) {
        
        if (s.empty() || heights[i] > heights[s.top()]) {
            s.push(i);
            i++;

        } else {
            int top = s.top();
            s.pop();
            area = heights[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}


int maximalRectangle(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();

    // sum up the columns vertically 
    for(int j=0; j<m; j++) {
        for(int i=1; i<n; i++) {
            // if a[i][j] = 0, then prev height not taken
            if(a[i][j] > 0 /*&& a[i-1][j] > 0*/) {
                a[i][j] += a[i-1][j];
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << a[i][j] << " ";
        }cout << endl;
    }
    
    int maxA = 0;
    for(int i=0; i<n; i++) {
        // passing the ith row
        maxA = max(maxA, niceMaxRectangleArea(a[i]));
    }
    
    return maxA;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    cout << maximalRectangle(a) << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}