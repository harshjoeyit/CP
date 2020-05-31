#include<bits/stdc++.h>
using namespace std;
#define int long long 

/* best version */

int maxSubarraySumCircular(vector<int>& v) {
        int max_so_far = v[0];
        int max_end_here = v[0];
        int totalsum = v[0];
        int min_so_far = v[0];
        int min_end_here = v[0];

        for(int i=1; i<v.size(); i++){
                totalsum += v[i];
                max_end_here = max(max_end_here + v[i], v[i]);
                max_so_far = max(max_end_here, max_so_far);
                min_end_here = min(min_end_here + v[i], v[i]);
                min_so_far = min(min_so_far, min_end_here);
        }
        if(max_so_far < 0){ //means all element are negative
                return max_so_far;
        }
        return max(max_so_far, (totalsum - min_so_far));
}



/*my version*/

const int mxN = 1e6+10;
int a[mxN], pre[mxN], suf[mxN];
int n;


int kadane() {
        int ans = a[0], sum = 0;
        for(int i=0; i<n; i++) {
                sum += a[i];
                ans = max(ans, sum);
                sum = max(0LL, sum);
        }
        return ans;
}

int maxSumCircularSubarray() {
        int ans = kadane();

        /*  when part of the maxsum sub-array is suffix of the array and part is prefix of the subarray
        a[] = {4, 2, -6, 4, 3, -5, 2}  {4, 2, -6, 4, 3, -5, 2}
        maxsum subarray     -------------------

            so we find maximum prefix sum and maximum suffix sum - 
            because the subarray from end + subarray from beginning
            with maximum sum makes the maximum sum subarray
        */

        pre[0] = a[0];
        for(int i=1; i<n; i++) {
                pre[i] = pre[i-1] + a[i];
        }
        suf[n-1] = a[n-1];
        for(int i=n-2; i>=0; i--) {
                suf[i] = suf[i+1] + a[i];
        }

        // max prefix, suffix 
        for(int i=1; i<n; i++) {
                pre[i] = max(pre[i], pre[i-1]);
        }
        for(int i=n-2; i>=0; i--) {
                suf[i] = max(suf[i], suf[i+1]);
        }

        // max of prefix and suffix sum 
        // make sure array elements cannnot be repeated in the maxsum subarray
        /*
        max-pre[]            {4,  6,  6,  6,  7,  7,  7}
        max-suf[]       { 4,  4,  4,  4,  2,  2,  2}
        
        sum -                 10, 10, 10, 8,  9,  9   
        */

        for(int i=0; i<n-1; i++) {
                ans = max(ans, pre[i] + suf[i+1]);
        }
        return ans;
}

void solve() {
        cin >> n;
        for(int i=0; i<n; i++) {
                cin >> a[i];
        }
        cout << maxSumCircularSubarray() << "\n";
}

signed main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);     
        solve();
}





/*
Previoous version


#include<bits/stdc++.h>
using namespace std;

#define int long long int
const int mxN = 1e6+10;
int a[mxN], n, pre[mxN], suf[mxN];

int kadane() {                                  // simple kadane when maxsum can be found without a circular subarray
    int maxsum = 0, curr = 0;
    for(int i=0; i<n; i++) {
        if(curr + a[i] > 0) {
            curr += a[i];
            maxsum = max(maxsum, curr);
        } else {
            curr = 0;    
        }
    }
    return maxsum;
}

int minSumCircularArray() {             

    int maxsum = kadane();
    
    /*  when part of the maxsum sub-array is suffix of the array and part is prefix of the subarray
        a[] = {4, 2, -6, 4, 3, -5, 2}  {4, 2, -6, 4, 3, -5, 2}
    maxsum subarray     -------------------
    
        so we find maximum prefix sum and maximum suffix sum - 
        because the subarray from end + subarray from beginning
        with maximum sum makes the maximum sum subarray
    */

   // prefix, suffix sums
    pre[0] = a[0];                              
    for(int i=1; i<n; i++) 
        pre[i] = pre[i-1]+a[i];
    suf[n-1] = a[n-1];
    for(int i=n-2; i>=0; i--) 
        suf[i] = suf[i+1]+a[i];
    
    // max prefix , suffix
    for(int i=1; i<n; i++)
        pre[i] = max(pre[i], pre[i-1]);
    for(int i=n-2; i>=0; i--)
        suf[i] = max(suf[i], suf[i+1]);
 
    // max of prefix and suffix sum 
    // make sure array elements cannnot be repeated in the maxsum subarray
    /*
    max-pre[]            {4,  6,  6,  6,  7,  7,  7}
    max-suf[]       { 4,  4,  4,  4,  2,  2,  2}
    
    sum -                 10, 10, 10, 8,  9,  9   
    */
    for(int i=0; i<n-1; i++) 
        maxsum = max(maxsum, pre[i] + suf[i+1]);
    
    return maxsum;
}

void solve() {
    cin >> n;
    
    bool allneg = 1;
    int maxneg = INT_MIN;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        
        if(a[i] > 0)
            allneg = 0;
        maxneg = max(maxneg, a[i]);
    }
    
    if(allneg)                          // all negetive element case 
        cout << maxneg << "\n";
    else 
        cout << minSumCircularArray() << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
*/