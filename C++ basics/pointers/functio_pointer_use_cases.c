// all the function use cases are based on the concept that function pointer can be passed as an argument to another function 
// function pointers and callbacks 

#include<bits/stdc++.h>
using namespace std;

int acompare(int a,int b)
{
    // compare is callback function 
    // it compares the arguement and 
    // returns 1 if 1st elememt has higher rank
    // else returns -1
    // if we change ranking mechanism then this function would sort in dcreasing order 

    if( a> b) return 1;  // or we could just return a-b
    else return -1;

}

int dcompare(int a,int b)
{
    if( b>a) return 1; // or we could just return a-b
    else return -1;

}

void bubble_sort(int A[],int n,int (*compare)(int ,int) )
{
    int i,j,temp;

    for(i=0; i<n; i++)
        for(j=0; j<n-1; j++)
        {
            if( (*compare)(A[j],A[j+1]) > 0 )
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
}

int main()
{
    int i,A[]={3,2,1,5,6,4};
    
    bubble_sort(A,6,acompare);  // passing the function pointer 
                                // compare function decides ascending or descending 
    for(i=0; i<6; i++)
        printf("%d,",A[i]);
    
    bubble_sort(A,6,dcompare);  // descending
                                // this saves alot of duplicate code
    printf("\n");
     for(i=0; i<6; i++)
        printf("%d,",A[i]);

        // the array is sorted in increasing order 
        // if we want to arrange in decreasing order
        // could write one more sort function // duplicate code
        // or we could pass one more parameter telling function to arrange inascend or descen
        //we could also use function pointers


}