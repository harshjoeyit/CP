#include <bits/stdc++.h> 
using namespace std; 
  
// replace o by n in string s
void change_a_word_in_old(string o, string &s , string n) 
{ 
    int M = o.length(); 
    int N = s.length(); 

    for (int i = 0; i <= N - M; i++) 
    { 
        int j; 
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (s[i + j] != o[j]) 
                break; 
  
        if (j == M)
            s.replace(i,M,n);       // replace function of the string container 
        /*  
        i - position of replacable string ( o )
        M - length of string
        n - new string ( n ) 
        */
    }
} 
  
  
int main() 
{ 
    string s , o , n;
    cout<<"s : ";
    getline( cin , s);
    cout<<"o : ";
    getline(cin , o);
    cout<<"n : ";
    cin>>n;

    change_a_word_in_old( o , s , n ); 

    cout<<" changed s: "<<endl;
    cout<<s;

    return 0; 
}