#include<bits/stdc++.h>
using namespace std;

bool customComp(const pair<int, int> &a, const pair<int, int> &b) {
      cout << a.first << " " << b.first << endl;
      return a.first < b.first;
}

int main() {
      unordered_map<int, int> ump;
      ump[2] = 1;
      ump[3] = 4;
      ump[1] = 11;      
      ump[0] = 1;

      auto p = *max_element(ump.begin(), ump.end(), customComp);
      cout << p.first <<" " << p.second << endl; 
}