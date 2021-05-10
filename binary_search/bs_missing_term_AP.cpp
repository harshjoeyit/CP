#include <bits/stdc++.h>
using namespace std;

int missing(vector<int> a) {
    int n = a.size(), diff = (a[n-1] - a[0])/n;
    int l=0, h=n-2; 
    // excluding the last term from binary search, 
    // since we need (mid, mid+1)
    
    while(l <= h) {
        int mid = (l + h)/2;
        int currDiff = a[mid+1] - a[mid];
        if(diff != currDiff) {
            // find the value of middle element
            return a[mid] + currDiff/2;
        }
        // (mid + 1)th term
        int term = a[0] + mid*diff;
        if(term == a[mid]) {
            // no term is missing till (mid + 1)th term
            l = mid + 1;
        } else {
            // term is missing before (mid + 1)th term
            h = mid-1;
        }
    }
    return -1;
}

int main() {
    cout << missing({2, 6, 8, 10, 12, 14}) << endl;
}