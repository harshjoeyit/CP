
/*
triplet sum 0
*/

#include<bits/stdc++.h>
using namespace std;

// returning all unique pairs 
vector<vector<int>> threeSum(vector<int>& nums) {
      if(nums.size() == 0) {
            return {};
      }
      
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      vector<vector<int>> ans;

      for(int i=0; i<n; i++) {
            int left = i+1, right = n-1;
            
            if(nums[i] > 0) {
                break;
            }
          
            while(left < right) {
                  int s = nums[i] + nums[left] + nums[right];
                  if(s == 0) {
                        vector<int> temp = {nums[i], nums[left], nums[right]};
                        ans.push_back(temp);

                        // skipping the duplicates
                        while(left < right && nums[left] == temp[1]) {
                              left++;
                        }
                        while(left < right && nums[right] == temp[2]) {
                              right--;
                        }

                  } else if(s > 0) {
                        right--;
                  } else {
                        left++;
                  }
            }

            // skipping the duplicates
            while(i+1 < nums.size() && nums[i+1] == nums[i]) {
                  ++i;
            }
      }
      return ans;
}


// checking 
// hashing O(n^2) - O(n) - space 
void findTriplets(int arr[], int n) 
{ 
    bool found = false; 
  
    for (int i=0; i<n-1; i++) 
    { 
        // Find all pairs with sum equals to "-arr[i]"
        unordered_set<int> s; 
        for (int j=i+1; j<n; j++) 
        { 
            
            int x = -(arr[i] + arr[j]); 
            if (s.find(x) != s.end()) 
            { 
                printf("%d %d %d\n", x, arr[i], arr[j]); 
                found = true; 
            } 
            else
                s.insert(arr[j]); 
        } 
    } 
  
    if (found == false) 
        cout << " No Triplet Found" << endl; 
} 
  

// two pointer approach

void twoPointerApproach(vector<int> &v) {
    sort(v.begin(), v.end());

    int i = 0, l, r;
    bool flag = true;

    while((v[i] <= 0) && flag)
    {
        //cout << "a[i]: " << v[i] << endl;
        l = i+1;
        r = n-1;

        while(l < r)
        {
            //cout << "l: " << v[l] << ", r: " << v[r] << endl;
            int sum = v[i] + v[l] + v[r];
            
            if(sum == 0)
            {
                flag = false;
                break;
            }
            else 
            if(sum > 0)
                --r;
            else
            if(sum < 0)
                ++l;
        }
        ++i;
    }
    if(!flag)
        cout << v[i-1] << " " << v[l] << " " << v[r] << endl;
    else
        cout << "not possible" << endl;
} 


// counting all triplets with sum = 0
// use either a + b + c = d
// or use two pointer with counting pair with a given sum

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];


}