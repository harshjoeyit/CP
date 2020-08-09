
/*
count subarrays with siven sum divisble by k
https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/


similar : find longest subarray with sum divisble by k

- simple - make map <int, pai<int, int> > 
for each mod value - store the first and the last occurance 
traverse map - find the largest diff in first and last pos 
remeber to insert {0, {0, 0}} before hand 


let there exist a subarray (i, j) whose sum is divisible by k
sum(i, j) = sum(0, j) - sum(0, i-1)

Sum for any subarray can be written as q*k + rem where q 
is a quotient and rem is remainder
Thus,     
    sum(i, j) = (q1 * k + rem1) - (q2 * k + rem2)
    sum(i, j) = (q1 - q2)k + rem1-rem2

We see, for sum(i, j) i.e. for sum of any subarray to be
divisible by k, the RHS should also be divisible by k.
(q1 - q2)k is obviously divisible by k, for (rem1-rem2) to 
follow the same, rem1 = rem2 where

    rem1 = Sum of subarray (0, j) % k
    rem2 = Sum of subarray (0, i-1) % k 

we make an Array - modCnt = [] that stores number of times a mod value appears 
in prefix sum of the array 

now traverse the modCnt array - 
if(modCnt[i] > 1) 
	then we can choose any two i, j among modCnt[i] such that rem1 == rem2 = i
	so ans += (modCnt[i]*(modCnt[i] – 1))/2

IMP - 
but we forgot that that for mod = 0
there is a special case - example 
a = [1, 9, 1] , k = 10
modCnt[0] = 1 -
modCnt[1] = 2 - ans += 1

ans comes out to be = 1
but ans = 2;

since if we consider the actual array to be 
new_a = [0, 1, 9, 1]
modCnt[0] = 2 - ans += 1
modCnt[1] = 2 - ans += 1

ans = 2 - correct
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int


int countSubarrays(vector<int> a, int k) {
	int n = a.size();
	vector<int> modCnt(k, 0);

	int curr = 0;
	for(int i=0; i<n; i++) {
		curr += a[i];
		// for negetive integers too
		modCnt[((curr % k) + k) % k] += 1;
	}
	// remember, for counting all the prefixes such that sum a[0....i] % k = 0 
	modCnt[0] += 1;	

	int ans = 0;
      for(int mod = 0; mod < k; mod++) {
            if(modCnt[mod] > 1) {
                  ans += (modCnt[mod] * (modCnt[mod] - 1))/2;
            }
      }

	return ans;
}


signed main() {
	vector<int> a = {1, 9, 9, 1, 9, 1, 1, 9};
	cout << countSubarrays(a, 10);
}