#include<stdio.h>
#include<stdlib.h>
//using the function fgetc
int main()
{
    FILE *fptr;
    int ch;
    fptr = fopen("f1.dat","r");
    if(fptr == NULL)
    {
        printf("the file doesn't exist\n");
        exit(1);
    }
    else
    {
        while( (ch = fgetc(fptr)) != EOF)
            putchar(ch); // or a simple printf statement 
    }
    fclose(fptr);

    return 0;
}