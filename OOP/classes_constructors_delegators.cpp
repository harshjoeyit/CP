#include<bits/stdc++.h> 
using namespace std;

// sales_data class 
class sales_data {
    string book_no ;
    unsigned int units_sold;
    double revenue;
public:
    // sales_data() = default     
    // no need for above default constuctor 
    // our default arguments make constructor work as default constructo1r
    // values of the data members are iniitalized using                                        
    sales_data( const string &s = "ISBN00000000" , unsigned int n = 0 , double price  = 0.0 ): book_no(s) , units_sold(n) , revenue(price*n) {}        
    void print() {                                                    //   iniitalizer list 
       cout<<"book_no: "<<book_no<<endl;
       cout<<"units_sold: "<<units_sold<<endl;
       cout<<"revenue: "<<revenue<<endl<<endl;
    }
};

class debian {
private:
    string distro1;
    string distro2;
    int total;

public:
    // constructor 1: 
    debian( string d1 , string d2 , int t ): distro1(d1) , distro2(d2), total(t) {
        cout << "constructor 1 called\n";
    }
    
    // delegating constructors

    // defining default constructor as - delegation to another constructor
    // delegates to 1 for initialization
    debian(): debian("","", 0) {
        cout << "defalut constructor called\n";
    }        
    // cuonstructor 3, also delegates to 1
    debian( string d1 , string d2 ): debian( d1 ,d2 , 0) {
        cout << "constructor 3 called\n";
    }       
    // constructor 4, delegates to default constructor , which delegates to constructor 1
    debian( istream &input ): debian() { 
        cout << "constructor 4 called\n";
        read( input); 
    }    
    // public print function 
    void print() {
        cout<<"distro 1: "<<distro1<<endl;
        cout<<"distro 2: "<<distro2<<endl;
        cout<<"total : "<<total<<endl<<endl;
    }
    void read( istream &input) {
        cout<<"disro1 , distro2 , total \n";
        input>>distro1>>distro2;
        total = 2;   
    }
};


// Only one cosntructor defined explicitly
// it will raise error, if object is created like new Test(),
//  since default constructor is not defined 
class Test {
      int x;
public:
      // Test() = default;
      Test(const Test &rhs) {
            cout << "Copy\n";
      }
};


int main() {
    //same constructor works for obj1 and obj2... 
    // there cannot be mre than one constructor with default arguments
    // after all there is only one default constructor 
    // we can choose where we want to give default arguments 
    
    // onj with no args - default initiaized
    sales_data obj1;        
    cout<<"obj1: \n";
    obj1.print();

    // with only one arg
    sales_data obj2("ISBN1324580ASUP" );
    cout<<"obj2: \n";
    obj2.print();

    // first arg must be provided for prviding next arg
    sales_data obj3("", 30);
    cout<<"obj3: \n";
    obj3.print();

    // all the three args 
    sales_data obj4("ISBN094545009KE" , 100 , 500);
    cout<<"obj4: \n";
    obj4.print();

    // debian class 
    debian db1;
    debian db2("linux" , "fedora");
    debian db3("UBUNTU" , "FEDORA" , 2);
    debian db4(cin);

    db1.print();
    db2.print();
    db3.print();
    db4.print();



    // .........
    // raises an error - no default constructor present 
    Test t;
    t.print();
    Test t1 = t;
}
