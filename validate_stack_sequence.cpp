
/*
https://leetcode.com/problems/validate-stack-sequences/
check if the popped array can be a sequence of push and pop options on pushed array 
*/

#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> st;
      int i = 0, n = pushed.size();
      for(auto val: pushed) {
            st.push(val);
            while(!st.empty() && st.top() == popped[i]) {
                  st.pop();
                  i += 1;
            }
      }
      return st.empty();
}

int main() {
}