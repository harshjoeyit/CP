#include<bits/stdc++.h>
using namespace std;

// stores index of the char in window 
int indexOfChar[256];
int lengthOfLongestSubstring(string str) {
    	if(str.length() == 0) {
      	return 0;
    	}
    
    	string s = str;
    	s = s + str[str.length()-1];
    	memset(indexOfChar, -1, sizeof(indexOfChar));
    	int st = 0;						// start of the window 
    	int ans = 0;
    
    	for(int i=0; i<s.length(); i++) {
      	int j = (int)(s[i]);
        
        	if(indexOfChar[j] == -1) {		// if there is no repetition in the current window - add char to window 
            	indexOfChar[j] = i;
        
        	} else {					// char at i is already in the window 
            	ans = max(ans, i-st);
            	int k;
            	for(k = st; k <= indexOfChar[j]; k++) {		// remove all the char from window up untill the repeated char's index
                		indexOfChar[(int)s[k]] = -1;			// these chars will not be in new window 
            	}
            	st = k;							// window start from next index in the previous window where the repeated char was found
            	indexOfChar[j] = i;					// include this char in windoe 
        	}
    	}
    	return ans;
}