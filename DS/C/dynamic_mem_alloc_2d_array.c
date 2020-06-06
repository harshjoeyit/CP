#include<stdio.h> 
#include<stdlib.h>

  // 2 -D matrix using dynamic allocation 
  // using pointer to an array 
 main ( ) 
 {
      int i,j,rows;
       int (*a)[4];
       printf("Enter number of rows ") ;
        scanf ("%d", &rows) ;
         a = (int (*) [4] )malloc(rows*4*sizeof(int)) ; // allocating memory fro rows * col 
         for(i=0; i<rows; ++i) 
         for(j=0; j<4; j++) 
         { 
             printf("Enter a[%d][%d]: ",i,j) ;
             scanf ("%d", (a+i)[j] );  
             
         }
             printf ("The matrix is : \n");
              for(i=0; i<rows; i++) 
              { 
                  for(j=0; j<4; j++) 
                  printf ("%5d", a[i][j]);
                  printf ("\n"); 
                } 
free(a);
}
