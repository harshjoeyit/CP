#include<bits/stdc++.h>
using namespace std;

void print_all_possible_sums(int a[], int n, int i, int sum, set<int> &s)
{
    if(i <= n)
    {
        s.insert(sum);
        print_all_possible_sums(a, n, i+1, sum, s);
        print_all_possible_sums(a, n, i+1, sum+a[i], s);
    }
}

int main()
{
    int a[] = {1, 4, 6, 10};
    set<int> s;
    print_all_possible_sums(a, 4, 0, 0, s);
    for(auto x: s)
        cout << x << " ";
    cout << endl;
}