/*
    https://www.geeksforgeeks.org/tug-of-war/
*/


#include<bits/stdc++.h>
using namespace std;

/*
    Method 1.
*/

int n, ts;
int minDiff = INT_MAX;
vector<int> finalPicked;

void print(vector<int> &);

void go(int i, int sum, vector<int> picked, vector<int> &a) {
	if(i == n) {
		int diff = abs(ts - 2*sum);
		if(picked.size() == n/2 && minDiff > diff) {
			finalPicked = picked;
			minDiff = diff;
		}
		return;
	}
	// we need to choose exactly n/2 elements
	if(picked.size() > n/2) {
		return;
	}
	// skip 
	go(i+1, sum, picked, a);
	// choose
	picked.push_back(a[i]);
	go(i+1, sum + a[i], picked, a);
	picked.pop_back();
}

void solve1() {
	vector<int> a = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	n = a.size();
	ts = accumulate(a.begin(), a.end(), 0); 
	vector<int> picked = {};
	go(0, 0, picked, a);
	print(a);
}

void print(vector<int> &a) {
	int s1= 0, s2= 0;
	// print 1st set
	for(auto val: finalPicked) {
		cout << val << " ";
		s1 += val;
	}
	cout << "\t = " << s1 << endl;
	// print second set
	for(auto &val1: a) {
		bool flag = true;
		for(auto &val2: finalPicked) {
			if(val1 == val2) {
				flag = false;
				val2 = INT_MIN;
			}
		}
		if(flag) {
			cout << val1 << " ";
			s2 += val1;
		}
	}
	cout << "\t = " << s2 << endl;
}


/*
    Method 2.
*/

// find the minDiff possible
int go(int i, int sum, int picks, vector<int> &a) {
	if(i == n) {
		return (picks == n/2) ? abs(ts - 2*sum) : INT_MAX;
	}
	if(picks > n/2) {
		return INT_MAX;
	}
	return min(go(i+1, sum, picks, a), go(i+1, sum+a[i], picks+1, a));
}


void solve2() {
    vector<int> a = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	n = a.size();
	ts = accumulate(a.begin(), a.end(), 0); 
	int minDiff = go(0, 0, 0, a);

	/*
    s1 + s2 = ts 
	s1 - s2 = minDiff
	2 * s1 = (ts + minDiff)
	s1 = (ts + minDiff)/2;

	Now have to find a subset with sum = s1, 
    the remaining elements of a form s2
    */
} 