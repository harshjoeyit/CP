#include<bits/stdc++.h>
using namespace std;

int dig(int bal)
{
    int i=0;
    while(bal != 0)
    {
        bal = bal/10;
        ++i;
    }
    return i;
}

main()
{
    int wd;
    float bal;
    cin>>wd>>bal;

    if( ((int)wd)%5 != 0 )
        cout<<setprecision(dig(bal)+2)<<bal;

    else if( float(wd + 0.5) > bal)
        cout<<setprecision(dig(bal)+2)<<bal;

    else if( wd != 0)
    {
        bal = bal- wd - 0.5;
        cout<<setprecision(dig(bal) + 2)<<bal;
    }
}
