#include<bits/stdc++.h>
using namespace std;
#define int long long int

int pairsWithGivenSum(vector<int> &a, int target) {
      unordered_map<int, int> ump;
      for(auto &x: a) {
            ump[x] += 1;
      }
      int twiceCnt = 0;
      for(auto &x: a) {
            // for every elment in a, count all the values that can 
            // add to this element to give target
            twiceCnt += ump[target - x];
            // decrease count by 1 since we dont want the element 
            // pairing with itself
            if(target % 2 == 0 && x == target/2) {
                  twiceCnt--;
            }
      }

      return twiceCnt/2;
}

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      int n, s;
      cin >> n >> s;
      vector<int> a(n);
      for(auto &x: a) {
            cin >> x;
      } 

      int pairs = pairsWithGivenSum(a, s);
      cout << pairs << endl;
}