#include<bits/stdc++.h>
using namespace std;

string inttostring(int);
//comparator function
bool cmp(int x,int y)
{
//    if(x==99,)
    string s1=inttostring(x);
    string s2=inttostring(y);
    string s3=s1+s2;  // do not use strcat(a,b) it is for c style string
    string s4=s2+s1;

    if(s3>s4)
        return true;
    else
        return false;
}

string inttostring(int n)
{
    stringstream ss;
    ss << n <<endl;
    string newstring =ss.str();
    return newstring;
}

main()

{// cannot just sort like that because 10,9 make problem  as 910 > 109
    int a[]={9,6,5,7,8,10};
    sort(begin(a),end(a),cmp);
    for(int i=0; i<6;i++)
        cout<<a[i];
}
