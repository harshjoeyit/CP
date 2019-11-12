#include<bits/stdc++.h>
using namespace std;


int nxt_greater_not_in_array(int low, int high, vector<int> a, int x, int n)
{
    int ans = x+1;
    while( low <= high)
    {
        int mid = low + (high-low)/2;
        
        if (a[mid] == ans) 
        { 
            ans++; 
            high = n - 1; 
            low = mid + 1;
        } 

        if (a[mid] < ans)  
            low = mid + 1;
        else
            high = mid - 1; 
    } 
    return ans;
}

int main()
{
    vector<int> v= {1,2,3,5,9,13,14,15,16,17,19};
    //sort
    cout << "nxt grtr: " << nxt_greater_not_in_array(0, v.size()-1, v, 15, v.size()-1 ) << endl;
}

