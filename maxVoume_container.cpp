
/*
https://leetcode.com/problems/container-with-most-water/submissions/
find the container with the mst volume 

basically find i, j such that (j - i) * min(h[i], h[j]) is maximum 

*/

#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& h) {
      int n = h.size();
      int mx = 0;
      // two pointer 
      int left = 0, right = n-1;
      while(left < right) {
            // container height is min of left and right boundary 
            int height = min(h[left], h[right]);
            // maximzing the ans 
            mx = max(mx, (right - left) * height);
            // the boundary which is minimum moves forward in search for a longer bundary
            if(h[left] < h[right]) {
                left += 1;
            } else {
                  right -= 1;
            }
      }
      return mx;
}

int main() {
}

/*
similar - trap raiwater 
*/