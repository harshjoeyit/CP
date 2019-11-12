#include <stdio.h> 
#include<stdlib.h>

main()
{
    FILE *fptr;
    char ch;
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

    fptr = fopen("f1.dat","r");
    if(fptr == NULL)
    {
        printf("the file doesn't exist\n");
        exit(1);
    }
    else
    {
        printf("\npositon of fptr wrt start: %ld\n",ftell(fptr));
        while( (ch = fgetc(fptr)) != EOF)
        {
            fseek(fptr,sizeof(char),1); // skipping every alternate elements 
            putchar(ch); // or a simple printf statement 
        }
        printf("positon of fptr wrt start: %ld",ftell(fptr));
    }
    fclose(fptr);
}