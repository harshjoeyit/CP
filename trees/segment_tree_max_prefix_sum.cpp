// Maximum pre-sum for a given range

#include<bits/stdc++.h>
using namespace std;

struct node {
    int sum, pre;
};
#define int long long int 
#define Node struct node

const int mxN = 1e5;
int a[mxN];
Node t[4*mxN];      

void build(int a[], int v, int tl, int tr) {
    if(tl == tr) {
        t[v].pre = a[tl];
        t[v].sum = a[tl]; 
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);

        t[v].sum = t[2*v].sum + t[2*v+1].sum;
        t[v].pre = max(t[2*v].pre, t[2*v].sum + t[2*v+1].pre);
    }
}

Node max_pre_sum(int v, int tl, int tr, int l, int r) {
    Node res; 
    res.sum = res.pre = -1; 
  
    if (tl > r || tr < l) 
        return res; 
  
    if (tl >= l && tr <= r) 
        return t[v]; 
  
    int tm = (tl + tr) / 2; 

    if (l > tm) 
        return max_pre_sum(2*v+1, tm+1, tr, l, r); 
  
    if (r <= tm) 
        return max_pre_sum(2*v, tl, tm, l, r); 
  
    Node left = max_pre_sum(2*v, tl, tm, l, r); 
    Node right = max_pre_sum(2*v+1, tm + 1, tr, l, r); 
  
    res.sum = left.sum + right.sum; 
    res.pre = max(left.pre, left.sum + right.pre); 
    return res; 
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v].pre = new_val;
        t[v].sum = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm)
            update(2*v, tl, tm, pos, new_val);
        else
            update(2*v+1, tm+1, tr, pos, new_val);
            
        t[v].sum = t[2*v].sum + t[2*v+1].sum;
        t[v].pre = max(t[2*v].pre, t[2*v].sum + t[2*v+1].pre);
    }
}

signed main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(a, 1, 0, n-1); 

    int q;
    cin >> q;
    while(q--) {
        int t, l, r;
        cin >> t >> l>> r;
        if(t == 1)
            cout << max_pre_sum(1, 0, n-1, l, r).pre << endl;
        else
            update(1, 0, n-1, l, r);                // a[l] = r
    }
}