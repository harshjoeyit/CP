#include<stdio.h>
#include<stdlib.h>

// to printt the even numbers in front an dodd numbers in the end without changing the actual order 

int main()
{
    int n,index=0,index3=0,i;
    printf("N:");
    scanf("%d",&n);
    int index2=n-1;

    int *ptr = (int*)calloc(n,sizeof(int));
    int *ptr2 = (int*)calloc(n,sizeof(int));

    for(i=0; i<n; i++)
        scanf("%d",ptr+i);

    for(i=0; i<n; i++)
    {
        if(ptr[i] % 2 == 0)  // checking the even from the start
            ptr2[index++] = ptr[i];
        if(ptr[index2-i] % 2 == 1)  // checking odd from the end
            ptr2[index2-index3++] = ptr[index2-i];
    }

    printf("\narray\n");
    for(i=0; i<n; i++)
        printf("%d",ptr2[i]);

    return 0;
}