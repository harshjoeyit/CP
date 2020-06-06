#include<bits/stdc++.h>
using namespace std;

// write a program 

// create a function to read from s file and write int the two files , odd in one and even in one 
// usign the stream iterators
void print_list( list<int> lst , int n )
{
    cout<<"list "<<n<<": ";
    for( auto it = lst.begin(); it != lst.end(); it++ )
        cout<<*it<<" ";
    cout<<endl; 
}

void print_forw_list( forward_list<int> flst , int n)
{
    cout<<"forward list: "<<n<<": ";
    for( auto it = flst.begin(); it != flst.end(); it++ )
        cout<<*it<<" ";
    cout<<endl; 
}

int main()
{
    list<int> lst1 = {3 , 5, 9 , 1 , 8 , 9 , 11};
    list<int> lst2 = { 1 ,6 , 15 ,2 , 10 , 12 , 9 , 4};

    // sorting the lists
    lst1.sort();
    lst2.sort();

    // the lists must be sorted alresy for the merge to work flawlessly
    lst1.merge(lst2 );  
    print_list(lst1 , 1);
    print_list(lst2 , 2 );

    lst1.remove(10);
    print_list(lst1, 1);

    // removing all the even elements from the list 
    // the value is removed if the predicate returns the true value
    lst1.remove_if( []( int i ){ if(i%2 == 0 ) return 1; else return 0; } );
    print_list(lst1, 1);

    // removes all the consecutive duplicates
    lst1.unique([]( int i , int j ){ if(i == j ) return 1; else return 0; }); // write the condition here
    print_list(lst1, 1);                // these conditions sre present by default, event is the predicate is nit privuded as an argument 


    list<int> lst3 = {20,21,22,23};
    auto it = find(lst1.begin() , lst1.end() , 9 );

    // lst3 items are all added to the lst1 before the mentioned iterator
    lst1.splice(it,lst3);
    print_list(lst1, 1);  
    print_list(lst3, 3); 


    forward_list<int> flst1 = {1,3,4,5,6,8} , flst2 = { 11 , 12 ,13 ,14 };
    auto fit = find(flst1.begin() , flst1.end() , 4 );

    // flst2 items are all added to the flst1 after the mentioned iterator
    flst1.splice_after(fit,flst2);
    print_forw_list(flst1, 1);  
    print_forw_list(flst2, 2); 
    
    // also there are two overloaded versions of this algo 
    // having args 
    //( it1 , lst2 , it2 ) , copies all the elements after it2 in lst2 in  lst1 
    // ( it1, lst2 , a , b) ,  copies in the range a , b 
    // all above algorithms are valid for forward lists 
}