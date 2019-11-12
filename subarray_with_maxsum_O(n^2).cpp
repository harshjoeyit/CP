// an array consits of both positive and negetive numbers find the subarray with the maximum sum

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {-2,-3,4,-1,-2,1,5,-3};
    int sum, maxsum = -1 , J=-1 , I=0;

    for(int i = 0; i < a.size(); i++ )
    {   
        sum = 0;
        for(int j = i; j < a.size(); j++ )
        {
            sum = sum + a[j];
            if(sum > maxsum)
            {
                maxsum = sum;
                J = j;
                I = i;
            }
        }
        
    }

    for(int i = I; i<=J; i++ )
        cout<<a[i]<<" ";
    cout<<endl;
}