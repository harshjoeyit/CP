// collection of strings
#include<stdio.h>
#include<string.h>

void swap(char *p,int len)
{
    int i;
    char temp;
    for(i=0; i<len/2; i++)
    {
      temp = p[i];
      p[i] = p[len-i-1];
      p[len-i-1] = temp;
    }
}

int main()
{
    char b[520] = "      how   is   the    josh  ?   ";
    char a[50][20];
    int i,j1=0,j2=0;

   for(i=0; i<strlen(b); i++)
   {
       if(b[i] != ' ')
       {
           a[j1][j2++] = b[i];
       }
       else
       if( b[i] == ' ' )
       {
           a[j1][j2++] = '\0';
           j1++;
           j2 = 0;
       }
   }

   for(i=0; i<=j1; i++)
   {
       printf("%s ",a[i]);
   }

   for(i=0; i<= j1; i++)
   {
       swap(a[i],strlen(a[i]));
   }

    printf("\n");
    for(i=0; i<=j1; i++)
   {
       printf("%s ",a[i]);
   }




}