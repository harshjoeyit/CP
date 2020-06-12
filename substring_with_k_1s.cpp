
/*
substring containing exactly K ones 
nice approach
*/

#include <bits/stdc++.h> 
using namespace std; 
  
int countOfSubstringWithKOnes(string s, int K) { 
    int N = s.length(); 
    int res = 0; 
    // count of ones
    int c_one = 0; 
    int freq[N + 1] = {0}; 
  
    // initialize index having zero sum as 1 
    freq[0] = 1; 
    for (int i = 0; i < N; i++) { 
        c_one += (s[i] - '0');              
        if (c_one >= K) {                   
            res += freq[c_one - K];         
        }                                   
        freq[c_one]++; 
    } 
    return res; 
} 

int main() { 
    string s = "10010"; 
    int K = 1; 
    cout << countOfSubstringWithKOnes(s, K) << endl; 
    return 0; 
} 