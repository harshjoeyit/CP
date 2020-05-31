#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> dq)
{
    cout<<"vector: "<<endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
        cout<<*it<<" ";
}

int main()
{
    vector<int>v1={10,20,30,40,50,60};
    vector<int>vec1={10,20,30,40,50,60};

    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);
    vector<int>v2=v1;
    vector<int>v3(5,10);
    vector<int>v4(5);  // prints 5 times 0
    vector<string> v5(10, "hi!");  // using: {} causes error
    vector<char> v6(10,'a');
    vector<int> v;
    v.reserve(5);  //set capacity

        for(unsigned int i=0;i<11;i++)  // size is not specified only capacity is so cannot use v.size()
    {
        int n;
        cout<<"enter"<<endl;
        cin>>n;
        v.push_back(n);
    }
        for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";   // capacity changes in the multiple of 10
    }                      // if i=5 capacity =5  as specified
                           //if i =6 capacity = 10
                           //if i= 11 capacity = 20

    cout<<"capacity: "<<v.capacity()<<", size"<<v.size()<<endl;


    cout<<"vector : ";
    for(unsigned int i=0; i<v1.size(); i++)
    cout<<v1[i]<<" ";

        cout<<"vector : ";
    for( int i=0; i<v2.size(); i++)
    cout<<v2[i]<<" ";

        cout<<"vector : ";
    for(int i=0; i<v3.size(); i++)
    cout<<v3[i]<<" ";

        cout<<"vector : ";
    for(int i=0; i<v4.size(); i++)
    cout<<v4[i]<<" ";
cout<<endl;
         cout<<"vector : ";
    for(int i=0; i<v5.size(); i++)
    cout<<v5[i]<<" ";


         cout<<"vector : ";
    for(int i=0; i<v6.size(); i++)
    cout<<v6[i]<<" ";

       vector<int>::iterator it ;
   it = vec1.begin()+3;
   cout<<*it<<endl;

    display(vec1);
   it = vec1.insert(it,111);  // returns the iterator pointing to the element that was added

   display(vec1);
   cout<<endl<<*it<<endl;

   it = vec1.insert(it,5,4);  // returns vector to the first element added 




return 0;
}
