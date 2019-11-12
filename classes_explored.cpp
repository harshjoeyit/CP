#include<iostream>
using namespace std;

class node
{
    friend class Queue;     // explicitly writing class with the name is necessary 

    private:
        int data;
        node *next;
        void print(){
        cout<<data<<endl;}
    
    public:
    void initlz( int d , node *n )
    {
        data = d;
        next = n;
    }

};


class Queue
{
    private:
        node *Front;
        node *Rear;
    
    public:
        void Initlz( node *f , node *r )
        {
            Front = f;
            Front->data += 1;       // access possible to private member node , because Queue is friend of node 
            Rear = r;
            Rear->data += 2;
        }
        void FrontPrint(){
            Front->print();             // print is a private member accessible via friendship
        }
        void RearPrint(){
            Rear->print();             // print is a private member accessible via friendship
        }
        node* search( int data )
        {
            node *temp = Front;
            while( temp != Rear )
            {
                if( temp->data == data )        // data is inaccessable , private member , until Queue is friend of node otherwise we cannot access a private member from anywhere 
                    return temp;
                    temp = temp->next;
            }
            return NULL;   
        }

};



int a = 120;
class arbit
{
    public:
        arbit()
        {
            a = 5;
            b = 1;
            c = 3;
        }
        void show( int c )
        {
            int b = 10;     // look up for variables 1. in the function , 2. in the class
            cout<<a<<" "<<b<<" "<<c<<endl;        // prints 5 10 c(value passed )
            int a = 50;
            cout<<arbit::a<<" "<<this->b<<" "<<this->c;
            //for global object
            cout<<::a<<endl;
        }
    private:
        int a;
        int b;
        int c;
};


// typenames
typedef string Type;
/*string*/ 
Type initVal(); 
class Exercise 
{ 
    public:    
    typedef double Type;    
    //double     double
    Type setVal(Type); 
    //double   
    Type initVal(); 
    private: 
        int val; 
}; 

//since the return type here is not a part of class so it is of type string
// all the types were deecided inside the class while declaring the prototype( double )
//string              double from the class
// Type Exercise::setVal(Type parm)           // inconsistency in return type class says- double - here it is string 
// {  //int   double   double                        
//     val = parm + initVal();    
//     return val;     //int 
// }

int main()
{
    node *node1 = new node;
    node *node2 = new node;
    node *node3 = new node;

    node1->initlz(10, node2);
    node2->initlz(20, node3);
    node3->initlz(30 , NULL);

    Queue *Q = new Queue;
    Q->Initlz( node1, node3 );
    Q->FrontPrint();                 // printing the first element
    Q->RearPrint();                  // printing the rear element 

    auto find = Q->search(30);          // returns the pointer to the node


    arbit A;
    A.show( 30 );
    

}

