#include<bits/stdc++.h>
using namespace std;
#define int long long 

/*
https://leetcode.com/problems/find-the-duplicate-number/solution/
read all the methods 
IMPORTANT
There is only one duplicate number in the array, 
but it could be repeated MORE THAN ONCE.
*/

// METHOD 1.
// After swapping, the repeated element will be at index 0
int findDuplicate(vector<int>& a) {
    int n = a.size();
    for(int i=0; i<n; i++) {
        while(a[i] != a[a[i]]) {
            swap(a[i], a[a[i]]);
        }
    }
    return a[0];
}

// METHOD 2.
// Solution uses - Floyd's Hare and Tortoise Algo (used for finding cycle int the linked list)
int findDuplicate(vector<int>& nums) {
      // We use the fact that the cycle is present(due to given conditions)
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


/*
    values are in range [1, n] and 
    one of them is missing and one is repeating, find both 

    https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
*/

/*
    Other Method
    1. Sort Array
    2. Hash Table (count frequency)
*/

/*
    Method 1: swap each element to its right index
    Finally, the REPEATED element occupies index of MISSING element
    O(1) space
*/
void findTwoElement(int *arr, int n) {
    for(int i=0; i<n; i++) {
        while(arr[i] != arr[arr[i] - 1])  {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    int rep, mis;
    for(int i=0; i<n; i++) {
        if(i != arr[i]-1) {
            rep = arr[i];        // repeating
            mis = i + 1;         // missing
            break;
        }
    }
    
    cout << rep << " " << mis << endl;
}


/*
    Method 2: Mark each elements correct index once it is visited
    If mark twice it is REPEATED element, if unmarked MISSING
    O(n) space
*/
void solve(vector<int> &a) {
    int n = a.size();

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


/*
    Method 3: Using Xor 
*/

int *findTwoElement(int *a, int n) {
    
    int xr = 0;
    for(int i=1; i<=n; i++) {
        xr ^= i;
    }
    for(int i=0; i<n; i++) {
        xr ^= a[i];
    }

    /* Get the rightmost set bit in set_bit_no */
    int b = xr & ~(xr -1);
    int x = 0;

    for(int i=1; i<=n; i++) {
        if(i & b) {
            x ^= i;
        }
    }
    for(int i=0; i<n; i++) {
        if(a[i] & b) {
            x ^= a[i];
        }
    }
    // the two numbers are x, xr^x, but we don't know 
    // which is REPEATING and which is MISSING
    
    int mis = x, rep = xr ^ x;
    for(int i=0; i<n; i++) {
        if(a[i] == x) {
            mis = xr^x;
            rep = x;
            break;
        }
    }

    cout << mis << " " << rep << endl;
}

/*
    Method 4: (Make two equations using sum and sum of squares)
    Let x be the missing and y be the repeating element.
    Let N is the size of array.
    Get the sum of all numbers using formula S = N(N+1)/2
    Get the sum of square of all numbers using formula Sum_Sq = N(N+1)(2N+1)/6
    Iterate through a loop from i=1….N
    S -= A[i]
    Sum_Sq -= (A[i]*A[i])
    It will give two equations 
    x-y = S – (1) 
    x^2 – y^2 = Sum_sq 
    x+ y = (Sum_sq/S) – (2) 
*/


signed main() {

}