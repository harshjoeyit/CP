
#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/find-longest-awesome-substring/submissions/

An awesome substring is one which can be made palindrome 
by rearranging the characters 
*/

int longestAwesome(string s) {
      // bitmask can go upto 10 set bits 
      // initialize with a high number such as size
      vector<int> firstOcc(1024, s.size());
      int res = 0, mask = 0;
      firstOcc[0] = -1;
      // first Occurance of 0 should be -1
      for(int i=0; i<s.size(); i++) {
            // set/unset the bit corresponding to this char 
            mask ^= (1 << (s[i] - '0'));
            // check if such a mask has occured before 
            res = max(res, i - firstOcc[mask]);
            // check all the possible option by changing 1 bit in this mask 
            // since palindrome can be with 1 odd char
            for(int j=0; j<=9; j++) {
                  int first = firstOcc[mask ^ (1 << j)];
                  res = max(res, i - first);
            }
            // set the firstOcc of mask if it is not set, else donot change it if already set
            firstOcc[mask] = min(firstOcc[mask], i);
      }

      return res;
}



// similar problem 
// longest substring with even vowels 
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/

bool isVowel(char &c) {
    return (c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u');
}

int findTheLongestSubstring(string s) {
      unordered_map<char, int> pos;
      // we map the character to bit positions
      pos['a'] = 0, pos['e'] = 1, pos['i'] = 2, pos['o'] = 3, pos['u'] = 4;
      
      int n = s.length();
      // array to store first occurance of a mask
      vector<int> firstOcc(64, n);
      // first occurance of mask 0 is at -1
      firstOcc[0] = -1;
      int mask = 0, ans = 0;
      
      for(int i=0; i<n; i++) {
            if(isVowel(s[i])) {
	  		// update mask
                  mask ^= (1 << pos[s[i]]);
            }
        	// update ans 
            ans = max(ans, i - firstOcc[mask]);
            if(isVowel(s[i])) {
	      	// update the first occurance of the mask
                  firstOcc[mask] = min(firstOcc[mask], i);
            }
      }
      
      return ans;
}



/*
find number of substring that can be changed to palindromes on shuffling

solution: 
For a substring to be palindromic atmost one character can appear odd times. 
You can represent the status for each of the 26 characters using 26 bits 
(if a character appears even times then it's status can be 0 and if it appears 
odd times it's status can be 1). For every point  find the number of palindromic 
substrings ending at this point. This can be done by hashing the prefix "mask".
At each point  you have to look for 27 different types of strings

string having all characters with even count i.e, mask would be 00......26 times
string having all characters with even count except 'a' i.e, mask would be 0000....1  Similary for characters upto 'z'.

*/

void solve() {
    string s;
    cin >> s;
    int x = 0;
    unordered_map<int , int> ump;
    int ans = 0;
    ump[0] = 1;
    
    for(auto c: s) {
        int val = c-'a';
        x ^= (1 << val);

        // mask repeats that means a substring occurs 
        // that has even number of chars
        if(ump.count(x)) {
            ans += ump[x];
        }

        for(int j=0; j<26; j++) {
            // change mask by 1 bit for each character, 
            // and check if such a mask exists
            // if it does it means a substring with 
            // 1 odd char and rest even occured before  
            if(ump.count(x^(1<<j))) {
                ans += ump[x^(1<<j)];
            }
        }

        ump[x] += 1;
    }
    cout << ans << endl;
}



int main(){
}