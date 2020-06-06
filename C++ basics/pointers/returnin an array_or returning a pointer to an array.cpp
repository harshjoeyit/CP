#include<bits/stdc++.h>
using namespace std;

int (*func(int i))[3]
{
    static int a[3]={i*10,i*20,i*30};
    return &a;
}

int main()
{
    int a[3][3]={1,2,3,4,5,6,7,8,9};
    int (*p)[3] = a;

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<(*p)[j]<<" ";
        ++p;
        cout<<endl;
    }

    p = func(**p);

    cout<<(*p)[0]<<" "<<(*p)[1]<<" "<<(*p)[2]<<endl;
}

