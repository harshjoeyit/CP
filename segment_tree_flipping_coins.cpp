#include<bits/stdc++.h>
using namespace std;

int rangeSumLazyQuery(int *tree, int *lazy, int index, int s, int e, int l, int r)
{
    if( s > e  || l > e|| r < s)
        return 0;                

    if(lazy[index] != 0)
    {
        tree[index] = (e - s + 1) - tree[index];            // since the head becomes tails, tails becomes heads    - no reverses of what it actually was
        
        if(s != e)
        {   
            lazy[ index<<1 ] ^= 1;// update the lazy value to left child
			lazy[ index<<1|1 ] ^= 1; // update the lazy value to right child
        }    
        lazy[index] = 0;
    }
    
    // total overlap
    if(l <= s && e <= r)
        return tree[index];

    // partial overlap
    int mid = (s + e)/2;
    int leftans = rangeSumLazyQuery(tree, lazy, index<<1, s, mid, l, r);
    int rightans = rangeSumLazyQuery(tree, lazy, index<<1|1 , mid + 1, e, l, r);

    return leftans + rightans;
}



void updateRangeLazy(int *tree, int *lazy, int index, int s, int e, int l, int r)
{
    if(lazy[index] != 0)
    {
        tree[index] = (e - s + 1) - tree[index];                
        if(s != e)
        {   
            lazy[ index<<1 ] ^= 1;// update the lazy value to left child
			lazy[ index<<1|1 ] ^= 1; // update the lazy value to right child
        }  
        lazy[index] = 0;
    }
    
    // no overlap condition
    if(s > e || l > e || r < s)
        return;
    
    // total overlap
    if(l <= s && e <= r)
    {
        tree[index] = (e - s + 1) - tree[index];

        if(s != e)
        {   
            lazy[ index<<1 ] ^= 1;// update the lazy value to left child
			lazy[ index<<1|1 ] ^= 1; // update the lazy value to right child
        }  
        return;
    }

    //otherwise partial overlap so look both left and right
    int mid = (s + e)/ 2;
    updateRangeLazy(tree, lazy, index<<1, s, mid, l, r);
    updateRangeLazy(tree, lazy, index<<1|1, mid + 1, e, l, r);
    tree[index] = tree[index<<1] + tree[index<<1|1];

}


void disp(int *tree, int n)
{
    for(int i = 0; i < 4*n+1; i++)
        cout << tree[i] << " ";
    cout << endl;
}


int main()
{
    int n, q, op, l, r;
    cin >> n >> q;

    int a[n] = {};       // 0 denotes tails, 1 denotes heads 
    int *tree = new int[4*n + 1];
    int *lazy = new int[4*n + 1];

    while(q--)
    {
        cin >> op >> l >> r;

        if(op == 0)
        {
            updateRangeLazy(tree, lazy, 1, 0, n-1, l, r); 
            //disp(tree, n);
            //disp(lazy, n);
        }
        
        else
            cout << rangeSumLazyQuery(tree, lazy, 1, 0, n-1, l, r) << endl;

    }
}