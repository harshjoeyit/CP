#include<bits/stdc++.h>
using namespace std;

// we aim to find the largest wordlength having no ascender or descender 
int main()
{
    string name;
    getline(cin, name);
    // words extendong above half the line are ascenders , while extending belpw the line are descenders 
    string ascender_desccender("dfhkltgjpqy");
    int  word_start = 0, pos = 0, max = INT_MIN; 

    while( (pos = name.find_first_of(ascender_desccender,pos)) != string::npos )
    {
        if((pos - word_start) > max )
            max = pos - word_start;
            
        word_start = ++pos;
    }
    if(word_start == 0)                 // for the case when there are no descender and the ascender in the name , pos = npos , in first iteration 
        cout<<"max length word : "<<name.length();     
    else if( word_start != name.length()  &&  (max < name.length() - word_start) )      // for the case when name does not end with the ascender or descender , and largest substring is in the last
        cout<<"max length word : "<<name.length() - word_start;
    else                                                                                // for the rest cases 
        cout<<"max length word : "<<max;
}

// also all the exception cases in if else statements can be resolved if one descendent is added deleberately in the end of the name  
// ex: eueueue + p             : case 1
//ex eoeopqetioioioioio + t    : case 2
