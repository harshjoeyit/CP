//10. Write a program in C to take a matrix in function named ‘func()’, then return entire matrix in
//‘main()’ and in main() find & display the sum of all matrix element.
#include<stdio.h> 
#include<stdlib.h>

  // 2 -D matrix using dynamic allocation 
  // using pointer to an array 
  // cols variable
 main ( ) 
 {
      int i,j,cols;
       int *a[3];
       printf("Enter number of rows ") ;
        scanf ("%d", &cols) ;
         a[0] = (int * )malloc(cols*sizeof(int)) ; // allocating memory fro rows * col 
         a[1] = (int * )malloc(cols*sizeof(int)) ; // allocating memory fro rows * col 
         a[2] = (int * )malloc(cols*sizeof(int)) ; // allocating memory fro rows * col 

         for(i=0; i<3; ++i) 
         for(j=0; j<cols; j++) 
         { 
             printf("Enter a[%d][%d]: ",i,j) ;
             scanf ("%d", &a[i][j] );  
             
         }
             printf ("The matrix is : \n");
              for(i=0; i<3; i++) 
              { 
                  for(j=0; j<cols; j++) 
                  printf ("%5d", a[i][j]);
                  printf ("\n"); 
                } 
free(a[0]);
free(a[1]);
free(a[2]);
}
