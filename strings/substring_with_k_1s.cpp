
/*
substring containing exactly K ones, here string is binary 
use subarray with a siven sum approach

similar problem 
given an array of numbers, count the subarray with k 1s 
Sol - make all other elements 0 and use countSub method 
to count subarray with a given sum
*/

#include<bits/stdc++.h>
using namespace std;

int countSub(vector<int> &a, int s) {
      unordered_map<int, int> ump;
      int curr = 0, ans = 0, n = (int)a.size();
      
      for(int i=0; i<n; i++) {
            curr += a[i];
            if(curr == s) {
                  ans += 1;
            }
            if(ump.count(curr - s)) {
                  ans += ump[curr - s];
            }

            ump[i] += 1;
      }
      return ans;
}

void go(string &s, int k) {
      int n = (int)s.length();
      vector<int> a(n, 0);
      for(int i=0; i<n; i++) {
            a[i] = s[i] - '0';
      }

      cout << countSub(a, k) << endl;
}

int main() {
      string s;
      int k;
      cin >> s >> k;
      go(s, k);
}