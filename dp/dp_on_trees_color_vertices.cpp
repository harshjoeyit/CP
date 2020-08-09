#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1e5+10, mod = 1e9+7;
vector<int> g[mxN];
int n;

int mul(int a, int b) {
    return (a*b) % mod;
}

void tree_input() {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int x,y;
        cin >> x >> y;
        --x; --y;       
        g[x].push_back(y);
        g[y].push_back(x);
    }
}

// returns a pair {black, white} - 
// i.e. no ways to color trees when u is black , white respectively

pair<int, int> dfs(int u, int p) {
    int all_white = 1;  
    int some_black = 0;

    for(auto v: g[u]) {
        if(v != p) {
            pair<int, int> p = dfs(v, u);

            // pair return { ways when v is black, ways when v is white}
            // to make the ans for this node u
            // all such ways where v is white must be multiplied - these are the ways to when u is black

            // for current pair we have ways when v is black
            // to make some_black for this node 
            // some_black += existing_whites from other subtress * current black + existing_blacks * (current whites + blacks)

            int memo_all_white = all_white;                     // total ways till now that all child are white
            all_white = mul(all_white, p.second);
            some_black = (mul(memo_all_white, p.first) +
                            mul(some_black, p.first+p.second)) % mod;
        }
    }

    // the parent node(p) of this node can be 
    // colored black only if all the children are white - arg1 = all_white

    // the parent node can be 
    // colored white when the child node is either black or white 
    // arg2 = all_white + some_black

    return make_pair(all_white, (all_white + some_black) % mod);
}

void solve() {
    tree_input();
    auto p = dfs(1, -1);
    int ans = p.first + p.second;
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    solve();
}