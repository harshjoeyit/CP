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
#define pll                   pair<ll, ll>
#define pii                   pair<int,int>

  
// in O(N.N!)

bool check_all_permutations(vi G[], vi nodes)
{   
    do
    {
        bool path_present = false;
        auto st = nodes.begin();                // first node 
        auto en = nodes.end() - 1;              // last node

        vi PATH;
        PATH.push_back(*st);                    // first node pushed 

        int u;
        int p = nodes.size() - 1;

        for(auto it = st; it != en; it++)
        {
            u = *it;
            bool path_present = false;

            for(int &v : G[u])
            {
                if(v == *(it+1))
                {
                    path_present = true;
                    PATH.push_back(v);
                    --p;
                    break;
                }
            }
            if(! path_present)
                break;
        }
        if(p == 0)
        {
            for(auto &i: PATH)
                cout << i << " ";
            cout << endl;
            return true;
        }
    
    } while (next_permutation(nodes.begin(), nodes.end()));
    
    return false;
}


int main()
{
    int n, m, x, y;
    
    cin >> n >> m;
    vi G[n+1];

    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        G[x].pb(y);
       // G[y].pb(x);
    }

    vi nodes(n);
    for(int i = 0; i < n; i++)
        nodes[i] = i;

    if(check_all_permutations(G, nodes))
        cout << "path exists\n";
    else
        cout << "does not exist\n";
}