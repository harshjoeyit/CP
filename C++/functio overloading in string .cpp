#include<bits/stdc++.h>
using namespace std;

string & ret_string(string & str) // or  string ret_string //even work without a const
{
    cout<<"worked 1"<<endl;
    return str;
}

const string & ret_string ( const string & str = "#####")  // same goes for this function
{
    cout<<"worked 2"<<endl;
    return str;
}

int main()
{
    string str;
    cout<<ret_string("&&&&&")<<endl;
    str = "*****";
    cout<<ret_string(str)<<endl;
}
