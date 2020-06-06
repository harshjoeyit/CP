#include<stdio.h>

int main()
{
  int a[]= {0,1,0,1,0,1,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},i=0;
  int size = sizeof(a)/sizeof(int);
  int index=0, back_index = size-1 ;
  int b[size];

  for(i =0; i<size; i++)
  {
    if(a[i]==0)
      b[index++]=0;
    else
      b[back_index--]=1;
  }

  for(int i=0; i<size; i++)
    printf("%3d",b[i]);

}