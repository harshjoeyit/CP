#include<iostream>

int main()
{

int n1,n2,i;

std::cout<<"enter the first no. \n";
std::cin>>n1;

std::cout<<"enter the second no. \n";
std::cin>>n2;

std::cout<<"no.s are - \n";
for( i=n1;i<=n2-2;i++)
   {
    std::cout<<"\t"<<(i+1);
   }
return 0;
}

