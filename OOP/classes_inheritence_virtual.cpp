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
        //derived classes will overrride and apply different discount algorithms
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



class Bulk_quote: public Quote
{
    public:
        Bulk_quote() = default;
        
        // this constructor has 4 parameters since it also calls he parametrized constr. of base class
        Bulk_quote(const string& book, double p, size_t qty, double disc) 
        : Quote(book, p), min_qty(qty), discount(disc) 
        { 
            // sequence of running 
            /*  1.base class constructor
                2.initialization of membes of this class
                3.function body
            */
        }  
        //generates a discounted price  
        double net_price(size_t) const override;
    
    private:
        double discount = 0.0; 
        size_t min_qty = 0;
    
};

double Bulk_quote::net_price (size_t cnt) const
{
    if (cnt >= min_qty)        
        return cnt * (1 - discount) * price;    
    else        
        return cnt * price;
}



int main()
{
    Quote item;         	//  object of base type Bulk_quote bulk;   
    Bulk_quote bulk("1235410001", 521.2 , 10 , 0.30 );        //  object of derived type 
    Quote *p = &item;       //  p points to a Quote object 
    Bulk_quote *bp = &bulk;
    p = &bulk;              //  p points to the Quote part of bulk 
    Quote &r = bulk;        //  r bound to the Quote part of bulk
    p = bp;                 // p points to the Quote part of memory pointed

    Quote item2(bulk);
    item = bulk;
    //bulk = item;

    cout<<sizeof(bulk)<<" "<<sizeof(r)<<endl;

    double total_price = bulk.net_price(5);         //calles the override version , not he derived version
    cout<<"book no : "<< bulk.isbn() << "\nnet price: " <<total_price;

}