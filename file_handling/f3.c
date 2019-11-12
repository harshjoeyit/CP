#include<stdio.h>

int main()
{
    FILE *fptr;
    char str[100];
    fptr = fopen("f3.txt","w");
    printf("enter the text: \n");
    while( gets(str) != NULL )
        fputs(str,fptr);
    fclose(fptr);

}