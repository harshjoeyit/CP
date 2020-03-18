#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, B=300, M=998244353;
ll iv[mxN+1], f1[mxN+1], f2[mxN+1];
int n, q, a[mxN], ans[mxN], c[mxN], tx;
//counts of counts
int cc[mxN+1];
//the distinct counts
vector<int> d;
//status of the distinct counts
bool bd[mxN+1];

struct query {
	int l, r, i;
	bool operator<(const query &o) const {
		//compare by block of left index first then right index
		return make_pair(l/B, r)<make_pair(o.l/B, o.r);
	}
} b[mxN];

//update the count of x by y
void upd(int x, int y) {
	tx^=c[x];
	--cc[c[x]];
	c[x]+=y;
	tx^=c[x];
	++cc[c[x]];
	if(!bd[c[x]]) {
		d.push_back(c[x]);
		bd[c[x]]=1;
	}
}

void solve() {
	//input
	cin >> n;
	map<int, int> mp;
	for(int i=0; i<n; ++i) {
		cin >> a[i];
		//make the values small
		if(mp.find(a[i])==mp.end())
			mp.insert({a[i], mp.size()});
		a[i]=mp[a[i]];
	}
	cin >> q;
	for(int i=0; i<q; ++i) {
		cin >> b[i].l >> b[i].r, --b[i].l, --b[i].r;
		b[i].i=i;
	}

	//sort queries
	sort(b, b+q);

	//reset values
	memset(ans, 0, 4*q);
	memset(c, 0, 4*n);
	tx=0;
	memset(cc, 0, 4*(n+1));
	d={};
	memset(bd, 0, 4*(n+1));

	//process queries
	for(int i=0, l=0, r=-1; i<q; ++i) {
		//modify range from previous range
		while(b[i].l<l)
			upd(a[--l], 1);
		while(b[i].r>r)
			upd(a[++r], 1);
		while(b[i].l>l)
			upd(a[l++], -1);
		while(b[i].r<r)
			upd(a[r--], -1);
		//find answer for current range
		//iterate over distinct counts
		vector<int> nd;
		for(int c : d) {
			if(!cc[c]) {
				//this count doesn't actually occur
				bd[c]=0;
				continue;
			}
			int c2=c^tx;
			if(c2<c) {
				//c choose c2
				ans[b[i].i]=(ans[b[i].i]+cc[c]*f1[c]%M*f2[c2]%M*f2[c-c2])%M;
			}
			nd.push_back(c);
		}
		d=nd;
	}
	
	//output
	for(int i=0; i<q; ++i)
		cout << ans[i] << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//precalculate math
	iv[1]=1;
	for(int i=2; i<=mxN; ++i)
		iv[i]=M-M/i*iv[M%i]%M;
	f1[0]=f2[0]=1;
	for(int i=1; i<=mxN; ++i) {
		f1[i]=f1[i-1]*i%M;
		f2[i]=f2[i-1]*iv[i]%M;
	}

	int t;
	cin >> t;
	while(t--)
		solve();
}