#include<bits/stdc++.h>
using namespace std;


class parent
{
    public:
        virtual void foo()
        {
            cout<<"base \n";
        }
};

class child : public parent
{
    public:
        void foo() override
        {
            cout<<"child \n";
        }

};

class grandchild : public child
{
    public:
        void foo() override
        {
            cout<<"grandchild \n";
        }

};


void callfoo( parent* p )
{
    p->foo();
}

void callfoo2( parent *p)
{
    p->parent::foo();    
    // base version called
}




int main()
{
    
    
    parent *P = new parent();
    child *C = new child();
    grandchild *G = new grandchild();

    callfoo(P);
    callfoo(C);         // override
    callfoo(G);         // override 

    cout<<endl;
    callfoo2(P);
    callfoo2(C);         // no override,version mentioned
    callfoo2(G);         // no override ,version mentioned 

    
    
    
    parent p;
    parent *pptr = &p;
    parent &pr = p;

    child c;
    child *cptr = &c;
    child &cr = c;

    cout<<endl;
    
    p.foo();
    c.foo();
    pptr->foo();
    cptr->foo();
    pr.foo();
    cr.foo();

    
    
    // all possible, vice versa not possible 
    grandchild g;
    p = c;      
    c = g;      
    p = g;

    
}