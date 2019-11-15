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



const int N = 100005;
int par[N];
int Arr[N];

ll root(ll u)
{
    if(par[u] == u)
    return u;
    
    return par[u] = root(par[u]);
}


void Union(ll u, ll v)
{
    if(root(u) == root(v))
    return ;
    
    if(par[root(v)] < par[root(u)])         // by default the parent is the bigger number 
        par[root(v)] = root(u);
    else
        par[root(u)] = root(v);
}


bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
        return true;
    else
        return false;
}


// for tacking the size of each connected components / subset
int Size[N];

void initialize(int N)
{
    for(int i = 0; i < N; i++)
    {
        Arr[ i ] = i ;
        Size[ i ] = 1;
    }
}

// find , root functions will be same as before


//Maintaining a balance tree, will reduce complexity of the union-find function from N to log2N.
void weighted_union(int a, int b)
{
    int root_a = root(a);
    int root_b = root(b);

    if(Size[root_a] < Size[root_b])         // b has more connected components
    {   // a connected to  b
        Arr[root_a] = Arr[root_b];
        Size[root_b] += Size[root_a];
    }
    else
    {   // b connected to a 
        Arr[root_b] = Arr[root_a];
        Size[root_a] += Size[root_b];
    }
}


// modified root function with path compression 
int root (int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;            // changing the parent to parent of parent
        i = Arr[ i ]; 
    }
    return i;
}
//When you use the weighted-union operation with path compression it takes log * N for each 
// union find operation, where N is the number of elements in the set.



int main()
{
    ll n, m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        par[i] = i;
    
    while(m--)
    {
        ll u,v;
        cin >> u >> v;
        Union(u,v);
    }      
    
    ll q;
    cin >> q;

    while(q--)
    {
        ll u,v;
        cin >> u >> v;

        ll frnd1 = root(u);         // friend with the largest value 
        ll frnd2 = root(v);
        
        if(frnd1 > frnd2)
            cout << u << endl;
        
        else if(frnd2 > frnd1)
            cout << v << endl;

        else
            cout << "TIE" << endl;
    
    }
}