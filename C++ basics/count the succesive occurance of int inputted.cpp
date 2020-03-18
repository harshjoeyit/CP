#include<bits/stdc++.h>
using namespace std;

main()
{
    int c1,c2,countt=1;

    cin>>c1;
    c2=c1;

    while(cin>>c2)
    {
        if(c2 == c1 )
            ++countt;
        else
        {
            cout<<"count for "<<c1<<" = "<<countt<<endl;
            c1 = c2;
            countt = 1;
        }
    }
}
