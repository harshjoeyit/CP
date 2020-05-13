//10. Write a program in C to take a matrix in function named ‘func()’, then return entire matrix in
//‘main()’ and in main() find & display the sum of all matrix element.

#include<stdio.h> 
#include<stdlib.h>

int ** array(int rows, int cols)
{
    int i,j;
        int **a =(int **) malloc (rows* sizeof(int*));

        for(i=0; i<cols; i++)
            a[i] = (int * )malloc(cols*sizeof(int));

         for(i=0; i<rows; i++) 
         for(j=0; j<cols; j++) 
         { 
             printf("Enter a[%d][%d]: ",i,j) ;
             scanf ("%d", &a[i][j] );  
             
         }
         return a;
}


 main ( ) 
 {
      int i,j,cols,rows;
       printf("Enter number of rows ,cols") ;
        scanf ("%d%d", &rows,&cols) ;

        int **p = array(rows,cols);

         printf ("The matrix is : \n");
          for(i=0; i<rows; i++) 
          { 
             for(j=0; j<cols; j++) 
              printf ("%5d", p[i][j]);   
              printf ("\n"); 
         }


}
