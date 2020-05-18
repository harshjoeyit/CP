
/*
std::chrono has two distinct objects–timepoint and duration. 
A timepoint as the name suggests represents a point in time whereas a duration represents an interval or span of time.
The C++ library allows us to subtract two timepoints to get the interval of time passed in between.
Using provided methods we can also convert this duration to appropriate units.
The std::chrono provides us with three clocks with varying accuracy.
The high_resolution_clock is the most accurate and hence it is used to measure execution time.
*/

#include <algorithm> 
#include <chrono> 
#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
  
void measure_algo_time(vector<int> &values) {
    // put the algo here 
    sort(values.begin(), values.end());
}
  
// For demonstration purpose, we will fill up 
// a vector with random integers and then sort 
// them using sort function. We fill record 
// and print the time required by sort function 
int main() 
{ 
  
    vector<int> values(2000000); 
  
    // Generate Random values 
    auto f = []() -> int { return rand() % 10000; }; 
  
    generate(values.begin(), values.end(), f); 
  
    auto start = high_resolution_clock::now(); 
  
    // put Algorithm in this function
    measure_algo_time(values);
  
    auto stop = high_resolution_clock::now(); 
  
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << static_cast<double>( duration.count() ) /1000 << " ms" << endl; 
  
    return 0; 
} 