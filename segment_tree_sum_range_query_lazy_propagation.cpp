#include<bits/stdc++.h>
using namespace std;


void buildTree(int *tree, int *a, int index, int s, int e)
{
    if(s > e)
        return;
    // Base case - leaf node 
    if(s == e)
    {
        tree[index] = a[s];
        return;
    }

    int mid = (s + e)/2;
    // left subtree
    buildTree(tree, a, 2*index, s, mid);
    // right subtree 
    buildTree(tree, a, 2*index + 1, mid + 1, e);

    int left = tree[2*index];
    int right = tree[2*index + 1];

    tree[index] = left + right;                 // sum of the range 
}


int rangeSumLazyQuery(int *tree, int *lazy, int index, int s, int e, int l, int r)
{
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if(s != e)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }    
        lazy[index] = 0;
    }

    // no overflap
    if(l > e || r < s)
        return 0;
    
    // total overlap
    if(l <= s && e <= r)
        return tree[index];

    // partial overlap
    int mid = (s + e)/2;
    int leftans = rangeSumLazyQuery(tree, lazy, 2*index, s, mid, l, r);
    int rightans = rangeSumLazyQuery(tree, lazy, 2*index + 1, mid + 1, e, l, r);

    return leftans + rightans;
}



void updateRangeLazy(int *tree, int *lazy, int index, int s, int e, int l, int r, int inc)
{
    // make sure all the propagation is done at index
    // If not update tree at index mark its children for laxy propogation 
    if(lazy[index] != 0)
    {
        tree[index] += lazy[index];
        if(s != e)      // not a leaf node - propagate the update in lazy tree 
        {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // no overlap condition
    if(l > e || r < s)
        return;
    
    // total overlap
    if(l <= s && e <= r)
    {
        tree[index] += inc;
        if(s != e)
        {
            lazy[2*index] += inc;
            lazy[2*index + 1] += inc;
        }
        return;
    }

    //otherwise partial overlap so look both left and right
    int mid = (s + e)/ 2;
    updateRangeLazy(tree, lazy, 2*index, s, mid, l, r, inc);
    updateRangeLazy(tree, lazy, 2*index + 1, mid + 1, e, l, r, inc);
    tree[index] = tree[2*index] + tree[2*index + 1];

}


void disp(int *tree, int n)
{
    for(int i = 0; i < 4*n+1; i++)
        cout << tree[i] << " ";
    cout << endl;
}


int main()
{
    int a[] = {1,3,2,-2,4,5};
    int n = sizeof(a)/sizeof(int);

    //Build the array tree 
    int *tree = new int[4*n + 1];
    int *lazy = new int[4*n + 1];

    buildTree(tree, a, 1, 0, n-1);
    disp(tree, n);

    // rangeMinQuery
    // range should be that from the original array
    // index is the starting index in the tree = 1 
    cout << "sum in range (1-4) => " << rangeSumLazyQuery(tree, lazy, 1, 0, n-1, 1, 4) << endl;

    //range update (l-r)
    // eg. (1-2) increment of 4
    for(int i = 0; i <= 2; i++)
        a[i] += 4;
    // range should be that from the original array
    updateRangeLazy(tree, lazy, 1, 0, n-1, 0, 2, 4);
    disp(tree, n);
    disp(lazy, n);

    cout << "sum in range (1-4) => " << rangeSumLazyQuery(tree, lazy, 1, 0, n-1, 1, 4) << endl;
    
    updateRangeLazy(tree, lazy, 1, 0, n-1, 0, 3, 5);
    disp(tree, n);
    disp(lazy, n);

    cout << "sum in range (2-3) => " << rangeSumLazyQuery(tree, lazy, 1, 0, n-1, 2, 3) << endl;
    
}