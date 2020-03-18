#include<iostream>
#include<cmath>
using namespace std;

void sortit(long long (&a)[100000] ,long long sz)
{
    int t;
    for(long long i=0; i<sz-1; i++)
    {
        // swap ==0;
        for(long long j=0; j<sz-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                // swap =1;
            }
        }
        for(long long i=0; i<sz; i++) // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
          // if(swap==0) // this means array is sorted and no value has swapped in the last pass
            // break;
    }

}

int main()
{
    long long S,A[100000],i=0;
    cout<<"enter the size of the array: ";
    cin>>S;

    while(S--)
    {
        long long N;
        cin>>N;
        A[i++]=N;
    }

     // bubble sort


    return 0;
}
