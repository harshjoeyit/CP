
/*
Count of ways to split a given number into prime segments

Input: str = “3175” 
Output: 3 
Explanation: 
There are 3 ways to split this string into prime numbers which are 
(31, 7, 5), (3, 17, 5), (317, 5).

Input: str = “11373” 
Output: 6 
Explanation: 
There are 6 ways to split this string into prime numbers which are 
(11, 3, 7, 3), (113, 7, 3), (11, 37, 3), (11, 3, 73), (113, 73) and (11, 373). 
*/

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6, mod = 1e9+7;
vector<bool> isPrime;
vector<long long int> dp;

void seive() {
	isPrime.assign(mxN, true);
	isPrime[0] = isPrime[1] = false;

	for(int i=2; i<mxN; i++) {
		if(isPrime[i]) {
			for(int j=2*i; j<mxN; j=j+i) {
				isPrime[j] = false;
			}
		}
	}
}

int go(int i, string s) {
	if(i == s.length()) {
		return 1;
	}
	
	if(dp[i] != -1) {
		return dp[i];
	}
	dp[i] = 0;
	string temp = "";
	
	for(int j=i; j<min(i+5, (int)s.length()); j++) {
		temp.push_back(s[j]);
		if(isPrime[stoi(temp)]) {
			dp[i] += go(j+1, s);
			dp[i] %= mod;
		}
	}
	return dp[i];
}

int main() {
	string s;
	cin >> s;
	seive();
	dp.assign(s.length(), -1);
	cout << go(0, s) << endl;
}