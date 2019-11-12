#include<stdio.h>
#include<stdlib.h>

struct student
{
    char name[20];
    int age;
};

int main()
{
    struct student S;
    int n,i;
    FILE *fptr;
    fptr = fopen("f4.dat","w");

    if(fptr = NULL)
    {
        printf("couldn't open file \n");
        exit(1);
    } 
    else
    {
        printf("no. of records:");
        scanf("%d",&n);
        
        for(i =0; i<n; i++)
        {
            printf("enter your name and age: \n");
            scanf("%s%d",&S.name,&S.age);
            fprintf(fptr,"%s%d",S.name,S.age);
        }
        fclose(fptr);
    }
    return 0;
}