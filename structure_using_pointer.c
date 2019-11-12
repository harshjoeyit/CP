#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student 
{
    char name[10];
    int r;
};

int main()
{    
    student S;
    printf("%d\n%d",&S.name,&S.r);
    printf("\nsizeof(struct)= %d\n",sizeof(S));

    int n;
    printf("N:");
    scanf("%d",&n);
    student *ptr = (student *)calloc( n , sizeof(S) );

    char N[10];
    int R,i;

    for(i=0; i<n; i++)
    {
        printf("name: ");
        scanf("%s",N);
        strcpy((ptr+i)->name , N);

        printf("r: ");
        scanf("%d",&R);
        (ptr+i)->r = R;
    }

    printf("out: \n");
    
    for(i=0; i<n; i++)
    {
        printf("%d. ",i+1);
        printf("name is : %s\n",(ptr+i)->name);
        printf("r: %d\n",(ptr+i)->r);
    
    }

}