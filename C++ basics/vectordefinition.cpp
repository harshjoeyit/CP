#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
vector<int> ivec;           //valid program it prints the finally changed value
ivec.push_back(43);
ivec.push_back(43);
ivec[0]=42;
ivec[1]=42;
cout<<ivec[0]<<" "<<ivec[1];

/* vector<int> ivec2;         //this does not print any value
ivec2[0]=41;                  //vector size of elements not defined
cout<<" "<<ivec[0]; */

cout<<"\nenter (n) as the size of the vector : ";          //vector may be defined in this way
int n;                         // unlike array
cin>>n;
vector<int> ivec3(n);  // a vector must be defined in some ay ti print the values in it
ivec3[0]=1;             // vector size=0 and values =0
                        // now values can be changed of any element
for(unsigned int i=0; i<ivec3.size(); i++)
{
    ivec3[i]=i;
}

cout<<"\ninteger vector:  ";
for(unsigned int i=0; i<ivec3.size(); i++)
{
    cout<<ivec3[i]<<" ";
}

return 0;
}
