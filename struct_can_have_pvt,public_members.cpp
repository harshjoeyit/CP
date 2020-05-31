#include<bits/stdc++.h> 
using namespace std;


struct sales_data
{
    private:
        string book_no ;
        unsigned int units_sold = 0;
        double revenue = 0.0;

    public:
        sales_data() = default;     //1 
        sales_data( const string &s ) : book_no(s) {/*empty function body */ }    //2
        sales_data( const string &s , unsigned int n , double price ) : book_no(s) , units_sold(n) , revenue(price*n) {/*empty function body */}

        // member function
        void print()
        {
            cout<<"class: \n";
            cout<<"book_no: "<<book_no<<endl;
            cout<<"units_sold: "<<units_sold<<endl;
            cout<<"revenue: "<<revenue<<endl;
        }

};

int main()
{
    sales_data sd("ISBN123456" , 40 , 780.56);
    sd.print();
}