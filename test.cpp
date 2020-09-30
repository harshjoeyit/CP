

#include<bits/stdc++.h>
using namespace std;

int main() {
      unordered_map<int, int> ump;
      ump[2] = 3;
      ump[1] = 4;
      ump[5] = 1;

      auto p = *max_element(ump.begin(), ump.end());
      cout << p.first << " " << p.second << endl;
}