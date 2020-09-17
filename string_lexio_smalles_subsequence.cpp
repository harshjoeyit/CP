
/*
    Find lexiographically smallest subsequence that has all distinct chars of the string
*/


#include <bits/stdc++.h> 
using namespace std; 
  
string smallestSubsequence(string s) {
    /*
        If the next character is smaller than the back of the result string, we remove larger                 
        characters from the back providing there are more occurrences of that character later in              
        the input string.
    */
    
    int cnt[26] = {}, used[26] = {};
    string res = "";
    // cnt counts the remaining character in the string of type 
    // used is for checking if we already have that char in our substring
    
    for(auto ch: s) {
        cnt[ch - 'a'] += 1;
    }
    
    for(auto ch: s) {
        // remove char 
        --cnt[ch - 'a'];
        // check if used, if not mark used 
        if(used[ch - 'a'] > 0) {
            continue;
        }
        
        used[ch - 'a'] += 1;
        
        while(!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
            // remove the larger chars, as they occur later in the string 
            // mark used = 0
            used[res.back() - 'a'] = 0;
            res.pop_back();
        }
        
        res.push_back(ch);
    }
    
    return res;
}