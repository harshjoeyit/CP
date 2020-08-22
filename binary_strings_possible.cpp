
/*
      total number of binary strings possible when 
      there cannot be x continuous 1s and y continuous 0s
*/

#include<bits/stdc++.h>
using namespace std;

int n, x, y;

void go(int i, int currX, int currY, string s) {
      if(currX > x || currY > y) {
            return;
      }
      if(i >= n) {
            cout << s << endl;
            return;
      }

      go(i+1, 0, currY + 1, s + '0'); 
      go(i+1, currX + 1, 0, s + '1');
}

int main() {
      cin >> n >> x >> y;
      string ans = "";
      go(0,0,0,ans);
}