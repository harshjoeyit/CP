#include<stdio.h>

int main()
{
    int i,j,count,c=0;

    for(i=1; i<=5; i++)
    {
        c=c+i;
        count=0;

        for(j=c; count != i ; j--)
        {
            printf("%d",j);
            ++count;
        }
        printf("\n");
    }

    return 0;
}
