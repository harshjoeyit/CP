#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    int a[]={1,2,3,4,5,6};
    int *p=a;
    cout<<p+2<<" "<<*(p+2);
cout<<endl;
    char b[]={"123harshit"};
    char *ptr=begin(b);
    cout<<ptr<<" "<<*(ptr+2);  // ptr is printing the string from the point where the pointer is pointing
cout<<endl;
    string str("gangwar");
    const char *sp =str.c_str();
cout<<endl;

//copying an array to a vector
    int arr[]={10,20,30,40,50};
    vector<int> vec(begin(arr)+1,end(arr)-1);  // copying a subset of the original array into the vector
                                           // starts from 1 ends at one less than end-1  ,
    for(auto v: vec)                       // PRINTS TILL ONE BEFORE THE END POOINTER
    cout<<v<<",";
cout<<endl;
// copying the vector to an array

  vector<int> ivec{10,20,30,40,50,60,70,80,90};
  int *ab=&ivec[0];
  for{int i=0; i<9; i++}
  cout<<*(ab++)<<",";

 // accessing the elements of the arrays using the begin and r=the end pointer
  int array1[8]={1,2,3,4,5,6,7,8};
    int *p111= begin(array1);
    int *p222= end(array1);

    while(p111 != p222 )
    {
        cout<<*p111<<" ";
        ++p111;
    }

    ptrdiff_t N = begin(array1) - end(array1);  // ptrdiff_t is the signed library type that suitable to store the differences of the  pointer
    cout<<N<<endl;

return 0;
}
