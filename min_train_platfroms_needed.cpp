
/*
version 1: trains arrive on stations min platfrom needed

version 2: guest arrive in restraunt min table needed

*/


#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 

int min_platforms_needed(vi arr, vi dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms = 1, result = 1;
    int i = 1, j = 0, n = arr.size();   // starting from the arrival of second train as 
                                        // min 1 platfrom will always bww needed 
    while(i < n && j < n)
    {
        if(arr[i] <= dep[j])            //  if arrival time is same as dep time of another train, then min 2 platforms are needed
        {
            ++platforms;
            ++i;
            result = max(platforms, result);
        }
        else
        {
            --platforms;
            ++j;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vi arr(n);
    vi dep(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i] >> dep[i];
    
    cout << "min platfroms : " << min_platforms_needed(arr, dep) << endl;
}