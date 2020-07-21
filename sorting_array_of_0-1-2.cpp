#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
      if(nums.size()<= 1) {
            return;
      }        
      int low=0, mid=0, high=nums.size()-1;
      
      while(mid <= high) {
            if(nums[mid] == 0) {
                  swap(a[mid], a[low]);
                  low += 1;
                  mid += 1;

            } else if(nums[mid] == 2) {
                  swap(a[mid], a[high]);
                  high -= 1;

            } else {
                  mid += 1;
            }
      }
}

int main() {

}