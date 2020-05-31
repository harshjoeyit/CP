// there are three cards with 2 characters written on top of them which may be the exactly same .
//the cards may be shuffled or flipped in any way
// if somehow bob appears in any one of the sequence the print yes else print no

#include<bits/stdc++.h>
using namespace std;

void swapit(char *x,char *y)
{
    char t;
    t=*x;
    *x=*y;
    *y=t;
}

bool check(char x, char y, char z)
{
    if(x=='b' && y=='o' && z=='b')
        return true;
    else
    if(y=='b' && z=='o' && x=='b')
        return true;
    else
    if(z=='b' && x=='o' && y=='b')
        return true;
    else
        return false;
}

main()
{
    vector<string> ans;
    int T;
    cin>>T;

    while(T--)
    {
        char a[4],b[4];
        int flag=0;

        for(int i=0; i<3; i++)  // top of three cards
            cin>>a[i];
        for(int i=0; i<3; i++)  //  bottom of three cards
            cin>>b[i];

        if( check(a[0],a[1],a[2]) )  //no swap between top and bottom cards
            flag=1;
        if( check(b[0],b[1],b[2]) )
            flag=1;

        for(int i=0; i<3 && flag == 0; i++)  // one item swap between top and bottom cards
        {
            swapit(&a[i],&b[i]);
            if( check(a[0],a[1],a[2]) )
                flag=1;
            swapit(&a[i],&b[i]);
        }

        for(int i=0; i<3 && flag == 0; i++)  // two item swap on top and bottom cards
        {
            if(i<2)
            {
                swapit( &a[i],&b[i]);
                swapit( &a[i+1],&b[i+1]);
            }
            else
            {
                swapit( &a[0],&b[0]);
                swapit( &a[i],&b[i]);
            }

            if( check(a[0],a[1],a[2]) )
                flag=1;


            if(i<2)
            {
                swapit( &a[i],&b[i]);
                swapit( &a[i+1],&b[i+1]);
            }
            else
            {
                swapit( &a[0],&b[0]);
                swapit( &a[i],&b[i]);
            }
        }

        if( flag == 1 )
            ans.push_back("yes");
        else
            ans.push_back("no");
    }

    for(auto it = ans.begin(); it!= ans.end(); it++)
        cout<<*it<<endl;
}
