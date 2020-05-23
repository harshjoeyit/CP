#include<bits/stdc++.h>
using namespace std;

//###########################################################################################################################################################

// problem
// The way Alice and Bob decide who eats each slice is as follows. 
// First, the order in which the pies are to be handed out is decided. 
// There is a special token called the "decider" token, initially held by Bob. 
// Until all the pie is handed out, whoever has the decider token will give the 
// next slice of pie to one of the participants, and the decider token to the other 
// participant. They continue until no slices of pie are left.
// All of the slices are of excellent quality, so each participant obviously wants to 
// maximize the total amount of pie they get to eat. Assuming both players make their 
// decisions optimally, how much pie will each participant receive

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, b = 0, a = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    for(int i = n-1; i >= 0; i--)
    {
        if(b > a)
            a += v[i];
        else
            b += v[i];
    }
    cout << min(b,a) << " " << max(b, a) << endl;
}