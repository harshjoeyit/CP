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

    tree[index] = min(left, right);
}





// return a min elemernt from the tree lying in rage l-r 
// O(log(n))
int rangeMinQuery(int *tree, int index,int s, int e, int l, int r)
{
    //  1. no overlap
    if(l > e || r < s)
        return INT_MAX;
    // 2. complete overlap
    if(s >= l && e <= r)
        return tree[index];
    // 3. partial overlap
    int mid = (s + e)/2;
    int leftans = rangeMinQuery(tree, 2*index, s, mid, l, r);
    int rightans = rangeMinQuery(tree, 2*index + 1, mid + 1, e, l, r);

    return min(leftans, rightans);
}




// O(log(n))
void updateNode(int *tree, int index, int s , int e, int upi, int value)
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
    updateNode(tree, 2*index, s, mid, upi, value);
    updateNode(tree, 2*index + 1, mid + 1, e, upi, value); 
    tree[index] = min(tree[2*index], tree[2*index + 1]); 
}



//   O(n) - as in worst case the whole array might have to be changed 
void updateRange(int *tree, int index, int s, int e, int l, int r, int inc)
{
    //no overlap
    if(l > e || r < s)
        return;

    // leaf node reached
    if(s == e)
    {
        tree[index] += inc;
        return;
    }

    // partial overlap
    int mid = (s + e)/2;
    updateRange(tree, 2*index, s, mid, l, r, inc);
    updateRange(tree, 2*index + 1, mid + 1, e, l, r, inc); 
    tree[index] = min(tree[2*index], tree[2*index + 1]); 
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

    buildTree(tree, a, 1, 0, n-1);
    disp(tree, n);


    // rangeMinQuery
    // range should be that from the original array
    // index is the starting index in the tree = 1 
    cout << "min in range (0-2) => " << rangeMinQuery(tree, 1, 0, n-1, 0, 2) << endl;


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