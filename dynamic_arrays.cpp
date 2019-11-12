#include<bits/stdc++.h>
using namespace std;


// using type alias 
typedef int array_of_ten[10];


void print_array( int *a , int size )
{
    for( int i = 0; i<size; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
}


// overloaded function print_array
void print_array( string *a , int size )
{
    for( int i = 0; i<size; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
}

int get_size()
{
    return 5;
}




int main()
{
    // returns int pointer to the first block of the array memory allocated 
    int *pia = new int[get_size()];
    // int pointer to an array of ten 
    int *p = new array_of_ten;
    
    //auto b = begin(piarr); - 
    // since the allocated memory does not have array type
    // , instead the meory allocated is of type of the element in the array ( here int )  
    //, no begin or end

    // cannot usee the range based for the dynamically allocated array 
    auto *piarr = new int[5]();
    // block of ten ints values initialized to zero
    print_array( piarr , 5);
    
    // braced list initialization 
    int *pia2 = new int[10]{1,2,3,4,5,6,7};
                    // cannot leave [] empty like static arrays 
                    // we must tell how many blocks to allocate 
    print_array( pia2 , 10 );

    // an array of strings 
    string *psa = new string[5]{"a", "an", "the", string(3,'x')};
    print_array(psa , 5);

    delete[] psa;
    // cannot use initializer list 

    // using unique_ptr to manage the array 
    unique_ptr<int[]> up( new int[10]() );
    
    // autimatically uses delete[] to destroy its pointer 
    // After all, the unqiue_ptr points to an array, not an object so these operators would be meaningless
    // but we can use the subscript to access the elements 

     for( int i = 0 ; i < 10; i++ )
        cout<<up[i]<<" ";
    cout<<endl;             // accessing by index 

    // using the shared pointer       // all 10 blocks  initialized to zero 
    shared_ptr<int> spto_arr(new int[10](), [](int *p) { delete[] p; });
    // uses the lambda we supplied that uses delete [] to free the arra
     // donot have a subscript operator 
     // but we can get a built in pointer by shared pointer 
     // use get() to get a built in pointer  
    for( size_t i = 0; i!= 10; i++ )
        cout<<*( spto_arr.get() + i )<<" ";

    spto_arr.reset();
    if( spto_arr == nullptr )
        cout<<"reset deallocates and sets pointer to Null "<<endl;
    

    // shared pointer to read standard input 
    shared_ptr<char []> spa( new char[10] );        // defalut initialized char array of 10 characters
    cin>>spa.get();
    cout<<spa.get()<<endl;
    
    // built inpointer to read standard input 
    char *pa = new char[10];
    cin>>pa;
    cout<<pa<<endl;
    
    delete [] pa;
    // we do not need to use delete on the smart pointers as they
    //( smart pointers ) automatically use delete[] when they go out of scope 
     

}
