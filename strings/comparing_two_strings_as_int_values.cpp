#include<bits/stdc++.h>
using namespace std;

// the inputs are numbers as strings , we check which is greater0
// simply s1>s2 does not work in cases like - 123 & 8 , it shows 8 is greater than 123

int main()
{
    string s1;
    string s2;

    cin>>s1>>s2;
    
    if( (s1.size() == s2.size())&& (s1<s2) || (s1.size()<s2.size()) )
    {
        cout<<"s1<s2\n";
    }
    else
    {
        cout<<"s2<s1\n";
    }
    
}