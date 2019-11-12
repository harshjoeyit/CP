#include<bits/stdc++.h>
using namespace std; 
  
// no copy
class nocopy 
{
    int data = 1;
    public:
        nocopy() = default;
        nocopy( const nocopy& ) = delete ;
        nocopy &operator=(const nocopy& ) = delete;
        ~nocopy() = default;
        // if the destructor is deleted then then no objects can be created 
    void print()
    {
        cout<<data<<endl;
    }
};


/* A nested class is a class that is declared in another class. 
The nested class is also a member variable of the enclosing class and has the same access rights as the other members. 
However, the member functions of the enclosing class have no special access to the members of a nested class.
*/
class budget
{
    int income;

    public: 
        class expenses
        {
            int schoolfees;
            int groceries;
            int rent;

            public:
               expenses( int sf = 0 , int gr = 0, int r = 0): schoolfees(sf) , groceries(gr) , rent(r) { }
                int spent()
                {
                    return ( schoolfees + groceries + rent );
                }
        };

        expenses exp;
        budget( int i , expenses e ): income(i) , exp(e) { }

        int savings()
        {
            return ( income - exp.spent() );
        }

};



int main()
{
    nocopy nc1;
    nc1.print();
    // follow show error that the function is deleted 
    //nocopy nc2 = nc1;
    //nocopy nc3(nc1);
    nocopy *nc2 = new nocopy();
    nc2->print();
    // if the destructor is deleted then dynamic objects cannot be deleted 
    //delete( nc2 );

    budget::expenses obj(100,200,300);
    budget jan( 2000 , obj );

    cout<<"expense: "<<obj.spent();
    cout<<"savings: "<<jan.savings()<<endl;
    
}
