

/*
find celebrity in minimu queries 
queries are of type does A know B - our matrix has answer to them
celebrity is 
      - one everyone knows
      - one who knows nobody


brute force approach O(n^2) time comlexity 
ask n*(n-1)/2 questions and fiil the indegree and outdegree array 
traverse arrays if a person with indegree = n-1 and outdegree = 0 occurs then this is the celebrity 
else nobody is 


better approach using stacks 
*/

#include<bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>> mat) {
      int n = (int)mat.size(), a, b;
      stack<int> st;
      // place all celebrity in the stack
      for(int i=0; i<n; i++) {
            st.push(i);
      }

      // do untill 2 or more celebrities are remaining 
      while(st.size() > 1) {
            a = st.top(); 
            st.pop();
            b = st.top();
            st.pop();

            if(mat[a][b] == 1) {
                  // if a knows b, then a cant be a celebrity b is potential celebrity
                  st.push(b);
            } else {
                  // a doesnt know b, a could be the celebrity 
                  st.push(a);
            }
      } 

      a = st.top();
      // a is just a potential celebrity 
      // lets check conditions 

      for(int i=0; i<n; i++) {
            // we dont check conditions with himsilf
            if(i != a) {
                  // if we find someone who doesnt know a 
                  // or someone who a knows then
                  if(mat[i][a] == 0 || mat[a][i] == 1) {
                        return -1;
                  }
            }
      }

      return a;
}

int main() {
      int n;
      cin >> n;
      vector<vector<int>> mat(n, vector<int>(n, 0));
      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                  cin >> mat[i][j];
            }
      }
      cout << findCelebrity(mat) << endl;
}