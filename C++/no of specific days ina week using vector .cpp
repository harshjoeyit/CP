#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,ct=0;
    cin>>t;
    const int T=t;
    vector<vector<int>> alldata;

  start:
  while(t--)
  {

    short int days,n=7;
    cin>>days;
    string fday;
    cin>>fday;

    vector<int> weekdays(7,0);// initializing every element of the vector to be zero

    while(days>3)
    {
        for(unsigned int i=0; i<7; i++)
        {
            ++weekdays[i];
        }
        days=days-7;
    }

    vector<string> daynames{"mon","tues","wed","thurs","fri","sat","sun"};

    while(n)
    {
        if(fday==daynames[n])
        {
            while(days--)
            {
                ++weekdays[n];
                n++;
            }

            alldata.push_back(weekdays);
            goto start;
        }
        n--;
    }

  }  // end of while with test cases

  for(int test=0; test<T; test++)
  {
      for(int each=0; each<7; each++)
        cout<<alldata[test][each]<<" ";
      cout<<endl;
  }

    return 0;
}


