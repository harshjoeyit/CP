#include<iostream>
#include<vector>
using namespace std;

// for string all the weekdays arrays  in a 2d array for later printing
void store(int alldata[][7], int arr[],int ct)
{
        for(int j=0; j<7; j++)
        {
            alldata[ct][j]=arr[j];
        }
}

// output function:
void outnow(int alldata[][7],int T)
{
    for(int i=0; i<T; i++)
    {
        for(int j=0; j<7; j++)
        {
            cout<<alldata[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int t,ct=0;
    cin>>t;
    const int T=t;
    int alldata[T][7];

  start:
  while(t--)
  {

    short int days,n=7;
    cin>>days;
    string fday;
    cin>>fday;

    int weekdays[7]={};// initializing every element of the array to be zero

    while(days>3)
    {
        for(unsigned int i=0; i<7; i++)
            ++weekdays[i];
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
            store(alldata,weekdays,ct);
            ct=ct+1;
            goto start;
        }
        n--;
    }

  }  // end of while with test cases

  outnow(alldata,ct);

    return 0;
}

