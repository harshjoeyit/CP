
/*
https://www.geeksforgeeks.org/amazon-interview-experience-set-149-campus-internship/
*/

#include<bits/stdc++.h>
using namespace std;

int getNum(char c) {
      c = tolower(c);
      if(c >= 'w') {    
            return 9;
      } else if(c >= 't') {
            return 8;
      } else if(c >= 'p') {
            return 7;
      } else if(c >= 'm') {
            return 6;
      } else if(c >= 'j') {
            return 5;
      } else if(c >= 'g') {
            return 4;
      } else if(c >= 'd') {
            return 3;
      } else {
            return 2;
      }
}

struct st {
      string a, b;
      int i;
};


bool scomp(const string &a, const string &b) {
      return (a + b) < (b + a);
}

int main() {
      int t;
      cin >> t;
      vector<st> ans;
      for (int i = 0; i < t; i++)
      {
            string s;
            cin >> s;
            string code = "";
            for(auto &c: s) {
                  code.push_back(getNum(c) + '0');
                  c = tolower(c);
            }
            ans.push_back({code, s, i});
      }

      auto comp = [](const st &a, const st &b) {
            if(a.a == b.a) {
                  return a.i < b.i;
            }
            return !scomp(a.a, b.a);
      };

      sort(ans.begin(), ans.end(), comp);

      for(auto e: ans) {
            cout << e.a << " " << e.b << endl;
      }
}