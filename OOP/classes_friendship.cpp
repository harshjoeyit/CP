#include<bits/stdc++.h> 
using namespace std;

class sales_data {
    string book_no ;
    unsigned int units_sold = 0;
    double revenue = 0.0;
public:
    sales_data() = default;     //1
    sales_data( const string &s ) : book_no(s) {/*empty function body */ }    //2
    sales_data( const string &s , unsigned int n , double price ) : book_no(s) , units_sold(n) , revenue(price*n) {/*empty function body */}
    // member function
    void print();
    //friends
    friend void read( istream& , sales_data& );
    
};

// friend function 
void read( istream &input , sales_data &obj )
{
    int price;
    cout<<"input: \n";
    input>>obj.book_no;
    input>>obj.units_sold;
    input>>price;
    obj.revenue = obj.units_sold * price;
}


void sales_data:: print()
{
    cout<<"\nclass: \n";
    cout<<"book_no: "<<book_no<<endl;
    cout<<"units_sold: "<<units_sold<<endl;
    cout<<"revenue: "<<revenue<<endl;
}


int main()
{
    sales_data sd("ISBN1212121");   // constructor 2 used 
    sd.print();

    sales_data sd1;
    read( cin,sd1 );
    sd1.print();
}