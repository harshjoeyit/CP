#include<bits/stdc++.h>
using namespace std;


void buildTree(int *tree, int *a, int index, int s, int e, bool op)
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
    buildTree(tree, a, 2*index, s, mid, !op);
    // right subtree 
    buildTree(tree, a, 2*index + 1, mid + 1, e, !op);

    int left = tree[2*index];
    int right = tree[2*index + 1];

    if(op == 0)
        tree[index] = left | right;  
    else
        tree[index] = left ^ right;
                   
}

// O(log(n))
void updateNode(int *tree, int index, int s , int e, int upi, int value, bool op)
{
    // no overlap
    if(upi < s || upi > e)
        return;
    // reached leaf
    if(s == e)
    {
        tree[index] = value;
        return;
    }

    // upi lying in range of s-e
    int mid = (s + e)/2;
    updateNode(tree, 2*index, s, mid, upi, value, !op);
    updateNode(tree, 2*index + 1, mid + 1, e, upi, value, !op); 
    
    if(op == 0)
        tree[index] = tree[2*index] | tree[2*index + 1]; 
    else
        tree[index] = tree[2*index] ^ tree[2*index + 1]; 

}


void disp(int *tree, int n)
{
    for(int i = 0; i < 4*n+1; i++)
        cout << tree[i] << " ";
    cout << endl;
}


int main()
{
    int a[] = {1, 6, 3, 5};
    int n = sizeof(a)/sizeof(int);

    //Build the array tree 
    int *tree = new int[4*n + 1];

    int h = 0;
    int l = 1, r = 2;
    while(1)
    {
        if(l <= n && n < r)
            break;
        l = l*2;
        r = r*2;
        ++h;
    }

    bool op = 0;
    if(h % 2 == 1)
        op = true;

    buildTree(tree, a, 1, 0, n-1, op);
    disp(tree, n);


    cout << "sum in range (1-4) => " << rangeSumQuery(tree, 1, 0, n-1, 1, 4) << endl;

    // updateNode
    // update index 3 in original array to value 6
    a[3] = 6;
    updateNode(tree, 1, 0, n-1, 3, 6);
    disp(tree, n);    


    //range update (l-r)
    // eg. (1-2) increment of 4
    for(int i = 0; i <= 2; i++)
        a[i] += 4;
    // range should be that from the original array
    updateRange(tree, 1, 0, n-1, 0, 2, 4);
    disp(tree, n);
}