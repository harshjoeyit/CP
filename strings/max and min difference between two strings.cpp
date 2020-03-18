#include<bits/stdc++.h>
using namespace std;

struct ans
{
    short int minn,maxx;
};

int main()
{
    ans x[101];
    string s1,s2;
    int T,index=0;
    cin>>T;

    while(T--)
    {
        int count1=0, count2=0;;
        cin>>s1>>s2;

        for(int i=0; i<s1.length(); i++)
        {
             if(s1[i]=='?' || s2[i]=='?')
                ++count1;
            else if(s1[i] != s2[i])
                ++count2;
        }
            x[index].minn = count2;
            x[index++].maxx = count2 + count1;
    }

    for(int i=0; i<index; i++)
        cout<<x[i].minn<<" "<<x[i].maxx<<endl;

    return 0;
}
