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
    FILE *fptr;
    fptr = fopen("f4.dat","r");
    printf("NAME\tMARKS\n");

    while( fscanf(fptr , "%s%d",S.name, &S.age) != EOF )
        printf("%s\t%d",S.name,S.age);
    fclose(fptr);

    return 0;
}