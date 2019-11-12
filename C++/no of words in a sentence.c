#include<stdio.h>
#include<string.h>


int main()
{
    char *s = " ",a[50];
    gets(a);
    int words = 0 , c = 1,i;
    for(i=0; i<strlen(a); i++)
    {
        if( a[i] == '\0')
            break;
        else
        if( a[i] != ' ' && c == 1)
        {
            ++words;
             c = 0;
        }
        else
        if( a[i] == ' ')
            c = 1;
    }
    printf("%d",words);
}
