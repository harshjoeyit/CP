#include<bits/stdc++.h>
using namespace std;


// The find smaller numbers than the current in whole array 
// i.e find count of all j such that i != j and a[i] > a[j]

// 1. Brute force O(n^2)

// 2. O(nlogn)
 
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      int n = (int)nums.size();
      vector<pair<int, int>> v;
      vector<int> ans(n, 0);

      // storing the number and its index 
      for(int i=0; i<n; i++) {
            v.emplace_back(nums[i], i);
      }
      // sorting based on value of the number 
      sort(v.begin(), v.end());
      
      // the first one is minimum so no element is less than it 
      ans[v[0].second] = 0;
        
      for(int i=1; i<n; i++) {
            int j = v[i].second;
            int val = v[i].first;
            // pj is index of previous element in sorted order
            int pj = v[i-1].second;
            // pval is the value of previous element in sorted order 
            int pval = v[i-1].first;

            // if the values we distinct then we would not this if condition 
            // simply assign i to ans[j]
            if(val == pval) {
                  ans[j] = ans[pj];
            } else {
                  ans[j] = i;
            }
      }

      return ans;
}


// 3. O(n) - hashing 
// similar to counting sort 
// can be used since there nums[i] <= 100

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
      int n = (int)nums.size();
      vector<int> freq(101, 0);
      vector<int> pref(101, 0);
      for(auto &val: nums) {
            freq[val] += 1;
      }

      // take prefix sum of freq array
      // then freq[i] will tell us number of element that 
      // are less than it in the nums array 
      for(int i=1; i<n; i++) {
            pref[i] = pref[i-1] + freq[i-1];
      }

      vector<int> ans(n);
      // now we care for only those indices in freq
      // that occur in nums
      for(int i=0; i<101; i++) {
            ans[i] = pref[nums[i]];
      } 

      return ans;
}




// Similar Problem 
// Count j such that j  > i and a[i] > a[j]
// i.e count smaller elements after self 


// can be solved using similar approach as inversion counting

int n;
vector<int> ans;
vector<pair<int, int>> temp;

void merge(vector<pair<int, int>> &p, int st, int mid, int en) {
      int i = st, j = mid + 1, k = st;
      while (i <= mid && j <= en) {
            int smaller = en - j + 1;

            if (p[i].first > p[j].first) {
                  ans[p[i].second] += smaller;
                  temp[k] = p[i];
                  k++, i++;
            }
            else {
                  temp[k] = p[j];
                  k++, j++;
            }
      }
      while(i <= mid) {
            temp[k] = p[i];
            k++, i++;
      }
      while(j <= en) {
            temp[k] = p[j];
            k++, j++;
      }

      for (int i = st; i <= en; i++) {
            p[i] = temp[i];
      }
}

void mergeSort(vector<pair<int, int>> &p, int st, int en) {
      if(st < en) {
            int mid = (st + en) / 2;
            mergeSort(p, st, mid);
            mergeSort(p, mid + 1, en);
            merge(p, st, mid, en);
      }
}

vector<int> countSmaller(vector<int>& nums) {
      n = nums.size();
      ans.assign(n, 0);
      temp.assign(n, {0,0});
      vector<pair<int, int>> p;
      for (int i = 0; i < n; i++) {
            p.emplace_back(nums[i], i);
      }
      mergeSort(p, 0, n - 1);
      return ans;
}





int main() {

}