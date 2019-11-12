// to find the sum of the mod of subtraction of adjacent terms of an even terms array is max
// (a[0] -a[1]) + (a[2] -a[3]) + .......................  array inputted may not be sorted;
#include<iostream>
#include<cmath>
using namespace std;

// bubble sort:
void sortit(int (&a)[100000], int sz)
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
        for(int i=0; i<sz; i++) // breaking loop if already sorted no more passes required
        {
            if(a[i]>a[i+1])
                break;
        }
          // if(swap==0) // this means array is sorted and no value has swapped in the last pass
            // break;
    }
}

void mysort(int (&a)[100000], int sz)
{
    // two arbitrary arrays.
    int a1[50000], a2[50000],e=0,m=sz/2;
    for(int k=0,x1=0; k<m; k++,x1++)
    {
        a1[x1]=a[k];  // array with half of the sorted values relatively greater
        a2[x1]=a[k+sz/2]; // array with another half of values  relatively smaller

    }
    // my sort
    for(int k=0; k<sz; k++)
    {
        if(k%2 == 0)
            a[k]=a1[e++];
        else
        {
            a[k]=a2[m-1];
            m--;
        }
    }

}
// max sum

void maxsum(int (&a)[100000], int sz)
{
    long long sum=0;
    for(int i=0; i<=(sz-2); i=i+2)  // increment of two;
    {
        sum=sum+ (a[i]-a[i+1]);
    }
    cout<<sum;
}

int main()
{
    int A[100000],S,x=0;
    cout<<"even size: ";
    cin>>S;
    cout<<"enter "<<S<<" terms: "<<endl;
    for(int x=0; x<S; x++)
    {
        int N;
        cin>>N;
        A[x]=N;
    }

    // original print
    cout<<"original"<<endl;
    for(int j=0; j<S; j++)
    {
        cout<<A[j]<<" ";
    }
    cout<<endl;

    // sorted print
    cout<<"sorted"<<endl;
    sortit(A,S);

    for(int j=0; j<S; j++)
    {
        cout<<A[j]<<" ";
    }
    cout<<endl;

    // my sort
    cout<<"mysort"<<endl;
    mysort(A,S);

    for(int j=0; j<S; j++)
    {
        cout<<A[j]<<" ";
    }
    cout<<endl<<"max sum:";

    // max sum
    maxsum(A,S);

    return 0;
}
