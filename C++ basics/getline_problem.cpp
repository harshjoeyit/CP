#include<bits/stdc++.h>
using namespace std;

int main()
{
    string name;
    int age;
    string cls;

    cout<<"name: ";
    getline( cin , name );              // consumes every char untill the next line char '\n'
                                        // is encountered ( enter is pressed )  
                                        // newline char is converted to '\0' char to terminate the string 

    cout<<"age: ";
    cin>>age;                       // cin consumes everything before space is encountered , '\n' os also considered space 
                                    // '\n' is still in the cin
    cin.ignore();                   // consumes 1st char present in the cin

    cout<<"class: ";
    getline( cin , cls );           // now cin is empty and can be used fresh   
                                    // otherwise cls would contain '\n' only and terminate without asking for input 

    cout<<"\nyou are  "<<name<<" of age "<<age<<" and class "<<cls;

}