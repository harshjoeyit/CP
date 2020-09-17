#include<bits/stdc++.h>
using namespace std;

void find_closet(int a[], int p, int b[], int q, int c[], int r) {
    int i=0, j=0, k=0;
    int p=0, q=0, r=0, diff = INT_MAX;

    while(i < p && j < q && k < r) {
       
        int mx = max({a[i], b[j], c[k]});
        int mn = min({a[i], b[j], c[k]});

        if(mx-mn < diff) {
            p = i;
            q = j;
            r = k;
            diff = mx-mn;
        }
        if(diff == 0) {
            // we cant get better result than 0
            break;
        }

        // the pointer with the min value moves forward 

        if(mn == a[i])      ++i;
        else if(mn == b[j]) ++j;
        else                ++k;
    }
    cout << "closest: " << a[p] << " " << b[q] << " " << c[r] << endl;
}

// brute force 
void find_closet_bf(int a[], int p, int b[], int q, int c[], int r) {
    int p=0, q=0, r=0, diff = INT_MAX;

    for(int i=0; i<p; i++) {
        for(int j=0; j<q; j++) {
            for(int k=0; k<r; k++) {
                int curr_maxdiff = max({abs(a[i]-b[j]), abs(b[j]-c[k]), abs(c[k]-a[i])});
                if(curr_maxdiff < diff) {
                    diff = curr_maxdiff;
                    p = i;
                    q = j;
                    r = k;
                }
            }
        }
    }
    cout << "closest: " << a[p] << " " << b[q] << " " << c[r] << endl;
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