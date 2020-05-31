#include<iostream>
using namespace std;

// individual prime check:   ...........................

bool isprime(int n)
{
    if(n==0 || n==1)
        return false;
    else                               //exclusively defining the conditions for 0,1,2 and 3
    if(n==2 ||n==3)
        return true;

    else
    if(n>3)             // for n>3 running loop till n/2
    {
        for(int i=2; i<=n/2; i++)
        {
            if(n%i==0)
                return false;
        }
        return 0;
    }

}

// check every element of the loop ,N, sum if it is prime...............

bool check(long long N,long long I, long long A[],long long sum)
{
    if(isprime(N))                         // 1. step checking the number itself
        if(isprime(sum))                     // if 1. is true   2.checking sum
            goto loop;                         // if 2. is true goto loop
        else
            return false;                  // if 2. is false
    else
        return false;                         // if 1. is false

    loop:
        for(long long J=0; J<=I; J++)        // loop for checking if the digits of the numbers are prime
        {
            if(isprime(A[J]))
            {
                continue;             // if prime loop forward
            }
            else
                return false;              // if not prime false
        }
        return true;                // at the end of loop is all are prime
}

// main........................................
int main()
{

        long long a[40],N;  // can take up to 40 digit numbers
        long long i=0;

// main while loop for every new number
    while(cin>>N)
    {
        const long long NN=N;  // needed ,since value is changed in the second statement of the loop
        while((N/10) != 0)
        {
            a[i]=N%10;      //storing the values of the   DIGITS   in the array
            N=N/10;      // changing the value of the N
            ++i;
        }
        a[i]=N;       // storing the the last digit ; outside the loop.


// calculation the sum of the digits:
        long long s=0;
        for(long long j=0; j<=i; j++)
        {
            s+=a[j];

        }

   // calling the check function.......

        if(check(NN,i,a,s))  // passing the number sum of digits and an array with digits as its elements
            cout<<"satisfied"<<endl;
        else
            cout<<"not satisfied"<<endl;

    }// end of while


return 0;
}
