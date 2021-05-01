
/*
      Similar Problem   
      Pair with a given sum in a sorted rotated array
      https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int

// Using O(n) time and space 

// Method 1:
int getPairsCount(vector<int> &arr, int n, int k) {
    int ans = 0;
    for(int i=0; i<n; i++) {
    unordered_map<int, int> ump;
        if(ump.count(k - arr[i])) {
            ans += ump[k - arr[i]];
        }
        ump[arr[i]]++;
    }
    return ans;
}

// Method 2:
int getPairsCount(vector<int> &a, int target) {
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

int checkPairSumExists(vector<int> &a, int target) {
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

}