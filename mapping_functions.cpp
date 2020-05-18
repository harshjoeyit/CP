#include<bits/stdc++.h>
using namespace std;

int add(int i, int j) { return i + j; }

int sub(int i, int j) { return i - j; }

int mult(int i, int j) { return i * j; }

int divd(int i, int j) { return i / j; }

int mod(int i, int j) { return i % j; }


int main()
{   
    //            - a templete corresponding to functions of this type
    map <string, function<int(int,int)>> BinaryOps;

    BinaryOps.insert( {"+" , add} );
    BinaryOps.insert( {"-" , sub} );
    BinaryOps.insert( {"*" , mult} );
    BinaryOps.insert( {"%" , mod} );
    BinaryOps.insert( {"/" , divd} );

    function<int(int ,int)> f[3];
    f[0] = add;
    f[1] = sub;
    f[2] = divd;
 
    cout << f[0](5,2) << endl; // prints 7                   
    cout << f[1](5,2) << endl; // prints 3
    cout << f[2](5,2) << endl; // prints 1

    // syntax - since for key return type using [] - is of type value  
    //( return type of BinaryOPs[key] is a function) 
    // , so we must call it with arguments 
    cout<<BinaryOps["+"](5,2)<<endl;        
    cout<<BinaryOps["-"](5,2)<<endl;
    cout<<BinaryOps["*"](5,2)<<endl;
    cout<<BinaryOps["/"](5,2)<<endl;
    cout<<BinaryOps["%"](5,2)<<endl;


}