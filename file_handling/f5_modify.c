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
    fp = fopen("f5.txt", "r+");

    printf("\nall records  \n");

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s -> %d -> %s\n",SH.real_name,SH.movies,SH.name );  
    }    
    fclose(fp);

    fp = fopen("f5.txt", "r+");
    printf("\nupdating the file\n");
    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf( "pointer position: %ld\n",ftell(fp) );
        if(SH.movies == 0)
        {
            printf("%s\n",SH.name);
            fseek(fp , -(sizeof(SH.name) + sizeof(SH.movies) + sizeof(SH.real_name)), 1 );
            printf( "changed pointer position: %ld\n",ftell(fp) );
            printf( "changed pointer position: %ld\n",ftell(fp) );
            
        }
    }    
    fclose(fp);

    return 0;
} 