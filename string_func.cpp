#include<bits/stdc++.h>
using namespace std; 


int main() 
{  
	string str; 
	getline(cin,str); 

	str.push_back('s'); 

	cout << "push_back : "; 
	cout << str << endl; 

	str.pop_back(); 

	cout << "pop_back : "; 
	cout << str << endl; 

    //..............................................

    string str1("serene"); 
    if ( str.compare(str1) == 0 ) 
        cout << "Strings are equal"; 
    else 
        cout << "Strings are unequal\n"; 

	
    //.............................................

    str = "The Geeks for Geeks"; 
  
    // find() returns position to first 
    if (str.find("Geeks") != string::npos) 
        cout << "Geeks found in str at " << str.find("Geeks") 
             << " pos" << endl; 
    else
        cout << "word not found in str" << endl;
  
    // Prints position of first occurrence of 
    // any character of "reef" (Prints 2) 
    cout << "First occurrence of character from \"reef\" is at : "; 
    cout << str.find_first_of("reef") << endl; 
  
    // Prints position of last occurrence of 
    // any character of "reef" (Prints 16) 
    cout << "Last occurrence of character from \"reef\" is at : "; 
    cout << str.find_last_of("reef") << endl; 
  
    // rfind() returns position to last 
    // occurrence of substring "Geeks" 
    // Prints 14 
    cout << "Last occurrence of \"Geeks\" starts from : "; 
    cout << str.rfind("Geeks") << endl; 


    //................................................


    string str6 = "animal king";

    char ch_f = str6.front();  // Same as "ch_f = str6[0];" 
    char ch_b = str6.back();   // Same as below 
                               // "ch_b = str6[str6.length() - 1];" 
  
    cout << "First char is : " << ch_f << ", Last char is : "
         << ch_b << endl; 


    //.......................................................

    str = "0123456789";

    //  substr(a, b) 
    // function returns a substring of 
    // b length 
    //  starting from index a 
    cout << str.substr(3, 5) << endl; 
  
    //  if second argument is not passed, string till end is 
    // taken as substring 
    cout << str.substr(3) << endl; 
  
    //  erase(a, b) deletes b characters at index a 
    str.erase(3, 6); 
    cout << str << endl; 
  
    str = "0123456789";

    //  iterator version of erase 
    str.erase(str.begin() + 3, str.end() - 2); 
    cout << str << endl; 
  
    str = "0123456789"; 
  
    //  replace(a, b, str)  replaces b characters from a index by str 
    str.replace(2, 7, "hello"); 


    // using iter
    str = "0123456789";  
    str.replace(str.begin() + 2, str.begin()+5, "hello"); 
  
    cout << str << endl; 
} 
