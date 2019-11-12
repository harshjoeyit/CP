#include<stdio.h>
#include<stdlib.h>

// storing the matrix {2-d array } in the file
int main()
{
    int a[5][3]={{1,2,3},{10,20,30},{100,200,300},{5,6,7},{15,35,65}},b[5][3]={},i,j;

    FILE *fptr;
    fptr = fopen("f6.txt","w");
    if(fptr == NULL)
    {
        printf("error: unopened");
        exit(1);
    }
    else
    {
        fwrite( a, sizeof(a), 1, fptr); // wrir=tes the contents of a
    }
    fclose(fptr);

    // reading from the file
    fptr = fopen("f6.txt","r");
    if(fptr == NULL)
    {
        printf("error: unopened");
        exit(1);
    }
    else
    {
        fread( b, sizeof(b), 1, fptr);  // reads and stores i b
    }
    fclose;

    for(i=0; i<5; i++)
        {
            for(j=0; j<3; j++)
                printf("%5d",b[i][j]);
            printf("\n");
        }        
    
}
