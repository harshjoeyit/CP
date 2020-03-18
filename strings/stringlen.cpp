#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string str("Test string");
  string str2;
  cout << "The size of str is: " << str.length() << "\nthe  size is : "<< str.size()<<endl;

  str2=str;
  cout<<str<<"-copy->"<<str2;

  if(str==str2)
    cout<<"\ncopied"<<endl;
  else
    cout<<"\nnot copied"<<endl;

  cout<<"concatenated : "<<str+str2<<endl;

  if (str.empty())
    cout<<"empty"<<endl;
  else
    cout<<"not empty"<<endl;

  str[4]='_'; // referring to the index 4 n the string
  cout<<str<<endl;

  string str3,str4;
  cout<<"enter the string: "<<endl;
  cin>>str3;
  cout<<str<<" "<<str2<<" "<<str3<<endl; //important: string str3 after white spaces is not in the output screen while those initialized are.

  cout<<str.size()<<endl; // this can also be used to tell size if the string
                                        // also in the output the preceding white spaces are neglected.
  string word,line;
  cout<<"first string ";
  while(cin>>word)
    cout<<word<<endl;   //press ctrl+z to stop the loop
  cout<<" second string";  // ?? why dos the second does not input
  while(getline(cin,line))
    if (!line.empty() )
    cout<<line<<endl;

 return 0;
}
