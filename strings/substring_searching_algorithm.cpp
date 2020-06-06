#include <bits/stdc++.h> 
using namespace std; 
  

int substring(string str, string substr)
{
    int N = str.length();
    int M = substr.length();

    for(int i = 0; i <= N - M; i++)
    {
        int j;

        for(j = 0; j < M; j++)
            if(str[i+j] != substr[j])
                break;
        
        if(j == M)
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

    int res = substring(s1, s2); 
    if (res == -1) 
        cout << "Not present"; 
    else
        cout << "Present at index " << res; 
    return 0; 
}