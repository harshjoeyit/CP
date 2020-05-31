#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
     int i=0,j=0,s1=0,s2=0,k=0,N;
     string S;
     string E;
     string O;
     int l;

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

cin>>N;

for(k=0;k<N;k++)
{
        getline(cin>> ws , S);
        l= S.size();

        for(j=0;j<l;j++)
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


        for(s1=0;s1<(l+1)/2;s1++)
        {
            cout<<E[s1];
        }
        cout<<" ";
        for(s2=0;s2<l/2;s2++)
        {
            cout<<O[s2];
        }
    cout<<endl;
}

 return 0;
}


