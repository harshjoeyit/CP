#include <stdio.h>  
int main()
{  
    FILE *fp;
    fp = fopen("file.txt", "w");//opening file 

    char name[255];
    int n,age;
    printf("n:");
    scanf("%d",&n);
    while(n--)
    {
        printf("enter the name :");
        scanf("%s",name);
        printf("enter the age :");
        scanf("%d",&age);
        fprintf(fp,"%s %d\n",name,age);//writing data into file // space %s and%d is must
    } 
   fclose(fp);//closing file

   // reading the file

    fp = fopen("file.txt", "r"); 
    printf("\n file read: \n");

    while(fscanf(fp, "%s%d",name,&age)!=EOF)
        printf("%s is %d years old\n",name,age );      
    fclose(fp);

    return 0;
} 