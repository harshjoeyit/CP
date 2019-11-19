#include<bits/stdc++.h>
using namespace std;



// O(n)
void buildTree(int *tree, int *a, int index, int s, int e)
{
    if(s > e)
        return;
    // Base case - leaf node 
    if(s == e)
    {
        tree[index] = a[s];         // leaf node is array element in order 
        return;
    }

    int mid = (s + e)/2;
    // build left subtree
    buildTree(tree, a, 2*index, s, mid);
    // build right subtree 
    buildTree(tree, a, 2*index + 1, mid + 1, e);

    int left = tree[2*index];
    int right = tree[2*index + 1];

    tree[index] = min(left, right);
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
    tree[index] = min(tree[2*index], tree[2*index + 1]);

}


int rangeMinLazyQuery(int *tree, int *lazy, int index, int s, int e, int l, int r)
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
        return INT_MAX;
    
    // total overlap
    if(l <= s && e <= r)
        return tree[index];

    // partial overlap
    int mid = (s + e)/2;
    int leftans = rangeMinLazyQuery(tree, lazy, 2*index, s, mid, l, r);
    int rightans = rangeMinLazyQuery(tree, lazy, 2*index + 1, mid + 1, e, l, r);

    return min(leftans, rightans);
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

    cout << "min in range 1-2 = " << rangeMinLazyQuery(tree, lazy, 1, 0, n-1, 1, 2) << endl; 
    // increment of 2 in (0-4)
    updateRangeLazy(tree, lazy, 1, 0, n-1, 0, 4, 2);
    disp(tree, n);
    disp(lazy, n);

    cout << "min in range 0-3 = " << rangeMinLazyQuery(tree, lazy, 1, 0, n-1, 0, 3) << endl; 

    updateRangeLazy(tree, lazy, 1, 0, n-1, 3, 3, 5);
    disp(tree, n);
    disp(lazy, n);

    cout << "min in range 2-4 = " << rangeMinLazyQuery(tree, lazy, 1, 0, n-1, 2, 4) << endl;
}