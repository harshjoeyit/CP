#include<stdio.h>

int main()
{
    int a[] = {1,2,3,4,5,6,7,8};\
    int size = sizeof(a)/sizeof(int);
    int index , b[size] ,i = 0 , j=0;
    printf("reverse from index: ");
    scanf("%d",&index);
    
    i = index;
    do
    {
        b[j++] = a[i]; 
        i = (i + 1)%size;
    } while( i != index );

    for( j =0; j<size; j++ )
        printf("%d ",b[j]);
    
}
