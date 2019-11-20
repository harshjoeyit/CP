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


void menu()
{
    cout << "1. display" << endl;
    cout << "2. update range " << endl;
    cout << "3. query " << endl;
    cout << "4. exit" << endl;
}


int main()
{
    int a[] = {1,3,2,-2,4,5,-1,6};
    int n = sizeof(a)/sizeof(int), l, r, choice, inc;

    //Build the array tree 
    int *tree = new int[4*n + 1];
    int *lazy = new int[4*n + 1];

    buildTree(tree, a, 1, 0, n-1);


    menu();
    while(cin >> choice)
    {
        switch(choice)
        {
            case 1: disp(tree, n);
                    disp(lazy, n);
            break;
            case 2: cin >> l >> r >> inc;
                    updateRangeLazy(tree, lazy, 1, 0, n-1, l, r, inc);
            break;
            case 3: cin >> l >> r;
                    inc = rangeMinLazyQuery(tree, lazy, 1, 0, n-1, l, r);
                    cout << inc << endl;
            break;
            case 4: exit(1);
            break;
        }
    }
    
}