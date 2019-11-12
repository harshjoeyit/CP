#include<stdio.h>
#include<string.h>

int stringCompare( char *a , char *b )
{
    int A = strlen(a);
    int B = strlen(b);

    for( int i = 0; (i<A)&&(i<B); i++ )
    {
        if( a[i] < b[i] )
            return 2;
        else if( a[i] > b[i] )
            return 1;
    } 
    return ( (A > B) ? 1 : 2 );
}


int main()
{
    char a[] = "hey";
    char b[] = "he";

    printf("%d",stringCompare(a,b) );
}