#include<stdio.h>
#include<stdlib.h>

int main()
{
    // itoa function converts integer to string
    // function syntax
    // atoi(int val,char *,int x)
    // x= 10 for decimal
    // x=16 for hex
    // x=8 for octal
    // x=2 for binary

    int i=14;
    char buf[20];
    // decimal
    itoa(i,buf,10);
    printf("%s",buf);
    // hex
    itoa(i,buf,16);
    printf("\n%s",buf);

    // octal
    itoa(i,buf,8);
    printf("\n%s",buf);

   // binary
    itoa(i,buf,2);
    printf("\n%s",buf);

    return 0;
}
