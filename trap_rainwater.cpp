#include <bits/stdc++.h>
using namespace std;

/*
      Method 1:
      Brute Force, for each tower, find the largest to its left and right and find the trapped water
      O(n*n) time, O(1) space
*/


/*
      Method 2.01:
      Pre compute leftmax and rightmax for each tower
      O(n) time, O(n) space
*/
int trap(vector<int> &a) {
      if (a.size() == 0 or a.size() == 1) {
            return 0;
      }
      int n = a.size();
      int l[n], r[n];
      l[0] = a[0];
      r[n - 1] = a[n - 1];

      for (int i = 1; i < n; i++) {
            l[i] = max(a[i], l[i - 1]);
      }
      for (int i = n - 2; i >= 0; i--) {
            r[i] = max(a[i], r[i + 1]);
      }
      int ans = 0;
      for (int i = 0; i < n; i++) {
            ans += min(l[i], r[i]) - a[i];
      }
      return ans;
}


/*
      Method 2.02
      Using Stack 
      O(n) time, O(n) Space
*/
int maxWater(int height[], int n) {
    stack <int> st;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        while ((!st.empty()) && (height[st.top()] < height[i])) {
            int pop_height = height[st.top()];
            st.pop();

            if (st.empty())     break;
            // Get the distance between the
            // left and right boundary of popped bar
            int distance = i - st.top() - 1;

            // Calculate the min. height
            int min_height = min(height[st.top()], height[i]) - pop_height;

            ans += distance * min_height;

        }
        st.push(i);
    }
    return ans;
}


/*
      Method 3:
      Space Optimization for Method 2
      O(n) time, O(1) space
*/
int findWater(int arr[], int n) {
    int ans = 0, lmax = 0, rmax = 0;
    int lo = 0, hi = n - 1;

    // the lowest height pointer i.e. min(lmax, rmax) moves forward, 
    // so we can be calculate water stored by lmax and rmax alone.
    while (lo <= hi) {
        if (arr[lo] < arr[hi]) {
            if (arr[lo] > lmax) {
                lmax = arr[lo];
            }
            else {
                ans += lmax - arr[lo];
            }
            lo++;
        }
        else {
            if (arr[hi] > rmax) {
                rmax = arr[hi];
            }
            else {
                ans += rmax - arr[hi];
            }
            hi--;
        }
    }
    return ans;
}



int main() {
}

/*
similar problem - find largest container for storing water 
*/