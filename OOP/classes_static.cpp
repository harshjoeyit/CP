#include<bits/stdc++.h>
using namespace std;










//.. always declare the static variable outside the class , uninitialized static class members give an error 
// ld returned 1 status exit(0)


/*
class test
{
    .........
    static int member....
}

static may not be specified again during initialization

int test::member = initialization value
*/






class student
{
    private:
        string name;
        int grade;
        
    public: 
        student( string n , int g): name(n), grade(g) { 
        }

        void get()
        {
            cout<<name<<" "<<grade<<" "<<college<<endl;
        }
        void change(string s)
        {
            college = s;
        }
        static string college;

};






// literal class 
class open
{       
    public: 
    int ival;
    string s;
    float f;
    char ch;
};

class C
{
    int p;
    C *ptr;
    public:
        void point()
        {
            ptr = this;
        }
    void display()
    {
        cout<<ptr->p<<endl;
    }
};








class Account
{
    public:
        void calculate() 
        {
            amount += amount * Irate;
        }
        static double rate()
        { 
            return Irate; 
        }
        static void rate( double );

    private:
        string owner;
        double amount;
        static double Irate ;
        static double initRate();
        // constexpr variable may be definened inside the class
        static constexpr int period = 30;       // must inclass initializers for constexpr 
        static const int IFSCcode = 987456;
        double daily_tbl[period];           //  may be used to define an array size 
        static constexpr int vecsize = 20;
};

// define and initialize static data member 
double Account::Irate = initRate();

void Account::rate( double newRate )
{
    Irate = newRate;
}







// use of static 
class employee
{
    public:
        employee() = default;
        employee( string n ) : name(n) , id( ++empcount ) { }
        void print()
        {
            cout<<id<<" "<<name<<endl;
        }

    private:
        static int empcount; 
        int id;
        string name = "noname" ;
};

//.MMIP....................
// without the initialization outside the class there is an error 
int employee::empcount = 0;








int main()
{



    student s("ashish",10);
    s.change("MNNIT");
    s.get();
    s.college = "IITK";
    s.get();

    student s2("ramesh" ,20);
    s2.get();

    cout<<student::college<<endl;
    // static members can be accesed by the class itself
    



    open obj;
    obj = { 0 ,"anna" };
    cout<<obj.ival<<obj.s<<obj.ch<<obj.f<<endl;




    Account Ac1;
    C ob;
    ob.point();
    ob.display();


    
    employee e1("ramesh") , e2("suresh");
    e1.print();
    e2.print();
    
}

