/*
For each query find the how mnay numbers repeat 3 times
Simple approach is to cnt from l to r in each range - O(n^2)

MO Algorithm

This is other but efficient appproch
Complexity - O(n * sqrt(n))
*/

// problem st: answer queries for number of unique elements in range [l,r]

#include<bits/stdc++.h> 
using namespace std; 

#define int long long int

const int N = 30005;
const int M = 1e6+5;
int cnt[M];			    		
int a[N];
int curL = 0;
int curR = 0;
int ans = 0;
int n;
int sqrtn;

void add(int i) {
	cnt[a[i]]++;
	if(cnt[a[i]] == 1)
		++ans;
}

void rem(int i) {
	cnt[a[i]]--;
	if(cnt[a[i]] == 0)
		--ans;
}

void findAns(int L, int R) {
	while(curL < L) {           // loop works for curL <= L-1 and stpos on curL = L
		rem(curL);
		curL++;
	}
	while(curL > L) {
		add(curL-1);            // as loop worked till curL <= L-1 for previous time ans settled on L
		curL--;
	}
	while(curR < R+1) {         // loop works till curR <= R ans stops on curR = R+1
		add(curR);
		curR++;
	}
	while(curR > R+1) {         // as loop worked till curR <= R for previous time ans settled on R
		rem(curR-1);
		curR--;
	}
}

struct query {
	int L, R, pos, ans;
};

bool comp(query q1, query q2) {
	if((q1.L/sqrtn) == (q2.L/sqrtn))
		return (q1.R < q2.R);
	return (q1.L/sqrtn < q2.L/sqrtn);
}

bool comp2(query q1, query q2) {
	return (q1.pos < q2.pos);
}

void MOsAlgo() {
	int q;
	cin >> q;
	vector<query> v(q);

	for(int i = 0; i < q; i++) {
		int L, R;
		cin >> v[i].L >> v[i].R;
        --v[i].L; 
        --v[i].R;
		v[i].pos = i;
		v[i].ans = 0;
	}

	// arranging the queries is ascending order of L / sqrt(n)
	// breaking the tie by arranging in ascending order of R
	sort(v.begin(), v.end(), comp);

	for(int i = 0; i < q; i++) {
		findAns(v[i].L, v[i].R);
		v[i].ans = ans;
	}

	sort(v.begin(), v.end(), comp2);
	for(int i = 0; i < q; i++)
		cout << v[i].ans << "\n";
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	sqrtn = sqrt(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	MOsAlgo();
}