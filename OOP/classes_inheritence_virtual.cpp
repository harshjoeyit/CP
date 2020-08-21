#include<bits/stdc++.h>
using namespace std;

class parent {
public: 
      string msg;
      parent() = default;
      parent(string _msg) : msg(_msg) {
      }
      virtual void wish() {
            cout << msg << endl;
      }
};

class child: public parent {
public:
      string msgStart;
      child() = default;
      child(string _msg, string _msgStart): parent(_msg), msgStart(_msgStart) {
      }
      void wish() override {
            cout << msgStart << " " << msg << endl;      
      }
};

class grandchild: public child {
      string name;
public:
      grandchild() = default;
      grandchild(string _name, string _msg, string _msgStart): child(_msg, _msgStart), name(_name) {
      }
      void wish() override {
            cout << msgStart << " " << msg << " " << name << endl;      
      }
};


class Quote {
    public:
        Quote() = default;
        Quote(const std::string& _bookNo, double _price ): bookNo(_bookNo), price(_price) {
        }
        std::string isbn() const {
            return bookNo;
        }
        // virtual function 
        //derived classes will overrride and apply different discount algorithms
        virtual double net_price(size_t n ) const {
            return n*price;
        }
        // virtual destructor 
        // dynamic binding 
        virtual ~Quote() = default;     

    private:
        string bookNo;
    protected:
        double price = 0.0;
};


class Bulk_quote: public Quote {
    public:
        Bulk_quote() = default;
        
        // this constructor has 4 parameters since it also calls he parametrized constr. of base class
        Bulk_quote(const string& _bookNo, double _price, size_t _min_qty, double _discount): min_qty(_min_qty), discount(_discount), Quote(_bookNo, _price) {  
            /*  
            sequence of running
                1.base class constructor
                2.initialization of members of this class
                3.function body

                the order of mention in initializer list does not affect the execution
            */
        }  
        //generates a discounted price  
        // overrides the virtaul net_price in Quote class 
        double net_price(size_t) const override;
    
    private:
        double discount = 0.0; 
        size_t min_qty = 0;
};

double Bulk_quote::net_price (size_t cnt) const {
    if (cnt >= min_qty)        
        return cnt * (1 - discount) * price;    
    else        
        return cnt * price;
}


int main() {
    parent *pobj = new child("Morning", "Good");
    pobj->wish();
    parent *pobj2 = new grandchild( "Rachel", "Evening", "Good");
    pobj2->wish();



    Quote item;         	//  object of base type Bulk_quote bulk;   
    Bulk_quote bulk("1235410001", 521.2 , 10 , 0.30 );        //  object of derived type 
    
    Quote *p = &item;       //  p points to a Quote object 
    Bulk_quote *bp = &bulk;
    
    p = &bulk;              //  p points to the Quote part of bulk 
    Quote &r = bulk;        //  r bound to the Quote part of bulk
    p = bp;                 //  p points to the Quote part of bulk

    Quote item2(bulk);      // copy costructor 
    item = bulk;
    //bulk = item;          // will throw error 

    cout << sizeof(bulk) <<" "<< sizeof(r) << endl;

    //calles the override version , not he derived version
    double total_price = bulk.net_price(5);         
    
    cout << "book no : "<< bulk.isbn() << "\nnet price: " <<total_price;
}