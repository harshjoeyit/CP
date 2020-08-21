// IMP: PIR
// maximum value lexiographically for an array of string of number

#include <bits/stdc++.h>
using namespace std;

string toString(int val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

string largestNumber(vector<int> &nums) {
    int i;
    for (i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            break;
        }
    }
    if (i == nums.size()) {
        return "0";
    }

    string ans = "";
    vector<string> nums1;

    for (auto &num : nums) {
        nums1.push_back(toString(num));
    }
    auto comp = [](const string &a, const string &b) {
        return (a + b > b + a);
    };

    sort(nums1.begin(), nums1.end(), comp);
    for (auto &num : nums1) {
        ans += num;
    }
    return ans;
}

int main() {
    // NOTE : if the numbers are already given as strings then 
    // we just need the comparitor function and nothing else
    // note no function can be called inside a lambda function 
    // gives error 
    // so convert the int vector to string vector then apply the same concept 
}