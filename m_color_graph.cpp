

#include<bits/stdc++.h>
using namespace std;

// checks if node 'u' can be colored with color 'col'
bool isSafe(int u, vector<int> &color, bool graph[101][101],  int n, int col) {
	for(int v=0; v<n; v++) {
		if(v != u && graph[v][u] == 1 && color[v] == col) {
			return false;
		}
	}
	return true;
}

bool go(int u, vector<int> &color, int m, int n, bool graph[101][101]) {
	if(u == n) {
		// succesfully colored all nodes [0....n-1]
		return true;
	}

	for(int col = 1; col <= m; col++) {
		if(isSafe(u, color, graph, n, col)) {
			color[u] = col;
			if(go(u+1, color, m, n, graph)) {
			    return true;
			}
			color[u] = 0;
		}
	}
	return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
	vector<int> color(n, 0);
	return go(0, color, m, n, graph);
}


/*
Improvements that can be made
1. Convert Graph to Adjacency list 
2. If graph has more than one conected component, then check for all components.
*/


int main() {
}