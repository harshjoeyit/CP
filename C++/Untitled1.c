 #include<stdio.h>

 struct student
 {
int rollno;
char name ;
float marks;
}stu;

 main ( )
 { printf("Address of name = %u \n" , &stu. name) ;
 printf("Address of rollno = %u\n",&stu.rollno);
 printf("Address of marks = %u\n" ,&stu.marks);
 printf("sizeof stu: %d\n",sizeof(stu));
 print("size:%d\n",sizeof(stu.rollno) + sizeof(stu.marks) + sizeof(stu.name));
 }
