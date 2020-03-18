#include <bits/stdc++.h> 
using namespace std; 
  
// Returns true if s1 is substring of s2 
int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 

    for (int i = 0; i <= N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
  
        if (j == M) 
            return i; 
    } 
  
    return -1; 
} 
  
  
int main() 
{ 
    string s1,s2;
    cout<<"enter the string: ";
    getline( cin , s2);
    cout<<"enter the sub-string ";
    getline(cin , s1);

    int res = isSubstring(s1, s2); 
    if (res == -1) 
        cout << "Not present"; 
    else
        cout << "Present at index " << res; 
    return 0; 
}