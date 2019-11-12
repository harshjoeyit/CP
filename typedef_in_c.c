#include <stdio.h>
#include <string.h>

#define cp char*  // to illustrate the diff between #define and typedef
typedef char* cptr;


typedef int INT;
typedef const int CINT;
typedef int array[10];
typedef int* I_PTR;

typedef struct  // struct name can only be omitted if the structure is not self referential 
{   //Here new name is same as that of tagname. Here we can't omit the tagname since 
    //we have to definl a pointer to the same structure inside the structure.
    int age; 
    char grade;
}person;

person student={.age=20,.grade='a'},worker={56,'c'};

int main()
{
    array A = {1,2,3,4,5};
    INT x = 10;
    CINT y = 9;
    INT i;
    I_PTR pointer;
    pointer = A;

    cp p1,p2,p3;  //  only p1 is pointer tot the char p2 and p3 are char since #define rerplaces only the test 
    cptr ptr1,ptr2,ptr3; // all are pointers to the char , it is type alias for a data type 

    printf("%d,%d,%d\n",x,y);

    for(i=0; i<10; i++)
        printf("%5d",A[i]);
    printf("\nsizeof(A = %d",sizeof(A));
    printf("\n%d",*pointer);

    printf("\nstruct:print %d,%c",student.age,student.grade);
    
    printf("\nstruct:print %d,%c",worker.age,worker.grade);

    printf("\ndifference b/w the typedef and #define\n%u,%u,%u",sizeof(p1),sizeof(p2),sizeof(p3));
    printf("\n%u,%u,%u",sizeof(ptr1),sizeof(ptr2),sizeof(ptr3));

    return 0;
}
