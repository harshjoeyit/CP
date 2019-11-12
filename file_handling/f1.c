#include<stdio.h>
#include<stdlib.h>
// using the function fputc
main()
{
    FILE *fptr;
    int ch;
    fptr = fopen("f1.dat","w");
    if(fptr == NULL)
    {
        printf("\nfile couldn't be opened\n");
        exit(1);
    }
    else
    {
        printf("enter the text: \n");
        while( (ch =  getchar()) != EOF)
            fputc(ch,fptr);
    }
    fclose(fptr);
}