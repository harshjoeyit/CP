
// Range max query with lazy updates 

#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e5;
int n, q;
int a[mxN];

struct segtree {
    int *tree = new int[1<<18];
    int *lazy = new int[1<<18];

    void build(int *a, int i=1, int s = 0, int e = n-1) {
        if(s > e)
            return;
        if(s == e) {
            tree[i] = a[s];       
            return;
        }
        int mid = (s + e)/2;
        build(a, 2*i, s, mid);
        build(a, 2*i+1, mid+1, e);
        tree[i] = max(tree[2*i], tree[2*i+1]);
    }

    void update( int l, int r, int inc, int i = 1, int s = 0, int e = n-1) {
        if(lazy[i] != 0) {
            tree[i] += lazy[i];
            if(s != e) {     // not a leaf node - propagate the update in lazy tree 
                lazy[2*i] += lazy[i];
                lazy[2*i + 1] += lazy[i];
            }
            lazy[i] = 0;
        }
        if(l > e || r < s)
            return;

        if(l <= s && e <= r) {
            tree[i] += inc;
            if(s != e) {
                lazy[2*i] += inc;
                lazy[2*i + 1] += inc;
            }
            return;
        }

        int mid = (s + e)/ 2;
        update(l, r, inc, 2*i, s, mid);
        update(l, r, inc, 2*i + 1, mid + 1, e);
        tree[i] = max(tree[2*i], tree[2*i + 1]);

    }

    int query(int l, int r, int i=1, int s =0 , int e= n-1) {
        if(lazy[i] != 0) {
            tree[i] += lazy[i];
            if(s != e) {
                lazy[2*i] += lazy[i];
                lazy[2*i + 1] += lazy[i];
            }    
            lazy[i] = 0;
        }
        if(l > e || r < s)
            return -1e18;

        if(l <= s && e <= r)
            return tree[i];

        int mid = (s + e)/2;
        int leftans = query( l, r, 2*i, s, mid);
        int rightans = query( l, r, 2*i + 1, mid + 1, e);

        return max(leftans, rightans);
    }
    void disp(int n)
    {
        for(int i = 0; i < 4*n+1; i++)
            cout << tree[i] << " ";
        cout << endl;
        for(int i = 0; i < 4*n+1; i++)
            cout << lazy[i] << " ";
        cout << endl;
    }
};


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // code
}