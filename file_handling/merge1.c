#include <stdio.h> 
#include<stdio.h>

struct league
{
    int level;
    int jersey;
};

int main()
{  
    struct league nba;
    FILE *fp;
    fp = fopen("merge1.txt", "w");//opening file 
    
    int n;
    printf("n:");
    scanf("%d",&n);

    while(n--)
    {
        printf("level :");
        scanf("%d",&nba.level);
        printf("jersey:");
        scanf("%d",&nba.jersey);

        fprintf(fp,"%d %d \n",nba.level,nba.jersey);
    } 
   fclose(fp);//closing file

   // reading the file

    fp = fopen("merge1.txt", "r"); 
    printf("\n file read: \n");

    while(fscanf(fp,"%d %d",&nba.level,&nba.jersey) != EOF)
    {
        printf("%d -> %d\n",nba.level,nba.jersey);
    }  
    fclose(fp);

    return 0;
} 