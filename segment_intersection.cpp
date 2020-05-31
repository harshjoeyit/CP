// finding the intersection of the horizontal segments 
// inersection of sgements (a, b) with (c, d) is valid if a < c < b , and none of a , b, c, d are same or equal 
// each segment has different starting points and end points  


#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long li;
typedef pair<li, li> pt;

const int N = 500010;

int n;
pt a[N];						// input 
vector<int> g[N];				// undirected graph
bool used[N];			

void dfs(int v, int p = -1) 		// p - parent
{
	used[v] = true;
	for (auto to : g[v]) 
		if (to != p) 				// checking cycle 
		{
			if (!used[to])
				dfs(to, v);			// sending parent - v
		}
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%lld%lld", &a[i].x, &a[i].y);			// segment st_pts, end_pts 
	
	vector<pt> evs;				// (st_pt/end_pt , index)
	forn(i, n) {
		evs.pb(mp(a[i].x, i));
		evs.pb(mp(a[i].y, i));
	}
	
	sort(all(evs));
	
	int cnt = 0;
	set<pt> cur;				// (end_pt, index) - pairs
	for (auto it : evs) 
	{
		if (cnt >= n) break;
		if (cur.count(it)) 				// if end point is present in the set, segment open until now  
		{
			cur.erase(it);				// remove end point, segment is closed by removing 
		} 
		else 
		{
			int i = it.y;
			int r = a[i].y;
			for (auto jt : cur) 
			{
				if (jt.x > r) break;				// jt.x = end point of segments in set

				int j = jt.y;			// intersection found
				g[i].pb(j);				// j = index of segment 2
				g[j].pb(i);				// i = index of segment 1
				cnt++;					// edges count increase
				if (cnt >= n) break;
			
			}
			cur.insert(mp(a[i].y, i));				// a[y].i = end pt for ith segment,  insert the end point in set 
		}
	}
	
	dfs(0);
	puts(cnt == n - 1 && count(used, used + n, 1) == n ? "YES" : "NO");
		// edges      ,    all connected               
}
