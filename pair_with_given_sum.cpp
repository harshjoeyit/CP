#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Using O(n) time and space 
int pairsWithGivenSum(vector<int> &a, int target) {
      unordered_map<int, int> ump;
      for(auto &x: a) {
            ump[x] += 1;
      }
      int twiceCnt = 0;
      for(auto &x: a) {
            // for every elment in a, count all the values that can 
            // add to this element to give target
            twiceCnt += ump[target - x];
            // decrease count by 1 since we dont want the element 
            // pairing with itself
            if(target % 2 == 0 && x == target/2) {
                  twiceCnt--;
            }
      }

      return twiceCnt/2;
}


// Using O(nlogn) time O(1) space, 
// using two pointers 
// but used for just finding the if pair exists 

int pairWithGivenSum(vector<int> &a, int target) {
      sort(a.begin(), a.end());
      int st = 0, en = a.size() - 1;
      while(st < en) {
            int s = a[st] + a[en];
            if(s > target) {
                  en -= 1;
            } else if(s < target) {
                  st += 1;
            } else {
                  return 1;
            }
      }
      return 0;
}


// pair with a given sum in sorted rotated array 
// O(logn) + O(n)
// use binary search to find the index of min element and largest element 
// use two pointers and (i) % n to move the indexes forward and backward 

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, s;
      cin >> n >> s;
      vector<int> a(n);
      for(auto &x: a) {
            cin >> x;
      } 

      int pairs = pairsWithGivenSum(a, s);
      cout << pairs << endl;
}