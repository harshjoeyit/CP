#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

int main()
{
    cout<<"size of an integer variable = "<<sizeof(int)<<endl<<"size of a float variable = "<<sizeof(float)<<"\n";
    cout<<"size of an long variable = "<<sizeof(long)<<endl<<"size of a double variable = "<<sizeof(double)<<"\n";
    cout<<"size of an long long variable = "<<sizeof(long long)<<endl<<"size of a uint64_t  variable = "<<sizeof(uint64_t )<<"\n";
    cout<<"size of an long double variable = "<<sizeof(long double)<<endl<<"size of a uint32_t variable = "<<sizeof(uint32_t)<<"\n";
    cout<<"size of uint8_t = "<<sizeof(uint8_t)<<endl<<"size of uint16_t = "<<sizeof(uint16_t)<<endl<<"size of integer pointer = "<<sizeof(intptr_t)<<endl;

    string one("Hello world");

    cout<<"no of characters = "<<one.length()<<" or "<<one.size()<<endl;  // no. of characters
    cout<<"storage size of the string = "<<sizeof(one)<<" bytes"<<endl;
    cout<<" size = "<<sizeof(string)<<" bytes"<<endl;                               //strings have a size of 24 bytes
    cout<<" max size = "<<one.max_size()<<endl;

    char two[10]="Hello";

    cout<<"no of characters = "<<strlen(two)<<endl;
    cout<<" size of the string = "<<sizeof(two)<<"bytes"<<endl;
    cout<<" size = "<<sizeof(char)<<endl;

    vector <char> myvector;
    myvector.push_back('b');
    myvector.push_back('a');
    myvector.push_back('s');         // vector has a storage size of  12  bytes
    myvector.push_back('j');
    myvector.push_back('k');
    myvector.push_back('j');
    myvector.push_back('k');
    myvector.push_back('j');

    cout<<"no of integers = "<<myvector.size()<<endl;  // no. of characters
    cout<<"storage size = "<<sizeof(myvector)<<" bytes"<<endl;
    cout<<" size = "<<sizeof(vector <int>)<<" bytes"<<endl;

return 0;
}
