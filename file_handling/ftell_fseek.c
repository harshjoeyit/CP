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
    fp = fopen("f5.txt", "r+");//opening file

    printf("reading the file\n skipping 3 records");

    printf("current position of the pointer is : %ld\n",ftell(fp));
   // fseek(fp,(2)*sizeof(SH),0);

    while(fscanf(fp, "%s %d %s",&SH.name,&SH.movies,&SH.real_name) != EOF)
    {
        printf("%s has played %d movies as %s\n",SH.real_name,SH.movies,SH.name );      
        printf("current position of the pointer is : %ld\n",ftell(fp));
        // the positon printed is the next to the data filled
        //ftell returns th eaddress of the starting address of the record 
        // each record has takes different memory space asoording to the lenght of the name
        // the last ftellp tells the total address taken up by the total data in the file
   }
    
    fclose(fp);

    

    return 0;
} 