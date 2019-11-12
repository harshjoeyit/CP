// FILE HANDLING
// stdio.h
// we can store the values we input in the program to perform a task permanently in the disk
// file and the input can be accesed and retrieved later when required
// fopen() - creates or opems the file in the disk
// FILE *fp - file pointer 
// fp = fopen( "file_name" ,"mode");
// mode 
// read- r
// write -w
// append - a
//fclose - closes a file
// flose(fp);
// getc() - reads one char ata at time
//char variable = getc(file_pointer)
// char ch = getc(fp)
// putc - writes one char at at a time 
// putc( char(could be a variable of literal)  ,  file_pointer)
// putc('a',fp);
// char c='a'    putc(c,fp)
// getchar() - one char input from user
// end of file in unix- ctrl+D, in DOS - ctrl + Z

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[20] ,i,value,n;
    printf("no of array elements n: ");
    scanf("%d",&n);

    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    FILE *fptr;
    fptr = fopen("text1.txt","w");

    if(fptr == NULL)
    {
        printf("could not open file\n");
        exit(1);
    }

    for(i=0; i<n; i++)
    {
        putw(a[i],fptr);
    }
    fclose(fptr);

    fptr = fopen("text1.txt","r");
    if(fptr == NULL)
    {
        printf("could not open file\n");
        exit(1);
    }
    printf("\narray output: \n");

    while( (value = getw(fptr)) != EOF)  // cannot read beyond -1 becase that is the value of EOF
        printf("%d,",value);
    fclose(fptr);


    char str[80];

    fptr = fopen("text1.txt","a");
    printf("\nenter text\n");
    while(gets(str) != NULL)
        fputs(str,fptr);
    fclose(fptr);

    printf("\nstring\n");0

    fptr = fopen("text1.txt","r");
    printf("\nstring: \n");
    while(fgets(str,80,fptr) != NULL)
        puts(str);
    fclose(fptr);



    return 0;
}