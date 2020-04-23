
/*
	You are given two arrays A,B(1-indexed) of equal size N and a number K.
	For every index i(1..N) we have to select either Ai or Bi, such that sum of 
	selected numbers is minimum and atleast K numbers from selected numbers must be from array A.

	Simply: for each index we can either choose A[i] or corresponding B[i], and least k should be from A[i]

	Logic: first we are choosing the k elements from A[i] and reject corresponding B[i]
			we do this by finding diff = A[i] - B[i]
			the more lower diff is the lower our sum will be for k elements 

			for rest n-k elements we can choose min(A[i], B[i])

			so we sort the array in this fasion 
*/



#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e6+10;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    int dif1 = p1.first - p1.second;
    int dif2 = p2.first - p2.second;
    return (dif1 < dif2);
}

void solve() {
    int n, k;
    cin >> n;

    int a[n], b[n];
    pair<int, int> c[n];
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        c[i].first = a[i];
    }
    for(int i=0; i<n; i++) {
        cin >> b[i];
        c[i].second = b[i];
    }

    cin >> k;
    sort(c, c+n, comp);

    int s = 0;
    for(int i=0; i<n; i++) {
        if(i < k) {
            s += c[i].first;
        } else {
            s += min(c[i].first, c[i].second);
        }
    }
    cout << s << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}