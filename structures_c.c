#include<stdio.h>
#include<string.h>
  
  
  // find the solution to the problem of the size of structure 
  // if only char c -- size =1;
  // if intx , xhar c, float f - size = 12



struct student
{
    int rollno;
    char name[20];
    float CPI;
}s1;  // this object is a global object

struct address 
{ 
   char name[50]; 
   int pin; 
};


void print()
{
    printf("%d\n",s1.rollno);
    printf("%s\n",s1.name);
    printf("%f\n",s1.CPI);
}

int main()
{
    struct address add = {}; // uniintialized gives blank string 0 to int variable 
    struct student s[3];
    struct student *struct_ptr;

    int i;
    for(i=0; i<3; i++)
    {
        printf("Roll No:");
        scanf("%d",&s[i].rollno);
        printf("Name:");
        scanf("%s",&s[i].name);
        printf("CPI:");
        scanf("%f",&s[i].CPI);
    }

    for(int i=0; i<3; i++)
    {
        if(s[i].CPI > 9.2)
        {
            struct_ptr = &s[i]; 

            printf("rollno: %d,",struct_ptr -> rollno);
            printf("name: %s,",struct_ptr -> name);
            printf("CPI: \n%f",struct_ptr -> CPI);
        }
    }

    s1.rollno = 5641;
    strcpy(s1.name , "yo_yo");
    s1.CPI = 9.5;  

    return 0;
}