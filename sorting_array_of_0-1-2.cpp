#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& a) {
      if(a.size()<= 1) {
            return;
      }        
      int low = 0, mid = 0, high = a.size()-1;
      
      while(mid <= high) {
            if(a[mid] == 0) {
                  swap(a[mid], a[low]);
                  low += 1;
                  mid += 1;

            } else if(a[mid] == 2) {
                  swap(a[mid], a[high]);
                  high -= 1;

            } else {
                  mid += 1;
            }
      }
      /*
      we dont move mid when we move high, the reason is 
      example left =  1, mid = 2, high = 0
      what happens ater swap is
              left = 1, mid = 0, high = 2
      we cant move mid forward because
      in next swap 
              left = 0, mid = 1, high = 2
      now we can safeily move mid forward 
      */
}

int main() {

}