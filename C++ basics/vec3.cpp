#include<iostream>
#include<vector>
using namespace std;

int main()
{

    int n;
    vector<int> vec;
    for(int i: vec)                        //entering just one value
    {
        cout<<"enter the values"<<endl;
        if (cin>>n)                        //entering and checking at the same time
        {
            vec.push_back(n);               //entering in vector and breaking
            break;
        }
    }

    cout<<"vector: ";
    for(unsigned int j=0; j<vec.size();j++)
    cout<<vec[j]<<" ";

    vector<int> vec1;
    vec1=vec;
    // or initialization are valid with c++11 or before vec={10,20,30};
    cout<<"\nvector: ";
    for(unsigned int j=0; j<vec.size();j++)
    cout<<vec[j]<<" ";

    if(vec==vec1)
    cout<<"\nsuccess";

    return 0;
}
