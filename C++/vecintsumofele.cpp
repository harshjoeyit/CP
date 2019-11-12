#include<iostream>
#include<vector>
#include<string>
using namespace std;
// to input
void input(vector<int> &ivec)   //by reference ,the variable defined is just a dummy variable
{
    int c=1,m=1;
    while(c!=0)
    {
       int n=0;
       cout<<"\n enter the (n) as a vector's --->"<<m<<"st element = ";
       cin>>n;
       ivec.push_back(n);
       cout<<"\n press 0 to stop adding and any other no. to continue";
       cin>>c;
       m++;
    }
}
// to find sum
vector<int> sumele(vector<int> &ivec)               // return type: vector<int>
{                                                   // arguement type: vector<int>         this function returns a vector after receiving and processing one
    vector<int> sumofall;
    int sum=0;
    cout<<"sum of adjacent values  : "<<endl;
    for(unsigned int i=0; i<(ivec.size()-1); ++i)
    {
        sum=ivec[i] + ivec[i+1];
        sumofall.push_back(sum);
        cout<<"sum of : "<<(i+1)<<"st and "<<(i+2)<<"th element is = "<<sum<<endl;
        sum=0;
    }

    return(sumofall);                            // vector returned to the destination of the call of the function
}

int main()
{
    vector<int> tvec;
    input(tvec);
    cout<<endl;
    vector<int> nvec(sumele(tvec));                // initialization of the the new vector "nvec" which has element same as "sumofall" vector
    cout<<endl;                                  // since sumofall is vector and nothing else so it can be used to initialize another vector..

    cout<<"sum of adjacent values : "<<endl;
    for(unsigned int i=0; i<nvec.size(); i++)
    {
        cout<<"sum of : "<<(i+1)<<"st and "<<(i+2)<<"th element is = "<<nvec[i]<<endl;
    }
return 0;
}
