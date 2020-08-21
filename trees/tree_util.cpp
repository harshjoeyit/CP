

/*
making the subtree array
*/
int subtree[mxN], a[mxN];
int dfs1(int u, int p = -1) {
	int s = 0, v;
	for(auto q: g[u]) {
        v = q.first;
		if(v != p) {
			s += dfs1(v, u);
		}
 	}
    subtree[u] = s+1;
	return subtree[u];
}