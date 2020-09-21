
#include<bits/stdc++.h>
using namespace std;
#define int long long int

/*
count subarrays with siven sum divisble by k
https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/
*/

/*
similar : find longest subarray with sum divisble by k

 Approach for this problem - 
- store the first occurance  index of each mod value in a map
- for each mod value - store the first occurance index, while travesing array, 

- IMP: if mod value repeats itself THEN there is SUBARRAY whose SUM is DIVISIBLE

This works because - 

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
follow the same, 
rem1 = rem2 where
rem1 = Sum of subarray (0, j) % k
rem2 = Sum of subarray (0, i-1) % k 


IMP: also we first occurance of the 0 is at -1 index (for the cases when a prefix of a array is divisble)
*/

// longest Subarray with sum divisble by k
void longestSubarray(vector<int> &a, int k) {
      auto n = a.size();
      unordered_map<int, int> firstOcc;
      firstOcc[0] = -1;
      int curr = 0, maxL = 0, st=-1, en=-1;

      for(int i=0; i<n; i++) {
            curr = ((curr + a[i]) % k + k) % k;
            if(firstOcc.count(curr)) {
                  // mod repeats in the array, find the length of the subarray in between 
                  if(maxL < i - firstOcc[curr]) {
                        maxL = i - firstOcc[curr];
                        st = firstOcc[curr] + 1, en = i;
                  }
            } else {
                  // store the first Occurance
                  firstOcc[curr] = i;
            }
      }

      cout << st << " " << en << endl;
      cout << maxL << endl;
}


/*
This problem is similar here we store the count of all the mod values 
we initialize modCnt[0] = 1 for reasons explained above 

Why we store count?

suppose consider mod value 2 appears like this 

....2.......2...........2.....2.....


this means between any two "2's" there is one subarray such that its sum is divisible by k
and we can count those subarrays using 
total = (modCnt[i]*(modCnt[i] – 1))/2, which is same as nC2 (n combination 2)

why modCn[0] = 1? 

because - 
there is a special case - example 
a = [1, 9, 1] , k = 10
modCnt[0] = 1 ->
modCnt[1] = 2 -> ans += 1

ans comes out to be = 1
but ans = 2;

since if we consider the actual array to be 
new_a = [0, 1, 9, 1]
modCnt[0] = 2 -> ans += 1
modCnt[1] = 2 -> ans += 1

ans = 2 - correct
*/


int countSubarrays(vector<int> a, int k) {
	int n = a.size();
	vector<int> modCnt(k, 0);
	modCnt[0] += 1;	
	int curr = 0;

	for(int i=0; i<n; i++) {
		curr += a[i];
		// for negetive integers too
		modCnt[((curr % k) + k) % k] += 1;
	}
	// remember, for counting all the prefixes such that sum a[0....i] % k = 0 
	
	int ans = 0;
      for(int mod = 0; mod < k; mod++) {
            if(modCnt[mod] > 1) {
                  ans += (modCnt[mod] * (modCnt[mod] - 1))/2;
            }
      }

	return ans;
}


/*
Longest Subarray with sum not divisible by x 
*/


void longestSubarrayNotDivisible() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    
    int s = 0;
    bool alldiv = true;
    for(int i=0; i<n; i++) {
          cin >> a[i];
          s += a[i];
          if((a[i] % x) != 0) {
                alldiv = false;
          }
    }
    // if all the elements are divisible by x - then - no subarray possible
    if(alldiv) {
          cout << -1 << endl;
          return;
    }
    // if sum of all the elements is not divisible by x
    if(s % x != 0) {
          cout << n << endl;
          return;
    }
    // a valid subarray exist, we remove elements from prefix or suffix - 
    // because removing from both ends would shorten the array uneccesarily
    // also removing elements that are divisible by x - renders the array sum still divisible by x
    // so we find the first pos i from start such that a[i] % x != 0 and remove the whole prefix
    // or we find the first pos i from end such that a[i] % x != 0 and remove the whole suffix      
    int ans=0;
    for(int i=0; i<n; i++) {
          if(a[i] % x != 0) {
                // remaining array size if prefix is removed = n-(i+1)
                // if suffix is removed = i
                ans = max({ans, n - (i+1), i});
          }
    }
    cout << ans << endl;
}



// Remove the smallest subarray to make array sum divisible by p

/*
    if there is a subarray that needs to be removed 
    then suppose it has (sum) % p = need
    
    so the problem reduces to smallest subarray with 
    (sum) % p = need;
    
    now suppose 
    sum[0....i] % p = x
    sum[i....j] % p = need
    
    then sum[0....j] % p == 0
    
    so we always find the complement of the need in the map
*/

int minSubarray(vector<int>& a, int p) {

    int need = 0;
    for(auto val: a) {
        need += val;
        need %= p;
    }
    // total sum is divisible by p
    if(need == 0) {
        return 0;
    }

    int n = a.size(), s = 0, ans = n;
    unordered_map<int, int> last;
    last[0] = -1;
    
    for(int i=0; i<n; i++) {
        s = (s + a[i]) % p;
        int comp = (p + s - need) % p;
        
        if(last.count(comp)) {
            ans = min(ans, i - last[comp]);
        }   
        last[s] = i;
    }

    return ((ans == n) ? -1 : ans);
}

signed main() {
	vector<int> a = {1, 9, 9, 1, 9, 1, 1, 9};
	cout << countSubarrays(a, 10);
}