#include<bits/stdc++.h>
using namespace std;

main()
{
    short int T,i=0;
    pair<int,string> ans[501];
    cin>>T;

    while(T--)
    {
        short int seat,rem;
        string stype;
        cin>>seat;

        rem = seat%8;
        // seat type
        if(rem==1 || rem ==4)
            stype="LB";
        else
        if(rem==2 || rem ==5)
            stype="MB";
        else
        if(rem==3 || rem==6)
            stype="UB";
        else
        if(rem==0)
            stype="SL";// corresponding seat type
        else
        if(rem==7)
            stype="SU";// corresponding seat type

        // seat number
        if(rem ==0 )
            seat -= 1;
        else
        if(rem >=0 && rem <=3)
            seat += 3;
        else
        if(rem >3 && rem<=6)
            seat -= 3;
        else
        if(rem == 7)
            seat += 1;

        ans[i].first = seat;
        ans[i++].second = stype;
    }

    for(int j=0; j<i; j++)
        cout<<ans[j].first<<ans[j].second<<endl;
}
