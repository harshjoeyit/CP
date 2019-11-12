#include <stdio.h> 
#include<stdio.h>

struct league
{
    int level;
    int jersey;
};

int main()
{  
    struct league nba1 , nba2;
    FILE *fp,*fp1,*fp2;
    int i,j;

    fp1 = fopen("merge1.txt", "r");//opening file 
    fp2 = fopen("merge2.txt", "r");//opening file 
    fp = fopen("merge.txt", "w");//opening file 

    i = fread(&nba1,sizeof(nba1),1,fp1);
    j = fread(&nba2,sizeof(nba2),1,fp2);

    while( (i==1) && (j==1) )
    {
        if( nba1.jersey > nba2.jersey )
        {
            fwrite(&nba1 , sizeof(nba1), 1, fp);
            i = fread(&nba1,sizeof(nba1),1,fp1);
        }
        else
        {
            fwrite(&nba2 , sizeof(nba2), 1, fp);
            j = fread(&nba2,sizeof(nba2),1,fp2);   
        }
    }

    while( i==1 )
    {
        fwrite(&nba1 , sizeof(nba1), 1, fp);
        i = fread(&nba1,sizeof(nba1),1,fp1);
    }

    while(j==1)
    {
        fwrite(&nba2 , sizeof(nba2), 1, fp);
        j = fread(&nba2,sizeof(nba2),1,fp2); 
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);

    fp = fopen("merge.txt", "r"); 
    printf("\n file read: \n");

    while(fscanf(fp,"%d %d",&nba1.level,&nba1.jersey) != EOF)
    {
        printf("%d -> %d\n",nba1.level,nba1.jersey);
    }  
    fclose(fp);
}