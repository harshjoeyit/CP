#include<bits/stdc++.h>
using namespace std;

int main()
{
    short int T;
    vector<string> ans;
    cin>>T;

    while(T--)
    {
        int m=0,s=0;
        string line;
        cin>>line;

        line = "x" + line + "x";

        for(int i=0; i<line.length(); i++)
        {
            if(line[i]=='m')
                ++m;
            else if(line[i]=='s')
                ++s;
            else
                goto endd;

            if(line[i]=='s')
            {
                if(  line[i+1]=='m' )
                    --s;
                else
                if(line[i+1]=='s' || line[i+1]=='x')
                {
                    if( line[i-1]=='m' && ( line[i-2] !='s') )
                       --s;
                }
            }
        }

        if(s == m)
            ans.push_back("tie");
        else
        if(s > m)
            ans.push_back("snakes");
        else
            ans.push_back("mongooses");
    }

    for(auto it = ans.begin(); it!= ans.end(); it++)
        cout<<*it<<endl;

    endd:
    return 0;
}
