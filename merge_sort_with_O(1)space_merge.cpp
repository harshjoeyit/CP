

/*
Merge Sort with O(1) space merge 
*/

#include<bits/stdc++.h>
using namespace std;

/*
Suppose we want to store arr[i] and arr[j] both at index i(means in arr[i]). 
First we have to find a ‘maxval’ greater than both arr[i] and arr[j]. Now we 
can store as arr[i] = arr[i] + arr[j]*maxval. Now arr[i]%maxval will give the 
original value of arr[i] and arr[i]/maxval will give the value of arr[j]. So 
below is the implementation on merge sort.
*/

void merge(vector<int> &a, int st, int mid, int en, int maxEle) {
      int i = st, k = st;
      int j = mid+1;
      while (i <= mid && j <= en) {
            if(a[i] % maxEle <= a[j] % maxEle) {
                  a[k] = a[k] + (a[i] % maxEle) * maxEle;
                  i += 1;
            } else {
                  a[k] = a[k] + (a[j] % maxEle) * maxEle;
                  j += 1;
            }
            k += 1;
      }

      while (i <= mid) {
            a[k] = a[k] + (a[i] % maxEle) * maxEle;
            i += 1; 
            k += 1; 
      }
      while (j <= en) {
            a[k] = a[k] + (a[j] % maxEle) * maxEle;
            j += 1;
            k += 1;
      }

      for(int i=st; i<=en; i++) {
            a[i] = a[i]/maxEle;
      }
}

void mergeSort(vector<int> &a, int st, int en, int maxEle) {
      if(st < en) {
            int mid = (st + en)/2;
            mergeSort(a, st, mid, maxEle);
            mergeSort(a, mid+1, en, maxEle);
            merge(a, st, mid, en, maxEle);
      }
}

int main() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++) {
            cin >> a[i];
      }
      int maxEle = *max_element(a.begin(), a.end());
      
      mergeSort(a, 0, n-1, maxEle + 1);
      for (size_t i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
      }
      cout << endl;
}