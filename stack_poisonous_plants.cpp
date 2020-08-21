
/*
https://www.hackerrank.com/challenges/poisonous-plants/

plants with pesticide levels are given 
any plant that has higher pesticide level than the plant on the left dies on that day
count days it takes before plant stop dieing 
*/

#include<bits/stdc++.h>
using namespace std;

#define plantID first
#define daysToDie second

int main()
{     
      int N;
      cin >> N;
      vector<int> pLevel(N);
      for (int i = 0; i < N; i++) {
            cin >> pLevel[i];
      }

      // the max days needed to die among all the plants
      int maxDaysToDie = -1;
      stack<pair<int, int>> s;
      s.push({0, -1});

      for (int i = 1; i < N; i++) {
            int daysToDie = 1;

            while (!s.empty()) {
                  // we only care about the plants whose pesticide is smaller (potential killer)
                  if (pLevel[i] <= pLevel[s.top().plantID]) {
                        // need to wait the front plants to die, like "1 5 7 4", 4 will die only after 5 and 7 died
                        daysToDie = max(daysToDie, s.top().daysToDie + 1);
                        s.pop();
                  }
                  else {
                        break;
                  }
            }
            if (s.empty()) {
                  // this means no preceding plants have less pesticide than ith plant
                  daysToDie = -1;
            }

            // push the current element with number of days it will take to die 
            cout << i << " " << daysToDie << endl;
            s.push({i, daysToDie});
            // our answer 
            maxDaysToDie = max(maxDaysToDie, daysToDie);
      }

      cout << (maxDaysToDie < 0 ? 0 : maxDaysToDie) << endl;
      return 0;
}

