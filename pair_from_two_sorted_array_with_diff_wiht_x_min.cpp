/*

Given a sorted array and a number x,
 find the pair in array whose sum is closest to x

*/



#include<bits/stdc++.h>
using namespace std;

#define int long long int

void merge(int a[], int n, int b[], int m, pair<int, int> p[]) {
    
    int i=0, j=0, k=0;
    while(i < n && j < m) {
        if(a[i] < b[j]) {
            p[k].first = a[i];
            p[k].second = 1;
            ++i; 
        } else {
            p[k].first = b[j];
            p[k].second = 2;
            ++j; 
        }
        ++k;
    }

    while(i < n) {
        p[k].first = a[i];
        p[k].second = 1;
        ++i; ++k;
    }
    while(j < m) {
        p[k].first = b[j];
        p[k].second = 2;
        ++j; ++k;
    }
}

void sum_closest_to_x(int a[], int n, int b[], int m, int x) {
    
    pair<int, int> p[m+n];
    merge(a, n, b, m, p);

    // for(auto x: p)
    //     cout << x.first << " ";
    // cout << endl;
    // for(auto i: p)
    //     cout << i.second << " ";
    // cout << endl;


    int mind = INT_MAX, l = 0, r = n+m-1;
    // use algo for 
    // Given a sorted array and a number x, find the pair in array whose sum is closest to x

    while(l < r) {
        int s = p[r].first + p[l].first ;
        if(p[l].second != p[r].second  && abs(s - x) < mind) {
            mind = abs(s - x );
        }

        if(s > x)
            r--;
        else 
            l++;
    }

    cout << "mind: " << mind << endl;
}

void solve() {
    int n, m, x;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    cin >> m;
    int b[m];
    for(int i=0; i<m; i++)
        cin >> b[i];

    cin >> x;
    sum_closest_to_x(a, n, b, m, x);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
}