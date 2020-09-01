
/*
find minimum cost to combine all elements given when x, y are combined cost = x+y

also every node represents an interval - cost for that interval should be minimized 
the array elements can be considered as leaves of a binary tree
we combine them to form nodes

the final cost could be conisdered as the sum of the 
values present at the nodes(except leaves) 
when a tree is built to the root from the array 

dp[i][j] - min cost to combine interval [i, j]
our ans = dp[1][n]
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 405;
int dp[mxN][mxN];
int prefixix[mxN];
const int INF = 1e18;

int go(int st, int en) {
    if(st >= en) {
        return 0;
    }

    int sum = prefixix[en] - prefixix[st-1];
    int &ans = dp[st][en];
    if(ans != -1) {
        return ans;
    }
    ans = INT_MAX;

    for(int i=st; i<en; i++) {
        ans = min(ans, sum + go(st, i) + go(i+1, en));
    }

    cout << st << " " << en << " - >" << ans << endl;
    return ans;
}

void solve() {
    int n;
    cin >> n;

    int a[n+1];
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    memset(prefix, 0, sizeof(prefix));
    for(int i=1; i<=n; i++)
        prefix[i] = prefix[i-1] + a[i];
    
    // recursive approach 
    // go(1, n);

    
    // interative 
    for(int L=n; L>=1; L--) {
        for(int R=L; R<=n; R++) {

            if(L == R) {             
                // if interval consist of single node - cost = 0
                dp[L][R] = 0;
            
            } else {    
                dp[L][R] = INF;
                int sum = prefix[R] - prefix[L-1];

                // breaking intervals of L..i, i+1...R segments of left 
                // child and right child - to discpver all possibilites 
                for(int i=L; i<=R-1; i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + sum);
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << dp[i][j] << " ";
        }cout << endl;
    }

    // O(n^3)
    cout << dp[1][n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}



// similar problem 
// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/

// memoization table
vector<vector<pair<int, int>>> dp;
    
// function returns a pair 
// {cost, max-leaf}
pair<int, int> go(int st, int en, vector<int> &a) {
    if(st == en) {
        // on a leaf node, so cost = 0, max leaf = this node's value
		return {0, a[st]};
    }
    
	// memoized solution
    if(dp[st][en].first != -1) {
		return dp[st][en];
    }
    
    int ans = INT_MAX, maxLeaf;
    
    for(int i=st; i<en; i++) {
		// left subtree [st....i] 
        auto p = go(st, i, a);
		// right subtrees [i+1....en]
		auto q = go(i+1, en, a);
		
        // we merge to left and right subtrees 
		// left ans + right ans + (max-leaft left * max-leaf right)
        int temp = p.first + q.first + p.second * q.second;
        
        if(temp < ans) {
			// update the answer 
            ans = temp;
            maxLeaf = max(p.second, q.second);
        } else if(temp == ans) {
           // if max-leaf can be reduced 
		   maxLeaf = min(maxLeaf, max(p.second, q.second));
        }
    }
    
	// return, store ans 
    return dp[st][en] = {ans, maxLeaf};
}

int mctFromLeafValues(vector<int>& a) {
    int n = a.size();
    dp.assign(n, vector<pair<int, int>>(n, {-1,-1}));
    return go(0, n-1, a).first;
}
	







// similar problem 
// https://leetcode.com/problems/burst-balloons/submissions/
// given an array, and operation defined as 
// we remove an element at i the prize = a[i-1] * a[i] * a[i+1]
// for i = 0, i = n-1, the border element can be considered as 1
// find the max prize 

int go(vector<int>& nums,int st, int en) {
	if(st<0||en>=nums.size()||st>en)
		return 0;

    int &ans = dp[st][en];
	if(ans != -1)
		return ans;
	
    int ans = INT_MIN;
	
    for(int i=st;i<=en;++i) {
		int lval = st-1 < 0 ? 1 : nums[st-1];
		int rval = en+1 >= nums.size() ? 1 : nums[en+1];
		ans = max(ans, nums[i] * lval * rval + go(nums,st,i-1) + go(nums,i+1,en));
	}

	return ans;
}

int maxCoins(vector<int>& nums) {
	dp.resize(nums.size(),vector<int>(nums.size(),-1));
	return go(nums,0,nums.size()-1);
}


// similar problem 
// rod_cutting