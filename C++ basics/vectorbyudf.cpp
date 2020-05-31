#include<iostream>
#include<vector>
using namespace std;

void vectorin(vector<int> &vec1)   //by reference ,the variable defined is just a dummy variable
{
    int c=1;
    while(c!=0)
    {
       int n=0;
       cout<<"\n enter the n:";
       cin>>n;
       vec1.push_back(n);
       cout<<"\n press 0 to stop adding and any other no. to continue";
       cin>>c;
    }
}

void vectorchange(vector<int> &vec2)   //the variable defined is just a dummy variable
{                                       //could have used vec1 also
                                        // defining new variable just adds more references to passed vector ( it has more names vec1 ,vec2 to refer to it they all have the same address)
    for(unsigned int i=0; i<vec2.size(); i++)
    vec2[i]=2*vec2[i];
}

void vectorout(vector<int> &vec1)    //by reference
{
    cout<<"\nchanged vector: ";
    for(unsigned int i=0; i<vec1.size(); i++)
    cout<<vec1[i]<<" ";
}

int main()
{
  vector<int> myvector;
  vectorin(myvector);

  cout<<"\noriginal vector: ";        // original value change due passed value due to reference so
  for(unsigned int i=0; i<myvector.size(); i++)
  cout<<myvector[i]<<" ";

  vectorchange(myvector);
  vectorout(myvector);

  myvector.erase(myvector.begin(),myvector.begin()+3);  // IMP: erases three from the beginning

  cout<<"\nchanged vector: ";        // changed value change due passed value due to reference so
  for(unsigned int i=0; i<myvector.size(); i++)
  cout<<myvector[i]<<" ";

  return 0;
}
