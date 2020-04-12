#include<bits/stdc++.h>
using namespace std;

#define int long long

struct mons {
	int p, nxt, i;

	bool operator < (const mons &m) const {
        long double dp = (long double)p;
		long double mdp = (long double)m.p;

		return (dp/nxt < mdp/m.nxt);
    }
};

const int mxN = 3e5+10;
int n;
pair<int, int> a[mxN];

int count_bullets(set<mons> &s) {
	int bul = 0, j, p, nxt;

	while(!s.empty()) {
		auto ob = *(s.begin());
		s.erase(s.begin());
		
		bul += ob.p;
		cout << "poped: ";
		cout << ob.p << " " << ob.nxt << " " << ob.i <<  "\n";
		j = ob.i + 1;
		p = a[j].first;
		nxt = a[j].second;

		auto it = s.find({p, nxt, j});
		if(it != s.end()) {

			if(ob.nxt > p) {
				s.erase(it);
				a[j].first = 0;
			} else {
				s.erase(it);
				a[j].first = p - ob.nxt;
				s.insert({a[j].first, a[j].second, j});
			}

		} else {
			cout << "not found\n";
			break;
		}

		// cout << "set\n";
		// for(auto ob: s)
		// 	cout << ob.p << " " << ob.nxt << " " << ob.i <<  "\n";
	}

	return bul;
}

void solve() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	a[n].first = a[0].first;
	a[n].second = a[0].second;

	set<mons> s;

	for(int i=0; i<n; i++) {
		s.insert({a[i].first, a[i].second, i});
	}
	
	// for(auto ob: s)
	// 	cout << ob.p << " " << ob.nxt << " " << ob.i <<  "\n";
	cout << count_bullets(s) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    	solve();
}