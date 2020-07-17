
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


signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0);
}