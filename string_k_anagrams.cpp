
/*
Two strings are called k-anagrams if following two conditions are true.

Both have same number of characters.
Two strings can become anagram by changing at most k characters in a string.

*/

#include<bits/stdc++.h>
using namespace std;

bool areKAnagrams(string s, string t, int k) {
    int n = s.length();
    int m = t.length();
    
    if(n != m) {
        return 0;
    }
    
    unordered_map<char, int> ump1;
    unordered_map<char, int> ump2;
    for(auto c: s) {
        ump1[c]++;
    }
    
    for(auto c: t) {
        ump2[c]++;
    }
    
    int common = 0;
    for(auto p: ump1) {
        char c = p.first;
        if(ump2.count(c) > 0) {
            common += min(ump1[c], ump2[c]);
        }
    }
    
    // logic - at least n-k chars should be common, 
    // since at max k can be replaced 
    if(common >= n-k) {                  
        return 1;
    }
    
    return 0;
}