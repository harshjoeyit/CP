#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,i;
    printf("enter array size: ");
    scanf("%d",&n);

    int *ptr = (int*)malloc(n*sizeof(int));

    if(ptr = NULL)
        exit(1);

    //Note also that exit takes an integer argument, so you can't call it like exit(), you have to call as exit(0) or exit(42). 0 usually means your program completed successfully, and nonzero values are used as error codes.
    //There are also predefined macros EXIT_SUCCESS and EXIT_FAILURE, e.g. exit(EXIT_SUCCESS);

    printf("pointer at: %d\n",ptr);

    printf("enter array:\n");
    for(i=0; i<n; i++)
        scanf("%d",ptr+i );

    for(i=0; i<n; i++)
        ptr[i]*= 2;

    for(i=0; i<n; i++)
        printf("value: %d at add = %d\n",ptr[i],ptr+i);

    float *p = (float*)calloc( n,sizeof(float) );

    if(p == NULL)
        exit(1);
    // non zero value returned signiies error 
    // 0 signifies success 
    // if NULL then skips rest of the code 

    printf("\nenter array:\n");
    for(i=0; i<n; i++)
        scanf("%f", p+i );

    for(i=0; i<n; i++)
        p[i]*= 3;

    for(i=0; i<n; i++)
        printf("%f,",p[i]);

    printf(" \nenter number of elements to be added: ");
    int m,j;
    scanf("%d",&m);

    ptr = (int*)realloc(ptr,(n+m)*sizeof(int) );  // reallocating the memory

    printf("\npointer at : %d\n",pnew);

    printf("\nenter new elements: \n");
    for(j=i; j<n+m; j++)
        scanf("%d",pnew+j);

    for(i=0; i<n+m; i++)
        printf("value: %d at add = %d\n",pnew[i],pnew + i);

// entering a string an printing it later on
    char *ptri = (char*)malloc(100*sizeof(char));
    int ii,nn;

    printf("n:");
    scanf("%d",&nn);
    printf("enter: ");

    for(ii=0; ii<nn-1; ii++)
        scanf("%c",ptr+ii);
    *(ptr+ii) = '\0';

    printf("output:");

    printf("%s",ptri);

    free(ptr);
    free(pnew);
    free(p);



    return 0;
    
}