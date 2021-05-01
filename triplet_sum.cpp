
/*
    Triplet Sum Problem
*/

#include<bits/stdc++.h>
using namespace std;

/*
    triplet sum = 0 (returning all unique pairs)
    Note: To count all pairs (not-unique), find unique pairs and frequency of each element
    For each pair (a, b, c) with frequency (f1, f2, f3) add (f1*f2*f3) to ans
*/
vector<vector<int>> threeSumZeroPairs(vector<int>& nums) {
      if(nums.size() == 0) {
            return {};
      }
      
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      vector<vector<int>> ans;

      for(int i=0; i<n; i++) {
            int l = i+1, r = n-1;
            
            if(nums[i] > 0) {
                break;
            }
          
            while(l < r) {
                  int s = nums[i] + nums[l] + nums[r];
                  if(s == 0) {
                        vector<int> temp = {nums[i], nums[l], nums[r]};
                        ans.push_back(temp);

                        // skipping the duplicates
                        while(l < r && nums[l] == temp[1]) {
                              l++;
                        }
                        while(l < r && nums[r] == temp[2]) {
                              r--;
                        }

                  } else if(s > 0) {
                        r--;
                  } else {
                        l++;
                  }
            }

            // skipping the duplicates
            while(i+1 < nums.size() && nums[i+1] == nums[i]) {
                  ++i;
            }
      }
      return ans;
}


// triplet sum = target (find triplet, hashing approach )
bool find3Numbers(int a[], int n, int sum) {
    for(int i=0; i<n-2; i++) {
        unordered_set<int> st;
        int remSum = sum - a[i];
        for(int j=i+1; j<n; j++) {
            if(st.count(remSum - a[j])) {
                return true;
            }
            st.insert(a[j]);
        }
    }
    return false;
}
  

// triplet sum =  target (find triplet, two pointer approach)
bool find3Numbers(int a[], int n, int sum) {
    for(int i=0; i<n-2; i++) {
        int j =  i+1, k = n-1;
        while(j < k) {
            int s = a[i] + a[j] + a[k];
            if(s == sum)      return true;
            else if(s < sum)  j++;
            else            k--;
        }
    }
    return false;
}



/*
	find maximum triplet sum (a[i] + a[j] + a[k]) satisying 
	all are distinct and i < j < k
*/

int maxTripletSum(vector<int> &a) {
	int n = a.size();
	
	vector<int> maxr(n);
	maxr[n-1] = a[n-1];
	for(int i=n-2; i>=0; i--) {
		maxr[i] = max(maxr[i+1], a[i]);		
	}

	set<int> st;
	st.insert(a[0]);
	int ans = 0;

	for(int i=1; i<n-1; i++) {
		// store the elements in the set 
		st.insert(a[i]);
		if(maxr[i+1] <= a[i]) {
			// no element tp the r is greater
			continue;
		}

		auto it = st.lower_bound(a[i]);
		if(it == st.begin()) {
			// no element smaller exist 
			continue;
		}

		// *it is the max elements just smaller than a[i]
		--it;
		// found the triplet t
		int s = *it + a[i] + maxr[i+1];
		ans = max(ans, s);
	}
	return ans;
}


int main() {
}