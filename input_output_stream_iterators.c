#include<bits/stdc++.h>
using namespace std; 


int main()

{
    // istream iterators 
    vector<int> vec;
    istream_iterator<int> in_iter(cin) , in(cin);    // reads ints from cin
    istream_iterator<int> eof;              // end iterator 

    while( in_iter != eof )
    vec.push_back(*in_iter++);     // inputs the value then reads the next 
    
    //using algo with istream
    //cout<<accumulate(in_iter , eof , 0 )<<endl;

    cout<<"vec: ";
    for(auto x: vec ) 
        cout<<x<<" ";
    cout<<endl;

    // ofstream iterator
    ostream_iterator<int> out_iter(std::cout, " ");

    //copy(in_iter , eof , out_iter );   , this statement writes the input directly into the output 

    cout<<"vec again: ";
    for (auto e : vec)    
        out_iter = e;  // the assignment writes this element to cout 
    cout << endl;

     cout<<"vec again: ";
    for (auto e : vec)    
        out_iter = e;  // the assignment writes this element to cout 
    cout << endl;


    // copy algo 
    cout<<"vec again: ";
    copy(vec.begin() , vec.end() , out_iter);
    cout << endl;//                copy destination



}