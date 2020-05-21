
/*
Berland Government decided to improve relations with neighboring countries.
 First of all, it was decided to build new roads so that from each city of Berland 
 and neighboring countries it became possible to reach all the others. There are n 
 cities in Berland and neighboring countries in total and exactly n - 1 two-way roads. 
 Because of the recent financial crisis, the Berland Government is strongly pressed for money, 
 so to build a new road it has to close some of the existing ones. Every day it is possible 
 to close one existing road and immediately build a new one. Your task is to determine how many 
 days would be needed to rebuild roads so that from each city it became possible to reach all 
 the others, and to draw a plan of closure of old roads and building of new ones.

output as removed ,joined pair i, j, k, l 

 ex1    ex-2 
7	8
1 2	1 2
2 3	5 6
3 1	6 7
4 5	7 8
5 6	8 5
6 7	5 7
	8 6

output 1
1 - days
3 1 3 7

output 2
3 - days
8 5 5 4		
5 7 4 3
6 8 3 1


*/


#include<bits/stdc++.h>
using namespace std;
#define int long long int

const int mxN = 1005;
int parent[mxN], n;
int Rank[mxN];

vector<pair<int, int> > removed;	
vector<pair<int, int> > joined;
unordered_set<int> uniq_parent;

void make_set() {
	for(int v=0; v<=n+1; v++) {
		parent[v] = v;
		Rank[v] = 0;
	}
}

int find_set(int v) {
        if(v == parent[v]) {
                return v;
        }
        return parent[v] = find_set(parent[v]);
}

void union_set(int A, int B) {
	int a = find_set(A);
	int b = find_set(B);
	if(a == b) {
		// if already they are in the same component then this edge is extra - can be removed 
		removed.push_back(make_pair(A, B));
		return;
	}
	if(Rank[a] < Rank[b]) {
		swap(a, b);
	}
	parent[b] = a;
	if(Rank[a] == Rank[b]) {
		Rank[a]++;
	}
}


void solve() {
	cin >> n;
	make_set();
	int x, y;
	for(int i=0; i<n-1; i++) {
		cin >> x >> y;
		union_set(x, y);
	}
	for(int v=1; v<=n; v++) {			// finding leaders of the disconnected components
		uniq_parent.insert(find_set(v));
	}

	vector<int> uniq;	
	for(auto x: uniq_parent) {
		uniq.push_back(x);
	}
	for(int i=0; i<uniq.size()-1; i++) {		// connecting each disconnected component
		joined.push_back({uniq[i], uniq[i+1]});
	}
	
	cout << removed.size() << endl;
	for(int i=0; i<removed.size(); i++) {
		cout << removed[i].first << " " << removed[i].second << " "
		<< joined[i].first << " " << joined[i].second << endl;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}