#include<bits/stdc++.h>
using namespace std;
#define int long long 

/*
https://leetcode.com/problems/find-the-duplicate-number/solution/
read all the methods 
IMPORTANT
There is only one duplicate number in the array, 
but it could be repeated MORE THAN ONCE.

Solution uses - Floyd's Hare and Tortoise Algo (used for finding cycle int the linked list)
*/
int findDuplicate(vector<int>& nums) {
      // the cycle is here for sure 
      // due to given conditions 
      int slow = 0, fast = 0;   
      do {
            slow = nums[slow];
            fast = nums[nums[fast]];
      } while(slow != fast);

      slow = 0;

      while(slow != fast) {
            fast = nums[fast];
            slow = nums[slow];
      }
      return slow;
}

/*
all the numbers in the array occur twice except for 2 values 
find those (could be negetive as well)
*/
vector<int> singleNumber(vector<int>& nums) {
      // int xor1 = 0;        
      // for(auto &val: nums) {
      //       xor1 ^= val;
      // }

      // better way to find the xor 
      int lastSet = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
      // we could find any set bit (one will be set since the no are distinct)
      // here we find value with the last set bit
      lastSet &= -lastSet;

      cout << lastSet << endl;

      int x = 0, y = 0;
      for(auto val: nums) {
            if(val & lastSet) {
                  x ^= val;
            } else {
                  y ^= val;
            }
      }
      return {x, y};
}

void solve() {
    int n;
    cin >> n;

    int xr = 0;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int indices[n+1];
    for(int i=1; i<= n; i++)            // set all indices to 1
        indices[i] = 1;

    int rep;
    for(int i=0; i<n; i++) {            // if element is found set index = -1
        if(indices[a[i]] == 1)
            indices[a[i]] = -1;
        else                           // if -1 index is found - means repeated value
            rep = a[i];   
    }

    int mis;
    for(int i=1; i<=n; i++) {          // positive index found - means value never occurs in the array 
        if(indices[i] == 1) {
            mis = i;
            break;
        }
    }

    cout << rep << " " << mis << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}