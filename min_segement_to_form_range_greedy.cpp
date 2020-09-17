

/*
min segments to cover the range 
range [0, target]

Ex - target = 3
segs: [0,1], [2,3]
ans = -1 
since they are disjoint, 

segs = [0, 1], [1, 3]
ans = 2
*/

#include<bits/stdc++.h>
using namespace std;

int minSegments(vector<vector<int>> segs, int target) {
	// considering that a subset fo segs will completely cover target
      sort(begin(segs), end(segs));
	int i = 0, st = 0, end = 0, res = 0;
	// segements start at 0

	while (st < target) {
		while (i < segs.size() && segs[i][0] <= st) {
			// end is farthest end pt of any segment
			end = max(end, segs[i][1]);
			i += 1;
		}
		if (st == end) {
			return -1;
		}
		st = end;
		res += 1;
	}
	return res;
}

int main() {

      // array input 
      
      int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
      

}