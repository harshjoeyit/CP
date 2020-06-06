#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> ivec;  // empty vector
    vector<int> jvec;
    int c=1;

    for(unsigned int j=0;j<10;++j)
    {
       if(c==0)
           break;
       int n;
       cout<<"\n enter the n:";
       cin>>n;
       jvec.push_back(n);                 // invalid:   ivec[j]=n;
       cout<<"\n press 0 to stop adding and any other no. to continue";
       cin>>c;
    }

    for(unsigned int j=0;j<jvec.size();++j)
        cout<<jvec[j]<<" ";


    return 0;
}

