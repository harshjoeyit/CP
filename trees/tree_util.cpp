

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


/*
Largest value in each level of Binary Tree
O(n) space approach - Use queue 
O(1) space apprach use preorder traversal and keep updating the largest value at each level 
*/
