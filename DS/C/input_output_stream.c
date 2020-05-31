#include<bits/stdc++.h> 
using namespace std;

bool read( istream &input , int &x )    // must use refenece to input the same obeject that is passed 
{
    cout<<"read: ";
    if( input>>x )
        return true;
    else
        return false;
}

void print( ostream &output , int x )
{
    output<<"output: "<<x<<endl;
}


int main()
{
    int x = 0;
    if( read( cin , x ) )
        print( cout , x );
   
}