
#include <bits/stdc++.h>
using namespace std;

void nextGreater(vector<int> &a) {
      int n = a.size();
      stack<int> st;
      vector<int> nextG(n, -1);
      
      for(int i=0; i<n; i++) {
            while(!st.empty() && a[i] > a[st.top()]) {
                  nextG[st.top()] = a[i];
                  st.pop();
            }
            st.push(i);
      }
}

void nextGreaterCircular(vector<int> &a) {
      int n = a.size();
      stack<int> st;
      vector<int> nextG(n, -1);
      
      for(int i=0; i<2*n; i++) {
            // only one change - i -> i % n to go round the array 
            while(!st.empty() && a[i%n] > a[st.top()]) {
                  nextG[st.top()] = a[i%n];
                  st.pop();
            }
            st.push(i%n);
      }

      for(auto val: a) {
            cout << val << " ";
      }cout << endl;
      for(auto val: nextG) {
            cout << val << " ";
      }cout << endl;
}


// similar problem
// given daily temperatures, 
// find the number days after which a warmer day will come for each day
vector<int> dailyTemperatures(vector<int>& t) { 
      int n = t.size();
      stack<int> st;
      vector<int> ans(n, 0);

      for(int i=0; i<n; i++) {
            while (!st.empty() && t[i] > t[st.top()]) {
                  ans[st.top()] = i - st.top();
                  st.pop();
            }
            st.push(i);
      }
      return ans;
}


int main() {
      vector<int> v = {3,4,5,3,6,7,2,1};
      // nextGreater(v);
      nextGreaterCircular(v);
}

// 1 2 3 1 1    1 2 3 1 1