#include<bits/stdc++.h>
using namespace std;


class Quote 
{
    public:
        Quote() = default;
        Quote(const std::string& book, double sales_price )
        : bookNo(book), price(sales_price)
        { }

        std::string isbn() const 
        {
            return bookNo;
        }
       
        virtual double net_price(size_t n ) const
        {
            return n*price;
        }

        virtual ~Quote() = default;     // dynamic binding 

    private:
        string bookNo;
    protected:
        double price = 0.0;

};







class Disc_quote : public Quote
{
    public:
        Disc_quote() = default;
        Disc_quote(const string& book, double price, size_t qty, double disc)
        : Quote(book, price), quantity(qty), discount(disc) 
        { }

        // pure virtual function 
        double net_price( size_t ) const = 0;

        protected:
            size_t quantity = 0;            //no of books
            double discount = 0.0;          //fractional dsiscount
};









class Bulk_quote: public Disc_quote
{
    public:
        Bulk_quote() = default;
        
        // this constructor has 4 parameters since it also calls he parametrized constr. of base class
        Bulk_quote(const string& book, double price, size_t qty, double disc) 
        : Disc_quote(book, price,qty,disc) 
        { }

        //overrides the base version of the bulk purchase 
        double net_price(size_t) const override;
    
};

double Bulk_quote::net_price (size_t cnt) const
{
    return quantity*(1-discount)*price;
    // members inherited from the base classes
}



int main()
{
    // not possible - these are abstract classes 
    // Disc_quote *D = new Disc_quote();   
    // Disc_quote D1; 

    Bulk_quote *Bq = new Bulk_quote("12344333" ,3 ,10 ,0.5);

}