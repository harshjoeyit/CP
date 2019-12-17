#include<bits/stdc++.h> 
using namespace std; 

// use of insert functions 
 
int main() 
{ 
	string str1("0123456789"); 
	string str2("hello"); 

	cout << "Original String : " << str1 << endl; 
	
    // insert str2 starting from index 6 in str1
    // str could be a C- string like "hello tampa"
    str1.insert(6, str2);                
	
    cout << "Using insert : "; 
	cout << str1 << endl; 

    str1 =  "0123456789";  
    str2 = "hello";

    // Inserts all characters from index number 8 and after 8 in str2 
    // at index number 6 of str1        - another overload- insert(i, str2, st);
    str1.insert(6, str2, 1, 3); 

    cout << "using again: " << str1 << endl; 

    str1 =  "0123456789";  
    str2 = "0123456789";
    string str3("explode");
    //string str4 = "explode"; - this is string object too

    // copies 3 char from start - C - string
    str1.insert(6, "explode", 3);
    // copies char from index 3 into str2  - String object
    str2.insert(6, str3, 3);                

    cout << "C- string inserted: " << str1 << endl; 
    cout << "str3 is string object: " << str2 << endl; 


    str1 = "01234567890";

    // inserting a char at 3 for 5 times
    str1.insert(0, 1, '$'); 

    cout << "char inserted : " << str1 << endl;


    str1 = "0123456789";

    // iterator
    auto pos = str1.insert(str1.begin()+5,'$'); 

    cout << "Using insert : "; 
    cout << str1 << endl; 
    cout << "Value at Iterator returned : " << *pos << endl;


    str1 = "0123456789";
    str2 = "meditation";

    // using and returning iterators functions
    pos = str1.insert(str1.begin() + 6, str2.begin() + 2 ,  str2.end() - 3); 
    
    cout << "Using iterators : "; 
    cout << str1 << endl; 
    cout << "Value at Iterator returned : " << *pos << endl;

	return 0; 
} 
