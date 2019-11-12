//std::chrono has two distinct objects–timepoint and duration. 
//A timepoint as the name suggests represents a point in time whereas a duration represents an interval or span of time.
//The C++ library allows us to subtract two timepoints to get the interval of time passed in between.
 //Using provided methods we can also convert this duration to appropriate units.
//The std::chrono provides us with three clocks with varying accuracy.
// The high_resolution_clock is the most accurate and hence it is used to measure execution time.



// C++ program to find out execution time of 
// of functions 
#include <algorithm> 
#include <chrono> 
#include <bits/stdc++.h>
using namespace std; 
using namespace std::chrono; 
  
// For demonstration purpose, we will fill up 
// a vector with random integers and then sort 
// them using sort function. We fill record 
// and print the time required by sort function 
int main() 
{ 
  
    vector<int> values(10000); 
  
    // Generate Random values 
    auto f = []() -> int { return rand() % 10000; }; 
  
    // Fill up the vector 
    generate(values.begin(), values.end(), f); 
  
    // Get starting timepoint 
    auto start = high_resolution_clock::now(); 
  
    // Call the function, here sort() 
    sort(values.begin(), values.end()); 
  
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << static_cast<double>( duration.count() ) /1000000 << " seconds" << endl; 
  
    return 0; 
} 