#include<iostream>
using namespace std;

// class 1 
class cls
{
    private: 
        string *ptr;
        string s = "blank";
    
    public:
        cls() = default;
        // paramatrized constructor 
        cls( string *p , string str ) : ptr(p) , s(str) { }
        // copy constructor that -
        cls( const cls &org ) : ptr( new string (*org.ptr) ) , s( *org.ptr )        // creates a dynamic string with the value of the string that is pointed by the pointer ,
                                                                                    //  and initializes the string member with the value pointed by the org
        { }

    void display()
    {
        cout<<ptr<<" "<<*ptr<<" "<<s<<endl;
    }
};



// class 2 
class point
{
    private:
        int a = 0;
        string s = "nul";
    public:
        point() = default;
        point( int aa , string ss ): a(aa) , s(ss) { }
        // a copy constructor is always synthesized when it is not present by default , we might not mention it explicitley
        //  point( const point & );
        void print();
};

// point::p=oint( const point &orig ) :
//     a( orig.a ),
//     s( orig.s )
//     { }

void point::print()
{
    cout<<a<<" "<<s<<endl;
}

point global(10 , "global");




//The only differences are, name of an operator function is always operator keyword followed by symbol of operator and operator functions are called when the corresponding operator is used.
class Complex 
{ 
    private: 
        int real, imag; 
    public: 
        Complex(int r = 0, int i =0)  {real = r;   imag = i;} 
        // This is automatically called when '+' is used with 
        // between two Complex objects 
        Complex operator + (const Complex &); 
        Complex& operator = ( const Complex & );
        void print() { cout << real << " + i" << imag << endl; } 
}; 


Complex Complex::operator+( const Complex &obj )
{ //ret. type           // right hand operand  
  // ref to class
    Complex res; 
    res.real = real + obj.real; 
                     //LHO  +    RHO
    // left hand operand is (this) right hand operand is passed as parameter 
    res.imag = imag + obj.imag; 
    return res; 
} 

// assignment operator must return reference to the left hand operand 
// the synthesized copy assignment operator just looks like this one 
Complex& Complex:: operator=( const Complex &rhs )
{
    real = rhs.real;
    imag = rhs.imag;
    return *this;           // return reference to the left hand operator which is impicitly the *this object 
}


int main()
{
    string y = "yyyy";
    string x = "xxxx";
    cls C1;
    cls C2(&x,y);
    C2.display();
    cls C3(C2);  
    C3.display();
    // another way to copy an object 
    // possible through copy assignment operator function synthesized  in the class when the operator is used 
    cls C4 = C3;
    C4.display();

    // local class objects

    point local( 10 , "local" );
    point *heap = new point(local);
    heap->print();
    *heap = global;
    heap->print();
    point pa[4] = { local , *heap };
    pa[0].print();
    pa[1].print();

    cout<<"sizes of the classes defined : \n";
    cout<<"point : "<<sizeof(point)<<endl;


    //operator overloading 
    Complex c1(10, 5), c2(2, 4) , c3( 1 , 1); 
    Complex c4 = c1 + c2 + c3; // An example call to "operator+" 
    c4.print(); 
    Complex c5 = c4;
    c5.print();
}