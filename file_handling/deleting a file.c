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
    FILE *fp,*ftemp;
    fp = fopen("f5.txt", "r");//opening file 
    ftemp = fopen("temp_file","w"); // opening the temp file for writing 


    printf("\n file read: \n");

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s, %d, %s\n",SH.real_name,SH.movies,SH.name );
    }      
    fclose(fp);

    return 0;
} 