
#include<bits/stdc++.h>
using namespace std;
#define int long long 

class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, std::vector<int>, std::greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num)) firstQ.push(num); // if it belongs to the smaller half
        else secQ.push(num); 
        
        // rebalance the two halfs to make sure the length difference is no larger than 1
        if(firstQ.size() > secQ.size()+1) {
            secQ.push(firstQ.top());
            firstQ.pop();
        
        } else if(firstQ.size()+1 < secQ.size()) {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) {
            return firstQ.empty() ? 0 : ((firstQ.top()+secQ.top())/2.0);
        }
        return (firstQ.size() > secQ.size()) ? firstQ.top():secQ.top(); 
    }
};

/*
Follow up 

1. If all integer numbers from the stream are between 0 and 100, how would you optimize it?

We can maintain an integer array of length 100 to store the count of each number along with a 
total count. Then, we can iterate over the array to find the middle value to get our median.

*/