#include<bits/stdc++.h>
using namespace std;

 int main()
 {
     int T;
     vector<string> ans;
     cin>>T;

     while(T--)
     {
         int N,a[101],c1=1,c2=1;
         cin>>N;

         for(int i=0; i<N; i++)
            cin>>a[i];

         for(int i=0; i<=(N-1)/2; i++)
         {
             if( a[(N-1)/2 - i] != a[(N-1)/2 + i] )
             {
                c1=0;
                break;
             }
         }
         if(c1=1)
         {

         for(int i=0; i<(N-1)/2; i++)
         {
             if( (a[(N-1)/2 - i] - a[(N-1)/2 - i -1] ) > 1 || (a[(N-1)/2 - i] - a[(N-1)/2 - i -1] ) < 0 )
             {
                 c2=0;
                 break;
             }
         }

         }
         if ( c1 && c2 && (N%2 != 0) )
            ans.push_back("yes");
        else
            ans.push_back("no");
     }

     for(auto it = ans.begin(); it != ans.end(); it++)
        cout<<*it<<endl;

     return 0;
 }
