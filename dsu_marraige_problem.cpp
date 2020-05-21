
/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/description/
*/

#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e6+10;
int parent[mxN];
int m[mxN], w[mxN];
int n;

void make_set() {
      for(int i=0; i<mxN; i++) {
            parent[i] = i;
      }
}
int find_set(int a) {
      if(parent[a] == a) {
            return a;
      }
      return parent[a] = find_set(parent[a]);
}


void solve() {
      int x,y;
	cin>>x>>y;
	int q1,q2,q3,a,b,i;
	make_set();
	cin>>q1;
	while(q1--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		u = find_set(a);
		v = find_set(b);
		if(parent[u] == parent[v]) continue;
		parent[v] = parent[u];
	}
	cin>>q2;
	while(q2--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		a += 1000000;
		b += 1000000;
		u = find_set(a);
		v = find_set(b);
		if(parent[u] == parent[v]) continue;
		parent[v] = parent[u];
	}
	cin>>q3;
	while(q3--) {
		cin>>a>>b;
		int u,v;
		b += 1000000;
		u = find_set(a);
		v = find_set(b);
		if(parent[u] == parent[v]) continue;
		parent[v] = parent[u];
	}

      // NOTE: IMP
      // if if i the leader of any component then the m[i] = size of component
	
      for(i = 1; i <= x; i++) {
		int u = find_set(i);
		m[u]++;
	}
	for(i = 1; i <= y; i++) {
		int u = find_set(i+1000000);
		w[u]++;
	}
	int ans = 0;
	for(i = 1; i <= x; i++) {
		if(m[i]) {
			ans += (long long)(m[i])*(y-w[i]);
		}
	}
	cout<<ans<<endl;


}

int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();      
}