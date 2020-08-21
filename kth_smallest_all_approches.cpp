#include<bits/stdc++.h>
using namespace std;

// partition [l, r]
int Partition(int a[], int l, int r) {                  
    int pivot = r;
    int pindex = l;

    for(int i=l; i<=r-1; i++) {
        if(a[i] <= a[pivot]) {
            swap(a[i], a[pindex]);
            ++pindex;
        }
    }
    swap(a[r], a[pindex]);
    return pindex;
}
int randPartition(int a[], int l, int r) {
    int len = r-l+1;
    int i = l + (rand() % len);
    swap(a[i], a[r]);

    return Partition(a, l, r);
}


int kthSmallest(int a[], int l, int r, int k) {
      if(k > 0 && k <= r-l+1) {
            int pIndex = randPartition(a, l, r);
            // array divided at pIndex
            int currK = pIndex - l + 1;
            if(currK == k) {
                  return a[pIndex];
            }
            else if(currK > k) {
                  // we have kth element of the left partition
                  return kthSmallest(a, l, pIndex-1, k);
            } else {
                  // we have kth element on the right partition,
                  // also we have already covered currK length 
                  // we only need to cover remaining 
                  return kthSmallest(a, pIndex + 1, r, k-currK);
            }
      }
      return INT_MAX;
}

int main() {
      srand(0);
      int a[7] = {1,2,3,7,6,5,4};
      int k = 4;
      cout << kthSmallest(a, 0, 6, k);
}