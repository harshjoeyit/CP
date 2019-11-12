#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fptr;
    fptr = fopen("f2.txt","w");

    int n,temp=0 ;
    printf("no of elements: n:");
    scanf("%d",&n);

    for(int i=0; i <n; i++)
    {
        printf("element: ");
        scanf("%d",&temp);
        putw(temp,fptr);
    }
    fclose(fptr);

    return 0;
}