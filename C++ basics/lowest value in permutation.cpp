#include<iostream>
#include<cmath>
using namespace std;

// since pow function is not working properly so using the function and while loop to calculate power of 10

long long multiten(int P)
{
    long long power=1;
    while(P--)
    {
        power=power*10;
    }
    return power;
}

// maximize and n=minimizing no.
permutate(int a[10],int sz)
{
    long long num=0,fac;
    for(int x=0; x<sz; x++)
    {
        int p=sz-1-x;
        fac=multiten(p);
        num = num + a[x]*fac;
    }
    cout<<"max permut:  "<<num;
}


void sortit(int (&a)[10],int sz)                    // while passing an array as a reference do not forget to define the size of the array
{
    int t;
    for(int i=0; i<sz-1; i++)
    {
        // swap ==0;
        for(int j=0; j<sz-i-1; j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                // swap =1;
            }
        }
        for(int i=0; i<sz; i++)                    // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
                                                   // if(swap==0) // this means array is sorted and no value has swapped in the last pass
                                                   // break;
    }

    permutate(a,sz);
}




int main()
{
    long long T;
    cout<<"enter the number of test cases: ";
    cin>>T;

while(T--)
{
    long long N;
    cout<<endl<<"enter the no.: ";
    cin>>N;
    int a[10],i=0;


    while((N/10) != 0)
    {
        a[i]=N%10;            //storing the values of the   DIGITS   in the array
        N=N/10;               // changing the value of the N
        ++i;
    }
    a[i]=N;                   // storing the the last digit ; outside the loop.
    ++i;                      // incrementing so that i becomes equal to size if the array

    sortit(a,i);              // sorted digit

}

return 0;
}// calculates max value possible after interchanging the digits as suits to give max value
