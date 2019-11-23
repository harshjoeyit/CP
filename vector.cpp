#include<iostream>
#include<vector>
using namespace std;

#define VIT vector<int>::iterator  // replaces VIT test by vector<int> :: iterator
typedef vector<int>::iterator IT;  // IT can be used to declare vector iterator variables 

void display(vector<int> dq)
{
    cout<<"vector: "<<endl;
    for(auto it = dq.begin(); it != dq.end(); it++)
        cout<<*it<<" ";
}


int main()
{
    // vectors are dynamic arrays
    vector<int> vec1;
    vector<int> v{5,3,6,8,7,1,2,12};

    // another type of declaration
    int in;
    vector< decltype(in) > dec_i_vec{1,2,3,4,5,6,7};
    for( auto &ref : dec_i_vec )
        cout<<ref<<" ";

// iterators ...........................
    vector<int> v(10,2);
    auto v2(v);
    auto iter=v2.begin();
    auto iter2=v2.end();

    //.. imp...........................................
    int n = 10, m = 5;
    vector<vector<int>> grid;
    grid.assign(n, vector<int>(m, 0));

    while(iter<iter2)
    {
        cout<<*iter<<" ";
        iter++;
    }cout<<endl;
 // size changes for each push_back

    vec1.push_back(2); // enters value at the end
    vec1.push_back(7);
    vec1.push_back(5);
    vec1.push_back(9);
    vec1.push_back(3);
    vec1.push_back(12);
    vec1.push_back(5);

 //   vec1.erase(vec1.begin(),vec1.end());
    cout<<" vector: ";
    for(unsigned int i=0; i<vec1.size(); i++)
    {
        cout<<vec1[i]<<" ";
    }

    vec1.insert(vec1.begin()+2,11);  //add the element before the index number specified

        cout<<"\n vector: ";
    for(unsigned int i=0; i<vec1.size(); i++)
    {
        cout<<vec1[i]<<" ";
    }


    vec1.erase(vec1.begin()+3);

        cout<<"\n vector: ";
    for(unsigned int i=0; i<vec1.size(); i++)
    {
        cout<<vec1[i]<<" ";
    }

    if(vec1.empty())  // vec1.empty() returns the boolean value if the vector is empty or not
    {
        cout<<"\n is empty";
    }
    else{
        cout<<" \n not empty";
    }


    vec1.clear();

        cout<<"\n vector: ";
    for(unsigned int i=0; i<vec1.size(); i++)
    {
        cout<<vec1[i]<<" ";
    }

    if(vec1.empty())  // vec1.empty() returns the boolean value if the vector is empty or not
    {
        cout<<"\n is empty"<<endl;
    }
    else{
        cout<<" \n not empty"<<endl;
    }

    cout<<" size of vector= "<<sizeof(vector <int>);

    int fg[] = {1,2,3,4,5,6,7,8};
    vector<int> vectr(fg+3,fg+6);

    //a.swap(b); swaps a with b (a and b are vectors )
    // swap(a,b) // same job done

    vector<int>::difference_type count;
    count = abs(vec1.end() - vec1.begin());
    cout<<endl<<count;  // counts the elements in the container 

    vector<int> vec={97,98,99,100,101,102,103,104,105};

    vector<char> cvec(vec.begin(),vec.end());  // intializing by changing the type if possible
    for(auto it = cvec.cbegin(); it != cvec.cend(); it++ )
        cout<<*it<<" ";

    vector<int> vec2{10,20,30,40,50,60,70,80,90,100,101,102,103};
    initializer_list<int> il{2,4,6,8,10};
    vec2.assign(il);  // all the eleemnts of the initialzer list are copied in the vector 

    // random access
    //similar to the operation vectorr[2]
    cout<<"element at position 2: "<<vec1.at(2)<<endl;
    cout<<"element in the front: "<<vec1.front();
    cout<<"element in the end : "<<vec1.back();

    // to add or remove

    // removes last element 
    v.pop_back(); 
  
    // prints the vector 
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    // inserts 5 at the beginning 
    v.insert(v.begin(), 5); 
  
    cout << "\nThe first element is: " << v[0]; 
  
    // removes the first element 
    v.erase(v.begin()); 

    // to replace elements in the vector 
    // replaces 1 element of the vector with 5
    v.emplace(v.begin(), 5); 
    cout << "\nThe first element is: " << v[0]; 
  
    // Inserts 20 at the end in place of existing value 
    v.emplace_back(30); 
    // cannot use emplace front

    //inserting 

    vector<int>::iterator it ;
   it = vec1.begin()+3;
   cout<<*it<<endl;

    display(vec1);
   it = vec1.insert(it,111);  // returns the iterator pointing to the element that was added

   display(vec1);
   cout<<endl<<*it<<endl;

   it = vec1.insert(it,5,4);  // returns vector to the first element added 

   display(vec1);
   cout<<endl<<*(it)<<endl;

   vec1.insert(vec1.end(),{1,2,3,4,5,6,7,8,9});

   // continuous input at the beginning
    vector<int> vecx;

   int x;
   auto it = vecx.begin();
   cout<<"enter vector element: ";
   while(cin>>x)
   {
       it = vecx.insert(it,x);
       cout<<"enter vector element: ";
   }
   display(vecx);


   // capacity 
    vector<int> ivec11;
    vector<int> ivec22;

    ivec11.push_back(1);
    ivec11.push_back(2);
    ivec11.push_back(3);
    ivec11.push_back(4);
    ivec11.push_back(5);
    

    ivec22 = ivec11;

    cout<<"cap of vec 1: "<<ivec11.capacity()<<endl;
    // the capacity of the copied vector is the same as the size of the vec1 , since the memory allocated is of the no of elements in the vec1
    cout<<"cap of vec2: "<<ivec22.capacity()<<endl;


    

return 0;
}



