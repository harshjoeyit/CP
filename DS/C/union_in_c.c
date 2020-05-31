#include <stdio.h>
#include <string.h>

//. You can define a union with many members,
// but only one member can contain a value at any given time.
 //Unions provide an efficient way of using the same memory location for multiple-purpose.
union union_name 
{
    int a;
    char b;
    float c;
    char d;
}U2;

//When we declare a union,//
// memory allocated for a union variable of the type is equal to memory needed for the largest member of it,
// and all members share this same memory space

union test1 { 
    int x; 
    int y; 
} Test1; 
  
union test2 { 
    int x; 
    char y; 
} Test2; 
  
union test3 { 
    int arr[10]; 
    char y; 
} Test3; 

int main()
{
    union_name U1 = {};
    union_name *ptr =  &U1;

  U1.c=3.14;
    U1.b='b';
    U1.d='d';
    U1.a=2563;

    printf("for U1: \n");
    printf("int a = %d\n",ptr->a);
    printf("char b = %c\n",ptr->b);
    printf("float c = %f\n",ptr->c);
    printf("char d = %c\n",ptr->d);
// if avalue of structrure  e,lememnt then the other values change auto matically
        U1.a = 4561;

    printf("for U1: \n");
    printf("int a = %d\n",ptr->a);
    printf("char b = %c\n",ptr->b);
    printf("float c = %f\n",ptr->c);
    printf("char d = %c\n",ptr->d);

    printf("\nadd- at the pointer %u",ptr);
    printf("\nvlaue at the pointed union: %d",*ptr);
    printf("\nsized of the unions: \n");

    printf("test1= %u\n", sizeof(test1) );
    printf("test2= %u\n", sizeof(test2) );
    printf("test3= %u\n", sizeof(test3) );


    return 0;
}