
#include<bits/stdc++.h>
using namespace std;

// babylonian method
float SQRT(float n) {
    float x = n;
    float y = 1;
    float e = 0.000001;
    while(x - y > e) {
        x = (x + y) / 2;
        y = n / x;
    }
    return x;
}

// binary search 
float bsSQRT(float n) {
    float low = 1, high = n, mid;
    
    while (low <= high ) {
        mid = (low + high) / 2;
        if ((high - mid < 0.000001) || (mid * mid == n)) {
            break;
        }
        else if(mid*mid > n) {
            high = mid - 0.000001;
        } else {
            low = mid + 0.000001;
        }
    }
    return mid;
}

int main() {
    int n;
    cin >> n;
    cout << bsSQRT(n) << "\n";
    cout << sqrt(n) << "\n";
}