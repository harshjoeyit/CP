#include <stdio.h>
#include <string.h>

#pragma pack(1)  // avoids structure padding 
//i.e. leaving memory spaces in between to store data at multiples of 4 
struct student 
{
       int id1;
       char c;
       int id2;
       char a;
       float percentage;
       char b;
       
};
 
int main() 
{
    int i;
    struct student record1 = {1,'C', 2, 'A', 90.5, 'B'};
 
    printf("size of structure in bytes : %d\n", 
                           sizeof(record1));
 
    printf("\nAddress of id1        = %u", &record1.id1 );
    printf("\nAddress of c          = %u", &record1.c );
    printf("\nAddress of id2        = %u", &record1.id2 );
    printf("\nAddress of a          = %u", &record1.a );
    printf("\nAddress of percentage = %u",&record1.percentage);
    printf("\nAddress of b          = %u", &record1.b );
    
 
    return 0;
}