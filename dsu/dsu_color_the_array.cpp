#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5+10;
int n, q;
int parent[mxN];
int answer[mxN];

struct st {
	int L, R, c;
};

void make_set(int v) {
	parent[v] = v;
}

int find_set(int v) {
	if(v == parent[v]) {
		return v;
	}
	// could use path compression
	return find_set(parent[v]);
}

void paint_the_array(vector<st> &query) {
	for(int i=0; i<=n+1; i++) {
		make_set(i);
	}
        // reading queries backward since the element color will be the color painted finally
	for(int i = q-1; i >= 0; i--) {
		int L = query[i].L;
		int R = query[i].R;
		int c = query[i].c;
		// find the first not colored element in range L, R
		for(int v = find_set(L); v <= R; v = find_set(v)) {
			answer[v] = c;
			parent[v] = v + 1; 	
			// next element 
		}
	} 
}

int main() {
	cin >> n >> q;
	vector<st> query;
	st temp;
	for(int i=0; i<q; i++) {
		cin >> temp.L >> temp.R >> temp.c;
		query.push_back(temp);
	}

	paint_the_array(query);
	for(int i=1; i<=n; i++) {
		cout <<  answer[i] << " ";
	}cout << endl;
}