#include<bits/stdc++.h>
using namespace std;

#define int long long int 
const int mxN = 1e5;
int a[mxN], t[4*mxN];       // for range sum query 


void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];                   
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if(l > tr || r < tl)
        return 0;
        
    if(tl >= l && tr <= r)
        return t[v];

    int tm = (tl + tr)/2;
    int left= sum(2*v, tl, tm, l, r);
    int right = sum(2*v+1, tm+1, tr, l, r);
    return left+right;
}



void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update_range(int v, int tl, int tr, int l, int r, int inc)
{
    if(l > tr || r < tl)
        return;
    if(tl == tr)
    {
        t[v] += inc;
        return;
    }
    int tm = (tl + tr)/2;
    update_range(2*v, tl, tm, l, r, inc);
    update_range(2*v+1, tm + 1, tr, l, r, inc); 
    t[v] = t[2*v] + t[2*v+1]; 
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> a[i];

    build(a, 1, 0, n-1);
    int q;
    cin >> q;
    while(q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if(t == 1)
            cout << sum(1, 0, n-1, l, r) << endl;
        else if(t == 2)
            update(1, 0, n-1, l, r);                    // value at a[l] = r
        else {
            int inc;
            cin >> inc;
            update_range(1, 0, n-1, l, r, inc);
        }
    }
}