#include <iostream>
using namespace std;

int main()
{
    int arr[6][6];
    for(int i=0; i<6; i++)
    {
        for(int j=0; j<6; j++)
        cin>>arr[i][j];
    }


   int l=1,k=0,s,sum=-9999,c1=1;

    for(k=0;k<4;k++)
    {
        for(l=0;l<4;l++)
            {
            s= (arr[k][l] + arr[k][l+1] + arr[k][l+2]) + (arr[k+1][l+1]) + (arr[k+2][l] +  arr[k+2][l+1]  + arr[k+2][l+2]);

            cout<<"sum of "<<c1<<"th hourglass= "<<s<<endl;
            c1++;
            if(s>sum)
                sum=s;
            }
    }

    cout<<"max= "<<sum;


    return 0;
}
