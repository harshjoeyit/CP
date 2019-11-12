#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,value;
    FILE *fptr;

    fptr = fopen("text1.txt","r");
    if(fptr == NULL)
    {
        printf("could not open file\n");
        exit(1);
    }
    printf("\narray output: \n");

    while( (value = getw(fptr)) != EOF)  // cannot read beyond -1 becase that is the value of EOF
        printf("%d,",value);
    fclose(fptr);
    
    char str[80];
    printf("\nstring output: \n");
    fptr = fopen("text1.txt","r");
    printf("\nstring: \n");
    while(fgets(str,80,fptr) != NULL)
        puts(str);
    fclose(fptr);




    return 0;
}