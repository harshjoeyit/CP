#include<bits/stdc++.h>
using namespace std;

// # define is apreprocessor directive to define a macro
// here BEGIN , END ... are MACROS
// all preprocessor directive have got a funtion to do before the actual compilation has started
// macro is text substitution definition , which means it replaces the defined text with its original value in the respective desfinition  
// this is how amacro works that is by replacing the tex before the compile time
// this is nonly a tool for the purpose , if the developer wants to define the code in the different way for the better understanding  


#define BEGIN {  //  these macros 
#define END }
#define INTEGER int 

// PREDEFINED PREPROCESSOR 
#if !defined (MESSAGE)
#define MESSAGE "You wish!"
#endif

// PARAMATRIZED MACROS 
#define square(x) ((x) * (x) )
// advanage : the value is evaluated and replaced by actual piece of code at the compile tin=me
// suppose if quare was the functtion the memory would be allocated and deacllocated to it in the call stack but here is what a macro does
// it simply replaces itself with the code 
// it may be used for in simple codes such as this but is not practical to use it in the longer programmes 
// functions are fine and apt for them

INTEGER main()
BEGIN

    INTEGER i=10;
    INTEGER j=3;
    while(i != 0)
    BEGIN
        cout<<i--<<" ";
    END
    cout<<endl;
    cout<<"the MESSAGE IS: "<<MESSAGE<<endl;
    cout<<"square of "<<j<<" = "<<square(j);

END

// this code is translated before the compilation as

/* 
int main()
{
    int j=3;
    int i =10;
    while(i != 10)
    {
        cout<<i--<<" ";
        cout<<"THE MESSAGE IS:"<<"You wish!";
        cout<<"square of "<<j<<" = "<<(j*j);
    }
}
// afew thigs in the translation has beet skipped 
*/