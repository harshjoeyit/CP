#include<bits/stdc++.h>
using namespace std;

void find_closet(int a[], int p, int b[], int q, int c[], int r) {
    int i=0, j=0, k=0;
    int ans_i=0, ans_j=0, ans_k=0, diff = INT_MAX;

    while(i < p && j < q && k < r) {
       
        int mx = max({a[i], b[j], c[k]});
        int mn = min({a[i], b[j], c[k]});

        if(mx-mn < diff) {
            ans_i = i;
            ans_j = j;
            ans_k = k;
            diff = mx-mn;
        }
        if(diff == 0)
            break;

        if(mn == a[i])      ++i;
        else if(mn == b[j]) ++j;
        else                ++k;
    }
    cout << "closest: " << a[ans_i] << " " << b[ans_j] << " " << c[ans_k] << endl;
}

void find_closet_bf(int a[], int p, int b[], int q, int c[], int r) {
    int ans_i=0, ans_j=0, ans_k=0, diff = INT_MAX;

    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) {
            for(int k=0; k<r; k++) {
                if(max({abs(a[i]-b[j]), abs(b[j]-c[k]), abs(c[k]-a[i])}) < diff) {
                    diff = max({abs(a[i]-b[j]), abs(b[j]-c[k]), abs(c[k]-a[i])});
                    ans_i = i;
                    ans_j = j;
                    ans_k = k;
                }
            }
        }
    }
    cout << "closest: " << a[ans_i] << " " << b[ans_j] << " " << c[ans_k] << endl;
}

int main() {
    int a[] = {1, 4, 10}; 
    int b[] = {2, 15, 20}; 
    int c[] = {10, 12}; 
  
    int p = sizeof(a) / sizeof(a[0]); 
    int q = sizeof(b) / sizeof(b[0]); 
    int r = sizeof(c) / sizeof(c[0]); 

    find_closet(a, p, b, q, c, r);
    find_closet_bf(a, p, b, q, c, r);
}