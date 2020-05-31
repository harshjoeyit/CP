/*
You are given a tree consisting of n vertices. A tree 
is a connected undirected graph with n−1 edges. Each 
vertex v of this tree has a color assigned to it 
(av=1 if the vertex v is white and 0 if the vertex v is black).

You have to solve the following problem for each 
vertex v: what is the maximum difference between the 
number of white and the number of black vertices you 
can obtain if you choose some subtree of the given 
tree that contains the vertex v?
*/


#include<bits/stdc++.h>
using namespace std;

#define int long long int
vector<int> ans;
vector<int> dp;
vector<int> a;
vector<vector<int>> g;
int n;

void dfs1(int u, int p)
{
	dp[u] = a[u];
	for(auto v: g[u])
		if(v != p)
		{
			dfs1(v, u);
			dp[u] += max((int)0, dp[v]);
		}
}

void dfs2(int u, int p)
{
	ans[u] = dp[u];
	for(auto v: g[u])
		if(v != p)
		{
			dp[u] -= max((int)0, dp[v]);
			dp[v] += max((int)0, dp[u]);
			dfs2(v, u);
			dp[v] -= max((int)0, dp[u]);
			dp[u] += max((int)0, dp[v]);
		}
}

signed main()
{
	cin >> n;
	ans = dp = a = vector<int>(n+1);
	g = vector<vector<int>>(n+1);

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if(a[i] == 0)
			a[i] = -1;
	}

	for(int i = 0; i < n-1; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs1(1, -1);
	dfs2(1, -1);

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}
