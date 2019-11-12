#include<stdio.h>
#include<stdlib.h>

int main()
{
    int value;
    FILE  *fptr;
    fptr = fopen("f2.txt","r");

    while( (value = getw(fptr)) != EOF)  // reads until EOF or -1 not appers in the file in the data 
    {
        printf("value: %d\n",value);
    }
    fclose(fptr);

    return 0;
}