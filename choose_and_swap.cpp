#include<bits/stdc++.h>
using namespace std;

string chooseandswap(string s){
    vector<int> f(26, -1);
    int n = s.length();
    // find first occurance of each char
    for(int i=0; i<n; i++) {
        if(f[s[i] - 'a'] == -1) {
            f[s[i] - 'a'] = i;
        }
    }

     /*  We go from a -> z. 
        If string already lexiographically least (Ex. "abc", "ccffzz")
        then index of first occurance of a larger char (Ex. 'b' > 'a') is greater than the smaller char 
        i.e f['a'] < f['b'] < ........ < f['z'], if these char occur in string

        But if string is of type "abzzybd", then 'z' occurs before 'd', we can swap these two chars to 
        get a lexiographically smallest string.
        
        NOTE: It is always optimal to swap the first char that is out of order. We can swap 'y' with 'd', 
        but it will be lexiographically smallest string.
    */

    // we find the least index of a char with is out of place (i.e. occurs before a smaller char)
    int prevF = -1, minIdx = n;
    for(int i=0; i<26; i++) {
        if(f[i] == -1) {
            // if char does not occur in s
            continue;
        }
        if(f[i] > prevF) {
            // first occ. of this char is greater than previous first occ.
            prevF = f[i];
        } else {
            // this char is out of place
            minIdx = min(minIdx, f[i]);
        }
    }

    // no minIdx found, string is already smallest possible
    if(minIdx == n) {
        return s;
    }

    /*
        we have found one of the two chars i.e. s[minIndex]. 
        NOTE: The other char should have its first occ. after minIndex and should 
        be smaller than s[minIndex]
    */
    char x, y;
    x = y = s[minIdx];
    // start after minIndex + 1
    for(int i=minIdx+1; i<n; i++) {
        if(f[s[i] - 'a'] > f[y - 'a']) {
            // find least of all valid x
            x = min(x, s[i]);
        }
    }
   
    // swap each occurance of x with y and y with x
    for(auto &ch: s) {
        if(ch == x) {
            ch = y;
        } else if(ch == y) {
            ch = x;
        }
    }

    return s;
}
    
    

int main() {
    cout << chooseandswap("ccab") << endl;
    cout << chooseandswap("abczcbcdefe") << endl;
    cout << chooseandswap("abcwxyzcbcdefe") << endl;
    cout << chooseandswap("abba") << endl;
    cout << chooseandswap("zsxcdfezl") << endl;
}