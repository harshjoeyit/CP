#include<bits/stdc++.h>
using namespace std;


void build_tree(int *a, int *tree, int index, int s, int e)
{
    if(s > e)
        return;
    
    if(s == e)
    {
        tree[index] = a[s] % 2;
        return;
    }
    
    int mid = (s + e)/2;
    build_tree(a, tree, 2 * index, s, mid);
    build_tree(a, tree, 2 * index + 1, mid + 1, e); 
    
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}


void update(int *tree, int index, int s, int e, int upi, int val)
{
    if(upi < s || e < upi)
        return;
        
    if(s == e)
    {
        tree[index] = val % 2;
        return;
        
    }
    
    int mid = (s + e)/2;
    update(tree, 2 * index, s, mid, upi, val);
    update(tree, 2 * index + 1, mid + 1, e, upi, val); 
    
    tree[index] = tree[index * 2] + tree[index * 2 + 1];
}


// returns the odd number count 
int query(int *tree, int index, int s, int e, int l, int r)
{
    if(r < s || e < l)
        return 0;
    
    if(l <= s && e <= r)
        return tree[index];
        
    int mid = (e + s)/2;
    int left = query(tree, 2 * index, s, mid, l, r);
    int right = query(tree, 2 * index + 1, mid + 1, e, l, r); 
    
    return (left + right);
}

void disp(int *tree, int n)
{
    for(int i = 0; i < 4*n + 1; i++)
        cout << tree[i] << " ";
    cout << endl;
}


int main()
{
    int n, q, x, y, mark;
    cin >> n;
    
    int a[n] = {}, tree[4 * n + 1] = {};
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    build_tree(a, tree, 1, 0, n-1);
    //disp(tree, n);

    cin >> q;

    while(q--)
    {
        cin >> mark >> x >> y;

        if(mark == 0)
            update(tree, 1, 0, n-1, x-1, y);        // index x- 1, value y

        else
        {
            int odd = query(tree, 1, 0, n-1, x-1, y-1);
            int t = y-x+1;
            //cout << t <<" "<< odd << endl;
            
            
            if(mark == 1)
                cout << t - odd << endl;
            else
                cout << odd << endl;
        }
        
        //disp(tree, n);
    }
}