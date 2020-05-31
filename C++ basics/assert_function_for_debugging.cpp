#include<bits/stdc++.h>
using namespace std;

#define lower_limit  0  // we could have simply declared them in tegers in the main() but  when assetion falins the assertion fails 
#define upper_limit 20 // the error mesage shows the variable name niot the actul valuues 
                           // # define replaces it with actual values 

int test_fun(int x,int y)
{
    // preconditon
    assert( x>=lower_limit && x<=upper_limit ); // terminates program if condition is not met giving an error message

      int z= x+y;
    // postcondition
    assert(z < 30) ;

    return z;
}

int main()
{
    // assert function is mainly used when the input from the user needs to be constrained (it has a sort of a limit )
    // it does no  nothing if the input is within the limits but
    // teeminates the program if the limit is crossed
    // if NDEBUG is defined before the addition of the header files then all the assert calls will be ignored at the run time and the user will simply not recieve the erroe messege
    // it is simply like removing the alll the assert codes form the  program
    // there is slight performance improve if the NDEBUG macro is used at the top of the code  

    int x,y;
    cin>>x>>y;    

    cout<<test_fun(x,y)<<"\n success: ";

    return 0;
}