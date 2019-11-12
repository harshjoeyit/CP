#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Why we need allocater class
    /*it means allocating a memory should not mean that 
    It should be consumed instantly , 
    a small part of it could do , 
    we may not always need the whole memory allocated .
    we  create a RESERVE , and use whatever part of it  */

    int n = 10;
    allocator<string> alloc;
    // unconstructed memory allocated 
    auto const p = alloc.allocate(n);       // p - first block of the memory 
    auto q = p ;

    cout<<"sizeof string: "<<sizeof(string)<<endl;
    for( int i = 0; i<10; i++ )
        printf("%u\n",p+i);
    
    for( int i = 0; i<5; i++ )
        alloc.construct(q++ , "hello");
    // q will point to one past the last constructed element
    
    *(p+2) = "stop";
    // cahnging value at a location
    alloc.construct(p,"again");     

    auto p1 = p;
    for ( auto i = 0; i<5 ; i++ )
        cout<<*p1++<<" ";
    cout<<endl;
    
    alloc.destroy(p);
    while (q != p)    
        alloc.destroy(--q);         // deconstucts 
        // this memory may be reused again of dealocated 
    
    printf("q now at: %u\n",q);
     alloc.deallocate(p,n);
        // memory deallocated 




    int a[] = {1,2,3,4,5};
    int b[] = {10,15,25,30};
    int sz_a = 2* sizeof(a)/ sizeof(int);
    allocator<int> alloc_int;
    auto const ip = alloc_int.allocate(sz_a);

    // using algorithm to construct 
    // returns the one past the constructed element
    auto iq = uninitialized_copy( begin(a) , end(a) , ip );
                        // range , starting block of allocated memory
    cout<<"\nmem: ";
    for( int i = 0; i<sz_a ; i++ )
        cout<<*(ip+i)<<" ";
        
    iq = uninitialized_copy_n( begin(b) , 1 , iq );
                        // ptr to copy from destination , no ,start of block to copy to
    cout<<"\nmem: ";
    for( int i = 0; i<sz_a ; i++ )
        cout<<*(ip+i)<<" ";

    
    uninitialized_fill( iq , iq + 3 , 20 );
                    //  ptr to start block , ptr to end block , copy_number
    cout<<"\nmem: ";
    for( int i = 0; i<sz_a ; i++ )
        cout<<*(ip+i)<<" ";

    uninitialized_fill_n( iq+3, sizeof(a)/sizeof(int) , 42);
                    //  pointer to start block , no of elements , copy_number
    cout<<"\nmem: ";
    for( int i = 0; i<sz_a ; i++ )
        cout<<*(ip+i)<<" ";



   
}