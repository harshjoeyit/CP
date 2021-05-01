
/*
    https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

    Rearrange positve and negetive elements such that each negetive number is followed by a positve in alternatig way,
    if there are any extra positve or negetive put them in the end of the array.
    NOTE: maintain the order of appearance.
*/

#include<bits/stdc++.h>
using namespace std;

// right rotate the subarray
void rotate(vector<int> &a, int l, int h) {
    // left rotate by h-l = right rotate by 1
    int by = h-l;   
    reverse(a.begin()+l, a.begin()+l+by);
    reverse(a.begin()+l+by, a.begin()+h+1);
    reverse(a.begin()+l, a.begin()+h+1);
}

/*
    O(n*n) approach
*/
void rearrange(vector<int> &a) {
    int n = a.size();
    for(int i=0; i<n; i++) {
        if (i % 2 == 0 && a[i] > 0) {
            // find next negetive and rotate right 
            int j=i+1;
            while(j < n && a[j] > 0)    j++;
            if(j != n) {
                rotate(a, i, j);
            } 
        }
        else if (i % 2 == 1 && a[i] < 0) {
            // find next positive and rotate right
            int j=i+1;
            while(j < n && a[j] < 0)    j++;
            if(j != n) {
                rotate(a, i, j);
            }
        }
    }
}


/*
    O(nlogn) approach
    NOTE: Order of element is not maintained 
*/

// when neg <= pos
void fill1(vector<int> &a, int neg, int pos) {
    if(neg%2 == 1) {
        for(int i=1; i<neg; i+=2) {
            swap(a[i], a[i+neg]);
        }
    }
    else {
        for(int i=1; i<=neg; i+=2) {
            swap(a[i], a[i+neg-1]);
        }
    }
}

// when neg > pos
void fill2(vector<int> &a, int neg, int pos) {
    if(pos%2 == 1) {
        for(int i=1; i<pos; i+=2) {
            swap(a[i], a[i+pos]);
        }
    }
    else {
        for(int i=1; i<=pos; i+=2) {
            swap(a[i], a[i+pos-1]);
        }
    }
}


/*
    O(n) apporach 
    Note: Order of elements not maintained 
*/
void rearrange(vector<int> &a) {
    int n = a.size(), i = 0, j = n-1;

    // shift all neg to right
    while(i < j) {
        while(i < n && a[i] > 0)    i++;
        while(j >= 0 && a[j] < 0)   j--;
        if(i < j) {
            swap(a[i], a[j]);
        }
    }

    // i has index of leftmost negative element
    if (i == 0 || i == n)   return;

    int k = 0;
    while(k < n && i < n) {
        swap(a[k], a[i]);
        k += 2;
        i += 1;
    }
}


int main() {
}