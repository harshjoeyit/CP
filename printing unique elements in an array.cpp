#include<bits/stdc++.h>
using namespace std;

int I;

void bubble_sort(int a[],int size)
{
    int temp;

    for(int i=0; i<size-1; i++)
    {
        for(int j=i; j<size; j++)
        {
            if(a[i]>a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int binary_search( int *a ,int size ,int search)
{
    int low = 0,high = size-1,mid;

    while(low<=high)
    {
        mid = (low+high)/2;

        if(a[mid] == search )
        {
            I = mid;
            return 1;
        }
        else
        if(search < a[mid] )
            high = mid - 1;
        else
            low = low + 1;
    }
    return 0;
}

int main()
{

    int a[] = {1,2,3,3,8,5,2,2,0,0,4,4,6,6,3,3,8,7};
    int size = sizeof(a)/sizeof(int);
    int b[size] ,temp, index = 0, count;

    bubble_sort(a,size);

    for(int i=0; i<size;  i++)
        cout<<a[i]<<" ";
    cout<<endl;

    for(int i=0; i<size; i++)
    {
        if(a[i] != 0)
        {
            count = 1;
            temp = a[i];
            a[i] = 0;  // `making the curent element zero so that it does not include in the binary search 

            while( binary_search(a,size,temp) )  // counting all the elements in the that are equal to a[i]
            {
                a[I] = 0;  // making them zero so that they do not get included in the next binary search
                ++count;   
            }

            if(count == 1)   // if the number does not appear again in the array then copying it in the seperate array (unique)
                b[index++] = temp;
        }
    }
    
    for(int i=0; i<index;  i++)
        cout<<b[i]<<" ";
    cout<<endl;
 
}