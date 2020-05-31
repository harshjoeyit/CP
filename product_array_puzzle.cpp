// Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. Solve it without division operator and in O(n).
// Example :
// arr[] = {10, 3, 5, 6, 2}
// prod[] = {180, 600, 360, 300, 900}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    int n, x, k = 1;
    cin >> n;
    vector<int> v1(n), L(n), R(n);

    // method 1 - O(n) - space copmlexity

    for(int i = 0; i< n; i++)
    {
        cin >> v1[i];
        L[i] = k * v1[i];
        k = L[i];
    }
    
    k = 1;
    for(int i = n-1; i >= 0; i--)
    {
        R[i] = v1[i] * k;
        k = R[i];
    }

    for(int i = 0; i < n; i++)
        cout << L[i] << " ";
    cout << endl;


    for(int i = 0; i < n; i++)
        cout << R[i] << " ";
    cout << endl << "ans: ";

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            cout << R[1] << " ";
        else if(i == n-1)
            cout << L[n-2] << " ";
        else
            cout << L[i-1] * R[i+1] << " ";
    }
    cout << endl;


    // O(1) space complexity
     // wroks because 
    // log(1.2.3.4) = log(1) + log(2) + log(3) + log(4)
    // log(1.2.3.4) - log(3) = log(1) + log(2) + log(4) = log(1.2.4)
    // pow(10, log(1.2.4)) = 1.2.4

    int prod = R[0];

    for(int i = 0; i < n; i++)
    {
        double ans = log10(prod) - log10(v1[i]);
        // ans is in decimal and somewhat not accurate 
        ans = ceil(pow(10, ans));
        // ceil value to prevent floor int conversion
        cout << ans << " ";
    }
    cout << endl;

}