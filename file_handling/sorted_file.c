#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

struct marvel
{
    char name[20];
    int movies;
    char real_name[20];
};

int main()
{  
    struct marvel store[10];
    struct marvel SH;
    int index = 0;
    FILE *fp;
    fp = fopen("f5.txt", "r"); 

    printf("\n file read: \n");

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s, %d, %s\n",SH.real_name,SH.movies,SH.name );
        strcpy(store[index].name , SH.name);
        store[index].movies = SH.movies;
        strcpy(store[index++].real_name , SH.real_name);
    }     
    fclose(fp);

    int i,j,temp;
    // bubble sort algorithm
    for(i=0; i<index-1; i++)
    {
        for(j=i; j<index; j++)
        {
            if( store[j].movies < store[i].movies)  // ascending order
            {
                temp = store[i].movies;
                store[i].movies = store[j].movies;
                store[j].movies = temp;
            }
        }
    }

    printf("\nsorted according to their movies: \n\n");
    for(i=0; i<index; i++)
    {
        printf("%s -> ",store[i].name);
        printf("%d -> ",store[i].movies);
        printf("%s\n",store[i].real_name);
    }

    fp = fopen("f5.txt", "w"); 
    fwrite( store, sizeof(SH) , index , fp);
    fclose(fp);

    printf("\n\ncontents of the file\n\n");
    fp = fopen("f5.txt", "r");
    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s, %d, %s\n",SH.real_name,SH.movies,SH.name );
        strcpy(store[index].name , SH.name);
        store[index].movies = SH.movies;
        strcpy(store[index++].real_name , SH.real_name);
    }
    fclose(fp);

    return 0;
} 