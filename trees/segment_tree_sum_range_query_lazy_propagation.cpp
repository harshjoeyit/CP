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
    if( s > e  || l > e|| r < s)
        return 0;                   // out of range

    if(lazy[index] != 0)
    {
        tree[index] += (e - s + 1) * lazy[index];
        if(s != e)
        {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }    
        lazy[index] = 0;
    }
    
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
        tree[index] += (e - s + 1) * lazy[index];               // e - s + 1 is just the number of children of the node with lazy update - the children that are not updated yet 
        if(s != e)      // not a leaf node - propagate the update in lazy tree 
        {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    
    // no overlap condition
    if(s > e || l > e || r < s)
        return;
    
    // total overlap
    if(l <= s && e <= r)
    {
        tree[index] += (e - s + 1) * inc;
        if(s != e)
        {
            lazy[2*index] +=  inc;
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

void final_array(int *tree, int *lazy, int *a, int index, int s, int e)
{   
    if(s > e)
        return;

    // propagating the lazy update
    if(lazy[index] != 0)
    {
        tree[index] += (e - s + 1) * lazy[index];               
        if(s != e)       
        {
            lazy[2*index] += lazy[index];
            lazy[2*index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }

    if(s == e)
    {
        a[s] = tree[index];
        return;
    }

    int mid = (s + e)/2;
    final_array(tree, lazy, a, 2 * index, s, mid);
    final_array(tree, lazy, a, 2 * index + 1, mid + 1, e);
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
    cout << "4. final array " << endl;
    cout << "5. exit" << endl;
}


int main()
{
    int n = 6;
    int a[n] = {};
    int l, r, choice, inc;

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
                    inc = rangeSumLazyQuery(tree, lazy, 1, 0, n-1, l, r);
                    cout << inc << endl;
            break;
            case 4: final_array(tree, lazy, a, 1, 0, n-1); 
                    for(int i = 0 ; i < n; i++)
                        cout << a[i] << " ";
                    cout << endl;

            case 5: exit(1);
            break;
        }
    }
    
}