#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {


    int n,a[102][102]={};
    cout<<"enter n: ";
    cin>>n;
    const int N1= 2*n-2;
    int N2= 2*n-2,s=0;

    while(N2>=0)
    {
        int i=0,j=N1-N2;

        while(j>=0 && i+j <=N1/2)
        {
            a[i][j]=++s;
            ++i;
            --j;
        }
        if(i+j>N1/2)
            break;
        --N2;
    }
    N2= N1/2;
    int x=1;

    while(N2<=N1)
    {
       int i=N1/2,j=x;

        while(i>=x)
        {
            a[j][i]=++s;
            --i;
            ++j;
        }
        ++x;
        ++N2;
    }

    for(int k=0; k<n; k++)
    {
        for(int m=0; m<n; m++)
        {
            cout<<a[k][m]<<"\t";
        }
        cout<<endl;
    }


    }
    return 0;
}




