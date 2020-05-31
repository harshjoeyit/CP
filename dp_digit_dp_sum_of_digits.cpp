// DIGIT DP:
/*
    Given two integers a and b. The task is to print 
    sum of all the digits appearing in the 
    integers between a and b 

    for divisibility problems like find how many numbers whose sum is divisible by k
    use the base case as -

    if(idx == -1) {
        if(sum % k == 0)
            return 1;
        else
            return 0;
    }

    similarly divisibility of 9 and 3 can also be checked
*/


#include<bits/stdc++.h>
using namespace std;

int dp[20][180][2];     // dp(idx, tight, sum) - is dp state (index, bound for digit value, sum of digit from MSD to indx)

void get_digits(int x, vector<int> &digit) {
    while(x) {
        digit.push_back(x%10);
        x = x/10;
    }
}

int digit_sum(int idx, int sum, int tight, vector<int> &digit ) {
    if(idx == -1)
        return sum;
    
    if(dp[idx][sum][tight] != -1 and tight != 1)
        return dp[idx][sum][tight];

    int ret = 0;
    int k = (tight)? digit[idx]: 9;

    for(int i=0; i<=k; i++) {
        int newTight = (digit[idx] == i)?tight:0;

        ret += digit_sum(idx-1, sum+i, newTight, digit);            // ans from next state 
    } 
    if(!tight) {
        dp[idx][sum][tight] = ret;
    }
    return ret;
}

int range_digit_sum(int a, int b) {
    memset(dp, -1, sizeof(dp));

    vector<int> digitA;
    get_digits(a-1, digitA);

    // finding sum from 1 to a-1
    int ans1 = digit_sum(digitA.size()-1, 0, 1, digitA); 

    vector<int> digitB;
    get_digits(b, digitB);

    int ans2 = digit_sum(digitB.size()-1, 0, 1, digitB);
    
    return (ans2 - ans1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a = 1, b = 25; 
    // cout << "digit sum for given range : "
         cout << range_digit_sum(a, b) << endl; 
}


