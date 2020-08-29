#include<bits/stdc++.h>
using namespace std;


int nextGreaterNotInArray(int low, int high, vector<int> a, int x, int n) {
    if(x >= a[n-1]) {
        // the element we are looking for is 
        // greater than the greatest element in the array  
        return x + 1;
    }

    int ans = x+1;
    // and = next greater 
    // we continue with the loop untill ans is not found 
    // that means it is number that we want 
    while( low <= high) {
        int mid = low + (high-low)/2;
        
        if (a[mid] == ans) {
            // ans is present in the array 
            // we search for next greater 
            //   ans++
            ans++; 
            // search space increased 
            high = n - 1; 
            low = mid + 1;
        } 

        if (a[mid] < ans) {
              low = mid + 1;
        }
        else {
              high = mid - 1; 
        }
    } 

    return ans;
}


// easier implementation 

int nextGreaterNotInArray(vector<int> &a, int x) {
      auto ub = upper_bound(a.begin(), a.end(), x);
      // keep continuing untill upperbound is in the array 
      while (ub != a.end() && x + 1== *ub) {
            // x becomes this upper bound
            x = *ub;
            // find upper bound of new x
            ub = upper_bound(a.begin(), a.end(), x);
      }
      return x + 1;
}

int main() {
    vector<int> v= {1,2,3,10,12,14,15,16,17};
    int x;
    cin >> x;
    
    //sort
    sort(v.begin(), v.end());

    cout << nextGreaterNotInArray(0, v.size()-1, v, 20, v.size()-1 ) << endl;
    cout << nextGreaterNotInArray(v, x);
}
