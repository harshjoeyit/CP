#include<bits/stdc++.h>
using namespace std;

const int mxN = 2*1e5 + 10; 
int a[mxN], l[mxN], r[mxN];

int solve() {
    int n, maxx = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++) 
        l[i] = r[i] = 1;

    for(int i = 0; i < n-1; i++)
        if(a[i] < a[i+1])
            l[i+1] = l[i] + 1;
    
    for(int i = n-2; i >= 0; i--) 
        if(a[i] < a[i+1])
            r[i] = r[i+1] + 1;

    // for(int i = 0; i < n; i++) 
    //     cout << r[i] << " ";
    // cout << endl;

    for(int i = 0; i < n; i++)
        maxx = max(maxx, l[i]);

    // cant remove first and last element no gain
    for(int i = 1; i < n-1; i++)
        if(a[i-1] < a[i+1])
            maxx = max(maxx, l[i-1] + r[i+1]);

    return maxx;
}

int main() {
    cout << solve() << endl;
}