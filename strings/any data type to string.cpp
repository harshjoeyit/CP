// any data type to string
#include<bits/stdc++.h>
using namespace std;

template<typename T>
string inttostring(T i)
{
    stringstream s;
    s << i;
    return s.str();
}

int main()
{
    float i=155.89;
    cin>>i;
    string ss= inttostring(i);
    cout<< ss;
}
