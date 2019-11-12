#include<bits/stdc++.h>
using namespace std;

// comlexity best case O( nlog^2(n) )
void shell_sort( int a[] , int n )
{
   int temp , j;

   for( int gap = n/2;    gap>0;    gap = gap/2 )        // O( logn ) , base2 , interval halved every time
   {  
      // everything in the gap( i - loop ) loop goes on for { (n- n/2) + ( n-n/4) +( n-n/8) + ..... (1) } = { nlogn - n } = O(nlogn)
      for(  int i=gap;  i<n;   i=i+1  )                
      {
         temp = a[i];
         for(  j = i;   (j >= gap) && (a[j-gap] > temp);    j = j-gap  )
            a[j] = a[j-gap];
         
         a[j] = temp;
      }
   }
}


void print( int a[] , int n )
{
   cout<<"array: \n";
   for( int i = 0; i < n; i++ )
      cout<<a[i]<<" ";
   cout<<endl;
}

int main()
{
   int a[] = {7,3,9,2,11,1,6,4,8,10,0};
   int n = sizeof(a)/sizeof( int );

   print(a,n);
   shell_sort(a,n);
   print(a,n);

}