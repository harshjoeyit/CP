
/*
longest valid parenthesis
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long int
int longestValidParentheses(string s)
{
      stack<int> st;
      st.push(-1);
      int ans = 0;
      for (int i = 0; i < s.length(); i++)
      {
            if (s[i] == '(')
            {
                  st.push(i);
            }
            else
            {
                  if (st.size() == 1)
                  {
                        st.pop();
                        st.push(i);
                  }
                  else
                  {
                        st.pop();
                        ans = max(ans, i - st.top());
                  }
            }
      }
      return ans;
}



/* 
given a string with some parenthesis and other characters too
we need to remove minimmum parenthesis to make the string is valid 
find the length of longest valid string
*/

int n, aptLen;
unordered_set<string> uniq;

void findAptLen(string &s) {
      n = s.length(), aptLen;
      int remove = 0, cnt = 0;
      
      for(auto &c: s) {
            if(c == '(') {
                cnt += 1;
            } else if(c == ')') {
                  if(cnt == 0) {
                        // close bracket without an open bracket 
                        // has to be removed
                        remove += 1;
                  } else {
                        cnt -= 1;
                  }
            }
      }
      
      // extra open brackets have to be removed 
      remove += cnt;
      aptLen = n - remove;
}



// additional problem 
// find all those longest valid strings after removing extra parenthesis 
// https://leetcode.com/problems/remove-invalid-parentheses/

void go(int i, int cnt, string curr, string &s) {
      if(i == n) {
            if(cnt == 0 && curr.length() == aptLen) {
                uniq.insert(curr);
            }
            return;
      }
      
      if(cnt < 0) {
            return;
      }
      
      int maxPos = n - i + curr.length();
      if(maxPos < aptLen) {
            return;
      }
      
      int inc;
      if(s[i] == '(') {
            inc = 1;
      } else if(s[i] == ')') {
            inc = -1;
      } else {
            // other char than (, )
            go(i+1, cnt, curr+s[i], s);
            return;
      }
      
      // skip
      go(i+1, cnt, curr, s);
      // include
      go(i+1, cnt+inc, curr+s[i], s);
}
    
vector<string> removeInvalidParentheses(string s) {
      if(s.empty()) {
          return {""};
      } 

      findAptLen(s);
      if(aptLen == 0) {
            return {""};
      }

      uniq.clear();
      string curr = "";
      int cnt = 0;

      go(0, 0, curr, s);

      vector<string> ans;
      for(auto str: uniq) {
            ans.push_back(str);
      }

      return ans;
}

// another approach - 
// instead of finding the aptLength 
// we can find extra ( brackets that need to be removed that is openCount 
// and extra ) that need to be removed that is closeCount

// we use recursion 
// we skip ( only if leftCount > 0 in recursion
// we skip ) only id right count > 0 in recursion 
// else we have to include then, since we have used up all options 

signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
}