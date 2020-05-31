
/*
L - denotes count of the numbers that are on left and greater than a value
R - denotes count of the numbers that are ont the right and are less than a value

find the min value of |R - L|

*/


#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    
    sort(a, a+n);           // sort the array
    
    int ans = INT_MAX;
    for(int i=0; i<n; i++) {
        ans = min(ans, abs(a[i].second - i));       // min diff b/w curr and original index is the ans 
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        solve();
}