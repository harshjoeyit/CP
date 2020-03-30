// C++ program to find count of substring containing  
// exactly K ones 
#include <bits/stdc++.h> 
using namespace std; 
  
int countOfSubstringWithKOnes(string s, int K) 
{ 
    int N = s.length(); 
    int res = 0; 
    int c_one = 0; 
    int freq[N + 1] = {0}; 
  
    // initialize index having zero sum as 1 
    freq[0] = 1; 
    for (int i = 0; i < N; i++) { 
        c_one += (s[i] - '0');              // total no of 1 till index i
        if (c_one >= K) {                   // for 1's greater than k
            res += freq[c_one - K];         // add frequency of indices, having 
        }                                   // sum (current sum - K), to the result 
        // update freqency of one's count 
        freq[c_one]++; 
    } 
    return res; 
} 
int main() 
{ 
    string s = "10010"; 
    int K = 1; 
    cout << countOfSubstringWithKOnes(s, K) << endl; 
    return 0; 
} 