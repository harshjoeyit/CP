
/*
check if array elements can be distributed in pairs 
such that each pair sum is divisible by given k
*/


#include <bits/stdc++.h>
using namespace std;

bool check(int arr[], int n, int k) {
      unordered_map<int, int> freq;

      for (int i = 0; i < n; i++) {
            // store the remainder of the elements 
            freq[arr[i] % k]++;
      }

      for (int i = 0; i < n; i++) {
            int rem = arr[i] % k;

            // 2*rem == k 
            // that means such elements can only be paired up each other 
            // simply it means they should be even, to pair up
            if (2 * rem == k) {
                  if (freq[rem] % 2 != 0)
                        return false;
            }

            // rem = 0 means element is multiple of k
            // these elements can only be paired with each other 
            // so they must be even in number 
            else if (rem == 0) {
                  if (freq[rem] & 1)
                        return false;
            }

            //  in all other cases 
            // rem is paired with k - rem 
            // so they should be equal in number
            else if (freq[rem] != freq[k - rem]) {
                  return false;
            }
      }
      return true;
}

int main()
{
      string s;
      cin >> s;
      cout << longestPalindrome(s);
}