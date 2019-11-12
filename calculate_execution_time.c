#include<stdio.h>
#include<stdio.h>
#include<time.h>

int binary_search(int a[], int low, int high, int search)
{
    int mid;
    while(low <= high)
    {
        mid = (low + high)/2;

        if(a[mid] == search)
            return 1;
        else
        if( a[mid] > search )
            high = mid - 1;
        else
            low = mid + 1;
    }
    return 0;
}

int main()
{ 
    clock_t start,end;
    double cpu_time_used;

    start = clock(); 

    int t=20,search;
    int a[]={0,1,2,3,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

    while(t--)
    {
        search = binary_search(a,0,20,t+17);
        printf("%d\n",search);
    }

    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;

    printf("total time used : %lf",cpu_time_used);

    return 0;

}
