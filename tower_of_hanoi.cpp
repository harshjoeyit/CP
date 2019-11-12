#include<bits/stdc++.h>
using namespace std;

void tower(int n, char source, char auxilliary , char destination)
{
   if(n==1)
   {
       cout<<"move disc 1 from "<<source<<" to "<<destination<<endl;
       return;
   }
   // moving top n-1 discs from source to auxilliary , Auxilliary becomes destination , destination becomes auxilliary
   tower(n-1, source, destination , auxilliary);  // recursing it becouse it is a seperate problem with defined tower, n , source , destination, auxilliary

   cout<<"move disc "<<n<<" from "<<source<<" to "<<destination<<endl;
   
   // movind the n-1 discs  to destination from auxilliary, auxilliary becomes the source , source becomes auxilliary
   tower(n-1, auxilliary, source ,destination);   // recursing it , because it is a seperate problem with defines tower ,n, source , destination, auxilliary
}

int main()
{
   tower(3,'S','A','D');
   return 0;
}