
/*
    ar1[0..m-1] and ar2[0..n-1] are two given sorted arrays 
    and x is given number. This function prints the pair  from 
    both arrays such that the sum of the pair is closest to x. 

    Logic- two pointers 
*/

#include<bits/stdc++.h>
using namespace std; 

void printClosest(int ar1[], int ar2[], int m, int n, int x#define int long long int
#define MOD 1000000007
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>

template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}

template <typename T1, typename T2>
void print(vector<pair<T1, T2>> v)
{
    for(auto x: v)
        cout << "("<< x.first << "," << x.second <<"), ";
    cout << endl;
}

template <typename T1, typename T2>
void print(map<T1, T2> m)
{
    for(auto it = m.begin(); it != m.end(); it++)
        cout << it->first << " - " << it->second << endl; 
}

template <typename T>
void print(set<T> s)
{
    for(auto x: s)
        cout << x << " ";
    cout << endl; 
}
) 
{ 
    int diff = INT_MAX; 
    int res_l, res_r; 
  
    int l = 0, r = n-1; 
    while (l<m && r>=0) { 
       
       if (abs(ar1[l] + ar2[r] - x) < diff) { 
           res_l = l; 
           res_r = r; 
           diff = abs(ar1[l] + ar2[r] - x); 
       } 

       if (ar1[l] + ar2[r] > x) 
           r--; 
       else  
           l++; 
    } 
  
    cout << "The closest pair is [" << ar1[res_l] << ", "
         << ar2[res_r] << "] \n"; 
} 
  

int main() 
{ 
    int ar1[] = {1, 4, 5, 7}; 
    int ar2[] = {10, 20, 30, 40}; 
    int m = sizeof(ar1)/sizeof(ar1[0]); 
    int n = sizeof(ar2)/sizeof(ar2[0]); 
    int x = 38; 
    printClosest(ar1, ar2, m, n, x); 
    return 0; 
} 