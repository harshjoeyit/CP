#include<bits/stdc++.h>
using namespace std;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    	int n, m, a, b, c;
	cin >> n >> m;

	vector<int> v(n+1);

	for(int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		// - for lender, + for borrower 
		v[a] = v[a] - c;
		v[b] = v[b] + c;
	}

	vector<vector<int>> ans;

	int j = 1;
	for(int i=1; i<=n; i++) {					
		while(v[i]>0) {
			// v[i] > 0, borrower
			auto &borrower = v[i];
			// find v[j] < 0, a lender 
			while (v[j] >= 0 && j <= n) {
				j++;
			}
			auto &lender = v[j];
			int Min = min(borrower, -lender);
			borrower -= Min;
			lender += Min;
			ans.push_back({j, i, Min});
		}
	}

	cout << ans.size() << endl;
	for(auto &t: ans)
		cout << t[0] << " " <<t[1] << " " << t[2] << endl;

}