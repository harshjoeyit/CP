#include <stdio.h> 

struct marvel
{
    char name[20];
    int movies;
    char real_name[20];
};

int main()
{  
    struct marvel SH;
    FILE *fp;
    fp = fopen("f5.txt", "a");//opening file 
    
    int n;
    printf("n:");
    scanf("%d",&n);

    while(n--)
    {
        printf("superhero :");
        scanf("%s",&SH.name);
        printf("no_movies:");
        scanf("%d",&SH.movies);
        printf("real_name:");
        scanf("%s",&SH.real_name);
        fprintf(fp,"%s %d %s\n",SH.name,SH.movies,SH.real_name);//writing data into file // space %s and%d is must
    } 
   fclose(fp);//closing file

   // reading the file

    fp = fopen("f5.txt", "r"); 
    printf("\n file read: \n");

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
        printf("%s, %d, %s\n",SH.real_name,SH.movies,SH.name );      
    fclose(fp);

    return 0;
} 