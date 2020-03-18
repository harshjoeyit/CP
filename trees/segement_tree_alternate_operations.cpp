#include<bits/stdc++.h>
using namespace std;

#define ll                    long long int
#define ld                    long double
#define mid(s,e)              (s+(e-s)/2)
#define MOD                   1000000007
#define F                     first
#define S                     second
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define itoc(c)               ((char)(((int)'0')+c))
#define vi                    vector<int>
#define pll                   pair<ll,ll>
#define pii                   pair<int,int>


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

    if(op)
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
    
    if(op)
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


// bottom to top
// perform or at depth = 0;
// then perform xor at depth = 1;
// then again perform or at depth = 3

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    n = pow(2, n);

    int a[n];
    int *tree = new int[4*n + 1];
   
    for(int i = 0; i < n; i++)
        cin >> a[i];

    // height of tree
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

    // op = 0 -> xor
    // op = 1 -> or

    bool op = 0;
    if(h % 2 == 1)          // height even start from xor, else start from or 
        op = 1;

    buildTree(tree, a, 1, 0, n-1, op);
    //disp(tree, n);

    for(int i = 0; i < m; i++)
    {
        int j, val;
        cin >> j >> val;
        --j;

        updateNode(tree, 1, 0, n-1, j, val, op);
        //disp(tree, n);
        cout << tree[1] << endl; 
    }

}