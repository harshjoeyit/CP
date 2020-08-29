#include<bits/stdc++.h>
using namespace std;

string s;
int k;

// O(n)
// make number smallest 
string removeKdigits(string num, int k) {
      stack<char> st;
      int n = num.length();
      for(auto c: num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                  st.pop();
                  k -= 1;
            }
            if(c != '0' || !st.empty()) {
                  // push non zero characters 
                  // or push '0's when they are not preceeding '0's
                  st.push(c);
            }
      }

      // k may not be zero 
      // example s = '123', k = 1
      // no element is ever popped in above condition
      // so pop k elements 
      while (!st.empty() && k--) {
            st.pop();
      }

      // non zero elements <= k, and all have been removed
      if(st.empty()) {
            return "0";
      }

      string ans = "";
      // stack contains our answer, in reverse order ofcourse
      while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
      }
      reverse(ans.begin(), ans.end());
      
      return ans;
}


// for the largest number just reverse condition
// st.top() > c   -------->   st.top() < c



// O(n*n)
string removeKdigits() {
    while(k--) {
        int n = s.length();
        int j = n-1;
        for(int i=0; i<n-1; i++) {
            if(s[i] > s[i+1]) {
                j = i;
                break;
            }   
        }
        s.erase(j, 1);
    }
    // trim string for leading 0s
    while(s.length() > 1 && s[0] == '0') {
        s.erase(0, 1);
    }
    return s;
}



int main() {
    cin >> s >> k;
    // cout << removeKdigits() << endl;
    cout << removeKdigits(s, k);
}