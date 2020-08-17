
/*
https://leetcode.com/problems/validate-stack-sequences/
check if the popped array can be a sequence of push and pop options on pushed array 

Idea - we try to recreate the situation how the element would have been pushed to give this 
pooped sequence 
so, we push the pushed sequence untill there is no match of the top element with the current char 
of popped sequence

when we find a match, we pop from stack and move forward in the pooped sequence 
*/

#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
      stack<int> st;
      int i = 0, n = pushed.size();
      for(auto val: pushed) {
            // push the chars from pushed sequence 
            st.push(val);
            while(!st.empty() && st.top() == popped[i]) {
                  // if the top element matched that char of popped seq 
                  st.pop();
                  // pop this char 
                  i += 1;
                  // increment to move forward in popped sequence  
            }
      }
      return st.empty();
}

int main() {
}