#include<bits/stdc++.h>
using namespace std;

// You are given a sequence A1,A2,…,AN. For each valid i, the star value of the element Ai is the number of valid indices j<i such that Aj is divisible by Ai.

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, maxStarVal = 0, currStarVal; 
        cin >> n;
        vector<int> v(n);
        vector<int> count_occurance(1000000);

        for(int i = 0; i < n; i++)
            cin >> v[i];

            
        for(int i = 0; i < n; i++)
        {
            currStarVal = count_occurance[v[i]];
            if(currStarVal > maxStarVal)
                maxStarVal = currStarVal;
                
            for (int j = 1; j <= sqrt(v[i]); j++)       // finds all divisors of v[i]
            { 
                if (v[i] % j == 0)      
                {
                    if (v[i] / j == j) 
                        ++count_occurance[j];           // increments the divisor count  
        
                    else
                    {
                        ++count_occurance[j];                           
                        ++count_occurance[v[i]/j]; 
                    }
                } 
            } 
        }
        cout << maxStarVal << endl;
    }
}