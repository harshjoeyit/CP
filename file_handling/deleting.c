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


    printf("\n file contents: \n");

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s, %d, %s\n",SH.real_name,SH.movies,SH.name );
    }    
    fclose(fp);

    fp = fopen("f5.txt", "r");//opening file 
    ftemp = fopen("temp_file.txt","w+"); // opening the temp file for writing 

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        if(SH.movies != 0)
        {
            fprintf(ftemp, "%s %d %s\n",SH.name,SH.movies,SH.real_name);//everything except the removable data is written into the temp file
        }
    }    
    fclose(ftemp);
    fclose(fp);

    // temp file has same data we want
    // we dont need previous file
    //so we can

    remove("f5.c") ; 
    rename("temp_file.txt", "f5.txt");

    return 0;
} //fprintf(fp,"%s %d %s\n",SH.name,SH.movies,SH.real_name);//writing data into file // space %s and%d is must