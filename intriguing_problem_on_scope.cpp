#include<bits/stdc++.h>
using namespace std;

int main()
{
   int a,b;
   cin>>a>>b;

   if(a>b)
   {
      int i = a-b;
      cout<<"i=(a-b)= "<<i<<endl;

      if( i>5 )
      {
         int i = a+b;
         cout<<"i = (a+b)= "<<i<<endl;
      }
   }

   else
   {
      int i = a*b;
      cout<<"i= (a*b) = "<<i<<endl;

      if(i>10)
      {
         int i = b/a;
         cout<<"i= (b/a) = "<<i<<endl;
      }
   }
   
}