#include<iostream>
#include<vector>
#include<string>
using namespace std;


int main()
{
    vector<string> vec;      // try a string arraypN
    string quote;
    int N;
    cin>>N;

// works for only one string


        getline(cin,quote);
        vec.push_back(quote);


    int c=0;
    start:
    for(int i=0; i<vec.size(); i++)
            {
                 for(int j=0; j<vec[i].length()-2; j++)
                 {
                     if(vec[i][j]=='n')           // step wise checking
                        if(vec[i][j+1]=='o')
                            if(vec[i][j+2]=='t')
                            {
                                cout<<"Real Fancy"<<endl;
                                break;          // end the for loop working for vec[i]
                            }
                            else
                                continue;    // re check the loop
                        else
                            continue;       // re do the loop
                     else
                     { //IMPORTANT : PUTTING THE CONDITION IN THE LST ELSE BECAUSE ITS IF() IS FIRST TO BE CHECJED
                         if(j==vec[i].length()-3)          // if the third last character is reached then is no chance of finding a not further
                            cout<<"regularly fancy"<<endl;
                        continue;
                     }

                 }
            }



return 0;
}
// problem: last string is automatically inputted
