#include<bits/stdc++.h>
using namespace std;


vector<int> v;

void checkBound(vector<int>::iterator it) {
      if(it == v.end()) {
            cout << "end!" << endl;
      } else {
            cout << *it << endl;
      }
}

void solve() {
      vector<int> a = {3, 6, 8, 11, 60};
      v.assign(a.begin(), a.end());

      auto it = upper_bound(v.begin(), v.end(), 1);
      checkBound(it);

      it = upper_bound(v.begin(), v.end(), 3);
      checkBound(it);

      it = upper_bound(v.begin(), v.end(), 60);
      checkBound(it);

      it = upper_bound(v.begin(), v.end(), 120);
      checkBound(it);


      // lowerbound

      it = lower_bound(v.begin(), v.end(), 1);
      checkBound(it);

      it = lower_bound(v.begin(), v.end(), 3);
      checkBound(it);

      it = lower_bound(v.begin(), v.end(), 60);
      checkBound(it);

      it = lower_bound(v.begin(), v.end(), 120);
      checkBound(it);

}


// binary search using vector iterators
int binarysearch(int searchy, vector<int>::iterator h, vector<int>::iterator l) {
    vector<int>::iterator mid;
    while(l<=h) {
        mid=l+(h-l)/2;
        if(*mid==searchy)
            return 1;
        if(*mid>searchy)
            h=mid-1;
        else
            l=mid+1;
    }
    return 0;
}


int main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      solve();
}
