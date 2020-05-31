#include<bits/stdc++.h>
using namespace std;

int *i = new int(); // intitalized to 0
int *p = new int(124);
string *dyn_s = new string(); // constructs an empty string
string *s = new string(9,'f');
vector<int> *ivec = new vector<int>({0,2,4,6,7});
auto *ptr = new auto(*s);       // using auto allocate dynamic memory

// structure type objects 
struct node
{
    int a , b;
}
obj{ 5,15 };
// global structure variable

struct node *new_node = new struct node( {10 ,20 } );
auto *New_node = new auto( obj );
// since a contsant declaration must be initialized, here empty parenthesis mean it is zero 
const int *pci = new const int();

// function returns a shared pointer to the object
// share pointer made using new 
shared_ptr<int> clone( int x )
{
    return shared_ptr<int>( new int(x) );// cant return plain pointers to shared pointer type
}


int main()
{
    shared_ptr<string> sptr;        // sptr == nullptr
    shared_ptr<list<int>> lptr;     // lptr == nullptr 
    // the above pointer are NULL as no constructor is passed at the time of memory allocation 

    if( sptr == nullptr )
        cout<<"sptr points to null "<<endl;
    else
        cout<<"sptr points to: "<<*p<<endl;

    shared_ptr<int> iptr = make_shared<int>(42);
    shared_ptr<string> sptr2 = make_shared<string>(10,'9');
    // pointing to an integer value initialized to be 0
    shared_ptr<int> iptr2 = make_shared<int>();
    // declaration using auto , empty vector<string>
    auto vptr = make_shared<vector<string>>();

    // iptr and q point to same objet
    auto q(iptr);
    // int to which r points has only one user ,counter = 1, itself 
    auto r = make_shared<int>(15);
    //assignment changes the int to which r was pointing to 
    r = q; 
    // counter for q is incresed , one more user , for r is decreased
    // counter to int to which r is pointing reduces to zero, automatically freed 

    cout<<*p<<endl;
    cout<<*s<<endl<<"vector: ";
    // using the arrow operator since the 
    // vector is repreented by a pointer here and 
    // we want to access one of itd function push_back() - (*ivec).push_back
    ivec->push_back(42);
    ivec->push_back(24);
    // range based for loop
    for( auto &x: *ivec )
        cout<<x<<" ";

    // using iterator to access dynamic vector 
    cout<<endl<<"vector: ";    
    for( auto it = ivec->begin(); it != ivec->end(); it++ )
        cout<<*it<<" ";
    cout<<endl;

    // accessing the new_node and New_node
    cout<<new_node->a<<" "<<new_node->b<<endl;
    cout<<New_node->a<<" "<<New_node->b<<endl;

    cout<<*pci<<endl;

    delete s;

    shared_ptr<int> sip( new int(42) );
    // making a shared oointer usung new

    shared_ptr<int> sip2;

    cout<<"sip: "<<*sip<<endl;
    cout<<"sip count: "<<sip.use_count()<<endl;
    cout<<"sip2 count: "<<sip2.use_count()<<endl;

    if( sip2 == nullptr )
        sip2 = sip;
    
    cout<<"sip: "<<*sip<<endl;
    cout<<"sip2: "<<*sip2<<endl;
    cout<<"sip count: "<<sip.use_count()<<endl;
    cout<<"sip2 count: "<<sip2.use_count()<<endl;


    
    // shared pointers to string literal , c style string  
    char s1[] = "hello!";
    char s2[] = " world";
    shared_ptr<char *> sps1( new char*(s1));       // initialized with s1
    shared_ptr<char *> sps2( new char*(s2));       // initialized with s2
    strcat(*sps1 , *sps2);

    cout<<"literal 1: "<< *sps1<<"\nliteral 2: "<<*sps2<<endl;
    
}