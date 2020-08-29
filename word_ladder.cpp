


#include<bits/stdc++.h>
using namespace std;

// Complexity analysis 
// O(n*m*m)
// n - entries in the dict 
// m - each word length

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
	// make dictionary 
      unordered_set<string> dict(wordList.begin(), wordList.end());     
	// ending word should be in dictionary
      if(dict.count(endWord) == 0) {
            return 0;
      }

      queue<string> q;
	// start
      q.push(beginWord);
      dict.erase(beginWord);
      int steps = 0;

      while (!q.empty()) {                                                    // O(n)
            steps += 1;
            int sz = q.size();
		// another while loop is used to traverse current level nodes 
		// this is quite standard way to do level order travesal 
            while (sz--) {
					// current word 
                  string u = q.front();
                  q.pop();
					
                  if(u.compare(endWord) == 0) {                  
                        // we found it!
						return steps;
                  }

                  for (auto &c : u) {                                         // O(m)
                        char save = c;
                        for (int i = 0; i < 26; i++) {      
                              c = (char)('a' + i);
							  
					// change current character and make new string 
                              if(dict.count(u)) {
                                    q.push(u);
						// erase used word
                                    dict.erase(u);                            // O(m)
                              }
                        }
				// restore for the next iteration
                        c = save;
                  }
            }
      }

      return 0;
}

int main() {
      vector<string> wordList = {
    "poon", 
    "plee", 
    "same", 
    "poie", 
    "plie", 
    "poin", 
    "plea"};

      cout << ladderLength("toon", "plea", wordList);
}