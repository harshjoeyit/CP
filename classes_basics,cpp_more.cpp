#include<bits/stdc++.h> 
using namespace std;

// function prototypes 
void print( ostream& , struct sales_data&);
void print( ostream& , struct employee& );

struct employee
{
    string name;
    int emp_no;
    char grade;
    
    employee()          //  no pramemters , default constructor 
    {                   // in absence of any constructor , the compiler generates a constructor , called synthesized default constructor 
        emp_no = 0;     
        grade = 'N';
        name = "no_name";
    }   

    // NOTE: compiler only generates the constructor when there is none , explicitly defined  
    employee( int en , char g , string n )          // pramemters , parametrized constructor 
    {                   
        emp_no = en;     
        grade = g;
        name = n;
    }   
    // if a parametrized constructor is defined , then 
    // we also need to define a default constructor (i.e. without any arguments)
    //, for the objects declared without any arguments
};


struct student
{
    int roll = 0;       // in class initializers
    char name[20] = "Student_name";
}Stu;
// global objects are initialized to zero for in int values and empty for stringd 
// , even if there is no in class initializer present

    

// sales_data class 
struct sales_data
{
    string book_no ;
    unsigned int units_sold = 0;
    double revenue = 0.0;

    // constructors added , they don't have a return type 
    sales_data() = default;     //1 
    sales_data( const string &s ) : book_no(s) {/*empty function body */ }    //2
    // values of the data members are iniitalized using iniitalizer list 
    sales_data( const string &s , unsigned int n , double price ) : book_no(s) , units_sold(n) , revenue(price*n) {/*empty function body */}     //
        // note: double price is not a member of class , just an additional parameter to find the revenue
        // there is no restriction on the parameters of the constructor
    sales_data( istream &input );   //4
    // prototype is necessary, body may appear later
};




/*general syntax of a function declaration outside the class 
return_type class_name:: function_name( parameters ) { body }   */
sales_data::sales_data(istream &input )   //4
{
    int price;
    cout<<"input - book_no , units_sold , price : \n";
    input>>this->book_no;
    input>>this->units_sold;
    input>>price;
    this->revenue = this->units_sold*price;
    print( cout , *this ); 
}


void print( ostream &output , struct sales_data &obj )
{
    output<<"book_no: "<<obj.book_no<<endl;
    output<<"units_sold: "<<obj.units_sold<<endl;
    output<<"revenue: "<<obj.revenue<<endl<<endl;
}



void print( ostream &output , struct employee &Emp )
{
    output<<Emp.name<<endl;
    output<<"emp_no: "<<Emp.emp_no<<endl;
    output<<"grade: "<<Emp.grade<<endl<<endl;
}



int main()
{
    struct employee Ramesh( 124 , 'B' , "Ramesh");
    print( cout , Ramesh );
    struct employee Suresh;
    print( cout , Suresh );

    struct student S;
    cout<<S.name<<" "<<S.roll<<endl<<endl;

    // using class sales_data

    // constructor 1
    sales_data obj1;
    cout<<"obj1: \n";
    print( cout , obj1 );
    // constructor 2
    sales_data obj2("ISBN45784512KL");
    cout<<"obj2: \n";
    print( cout , obj2 );
    // constructor 3
    sales_data obj3("ISBN1324580ASUP" , 5 , 350 );
    cout<<"obj3: \n";
    print( cout , obj3 );
    // constructor 4
    sales_data obj4(cin);

}
