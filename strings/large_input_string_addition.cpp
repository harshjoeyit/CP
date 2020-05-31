#include<bits/stdc++.h>
using namespace std;


string addStrings( string &s1 , string &s2 )
{
    stack<char, string> S1(s1);        // creating stack and initializing with the string 
    stack<char, string> S2(s2);        // creating stack

    string add = "";                // the add string initialized to be empty 
    int carry=0, val;

    while( !S1.empty() || !S2.empty() )     // iteraton continue until each of the stack becomes empty 
    {
        val = 0;                            //variable for cureent sum of values at each index 
        if( !S1.empty() )
        {
            val += static_cast<int>(S1.top()) - '0';        // converting to int adding to value
            S1.pop();
        }
        if( !S2.empty() )
        {
            val += static_cast<int>(S2.top()) - '0';            // converting to int and adding to val
            S2.pop();
        }

        val += carry;               // adding the carry from previous sum

        if( val - 9 > 0 )           // we use the carry if value of sum > 10
        {
            carry = 1;
            add += ( static_cast<char>( val - 10 ) + '0' );     // addding the value converted to ASCII to the present string 
        }
        else
        {
            carry = 0;
            add += ( static_cast<char>( val ) + '0' );          // if there is no carry 
        }
    }
    if( carry == 1)                         // at the end when all the stacks are empty 
                                            // and stilll thew carry exist we add "1" to the number 
    add.insert( add.size() , "1" );         //inserting at last 
    reverse( add.begin() , add.end() );      // present string is reversed of the actual value 
    
    return add;
}

int main()
{
    string s1;
    string s2;

    cout<<"s1: ";
    cin>>s1;
    cout<<"s2: ";
    cin>>s2;

    string add =  addStrings( s1 , s2 );
    cout<<"add: "<<add<<endl;   
}