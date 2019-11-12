#include<stdio.h>

int main()
{   
    FILE *fptr;
    char str[120];
    fptr = fopen("f3.txt","r");
    while(fgets(str,20,fptr) != NULL ) // reads 19 characters only last is null
        puts(str); // convers null charcter to a new line .
    fclose(fptr);

    return 0;
}