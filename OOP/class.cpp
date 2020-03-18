#include<iostream>

    class student
    {
        int rollno;
        char sec;

       public:
        int a;
      void input()
      {
          std::cout<<"enter the roll. no. of the student: \n";
          std::cin>>rollno;
          std::cout<<"enter the the section \n";
          std::cin>>sec;
          std::cout<<"enter the value of a \n";
          std::cin>>a;
      }

      void output()
      {
          std::cout<<"the roll no. is : "<<rollno;
          std::cout<<"\n the section is :"<<sec;
          std::cout<<"\n "<<a;
      }

    };

     int main()
      {
        student x;
        x.input();
        x.output();
        std::cout<<x.a;

        return 0;
      }


