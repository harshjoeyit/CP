#include<stdio.h>

// two sorted arrays are given 
// they are megedaaa
// find median of final array

int main()
{
  int a[] = {0,1,5,8};
  int size1 = sizeof(a)/sizeof(int);
  int b[] = {3,4,6,7,7};
  int size2 = sizeof(b)/sizeof(int);

  int S = size1+size2;
  int c[S]={};
  int i3=0,i1=0,i2=0,i;

  while( (i1 < size1) && (i2 < size2) )
  {
    if(a[i1] < b[i2])
     {
        c[i3++] = a[i1++];
     }
    else
    {
        c[i3++] = b[i2++];
    }
  }

  for(i=0; i<(S); i++)
    printf("%3d",c[i]);
    
  if(i2<size2)
  {
    for(i=i2; i<size2; i++)
      c[i3++] = b[i];
  }
  if(i1<size1)
  {
      for(i=i1; i<size1; i++)
        c[i3++] = a[i];
  }

  printf("\n");
  for(i=0; i<(S); i++)
    printf("%3d",c[i]);

  int median;
  if (S%2 == 0)
    median = (c[S/2] + c[S/2-1])/2;
  else
    median = c[(S-1)/2];

  printf("\nmedian: %d\n",median);
}