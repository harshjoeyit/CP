
/*
IMP: 
https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/539/week-1-june-1st-june-7th/3352/
https://www.youtube.com/watch?v=_DtZIPUt8jo
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
      int n = people.size();
      if(n <= 1) {
            return people;
      }
      // we arrange people in decreasing order of height 

      // comparitor for sorting people on the basis of height and index 
      auto comp = [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0]) {
                // if height equal arrange them increasing order of index 
                return a[1] < b[1];
            }  
            // arrange them in decreasing order of height
            return a[0] > b[0];
      };
      
      sort(people.begin(), people.end(), comp);
      
      stack<vector<int>> s, temp;

      // now we just need to people in the right spot 
      // we know how many people are taller than a particular person(actually but they are not arranged this way in the queue )
      // there are shorter people in between 
      // the only thing we do is use the (given) number of taller people TO PUT THE PERSON IN THE CORRECT SPOT 
      // SO THAT ONLY THAT NUMBER OF TALLER PEOPLE ARE BEFORE IN THE QUEUE 
      // for example there are 5 people in total that are taller than current peson 
      // but in the queue  only 2 were before him 
      // so we place this person after those 2 person and before remaining 3 person

      for(auto &p: people) {
            int h = p[0];
            int idx = p[1];

            while(s.size() > idx) {
                  temp.push(s.top());
                  s.pop();
            }

            s.push(p);
          
            while(!temp.empty()) {
                  s.push(temp.top());
                  temp.pop();
            }     
      }
      
      vector<vector<int>> ans;
      while(!s.empty()) {
            ans.push_back(s.top());
            s.pop();
      }
      reverse(ans.begin(), ans.end());
      
      return ans;
}


/*
      There is a nlogn approach using segment/fenwick tree
*/

int main() {
      int n;
      cin >> n;
      vector<vector<int> > v;
      v.assign(n, vector<int>(2));
      for(int i=0; i<n; i++) {
            cin >> v[i][0] >> v[i][1];
      }
      auto ans = reconstructQueue(v);

      for(auto v: ans) {
            cout << v[0] << " " << v[1] << endl;
      }
}