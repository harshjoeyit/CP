#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> transposeWithExtraSpace(vector<vector<int>> &a) {
	vector<vector<int>> b(a);
	int n = b.size();

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			b[j][i] = a[i][j];
		}
	}
	return a;
}

void transposeInPlace(vector<vector<int>> &a) {
	int n = a.size();

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			swap(a[j][i], a[i][j]);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	a = transposeWithExtraSpace(a);
	
	for(auto vec: a) {
		for(auto x: vec) {
			cout << x << " ";
		}
		cout << endl;
	}

	transposeInPlace(a);

	for(auto vec: a) {
		for(auto x: vec) {
			cout << x << " ";
		}
		cout << endl;
	}
}