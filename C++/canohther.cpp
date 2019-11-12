#include<iostream>
#include<string.h>

using namespace std;

int main()
 {
     int i=0,j=0,s1=0,s2=0,k=0,N;
     char S[40];
     char E[20];
     char O[20];

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

cout<<"start";
cin>>N;
while(k!=N)
{

        cout<<"enter S \n";
        cin>>S;

        for(j=0;j<strlen(S);j++)
        {
            if(j%2==0)
            {
                E[s1]=S[j];
                s1++;
            }
            else
            {
                O[s2]=S[j];
                s2++;
            }
        }


        for(s1=0;s1<(strlen(S)+1)/2;s1++)
        {
            cout<<E[s1];
        }
        cout<<" ";
        for(s2=0;s2<strlen(S)/2;s2++)
        {
            cout<<O[s2];
        }
    cout<<endl;

k++;
}

 return 0;
}
