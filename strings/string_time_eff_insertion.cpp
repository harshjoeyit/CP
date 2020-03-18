#include <iostream>
#include <string>
#include <chrono>
using namespace std;
 
const int N = 100000;
 
void add1(string &b) {
	int diff = (N - (int)b.length());
	for (int i = 0; i < diff; ++i) {
		b = '0' + b;
	}       
	return;
}
 
void add2(string &b) {
	int diff = (N - (int)b.length());
    // function signature -                 
    // str.insert(start, no_of_times, char);
	b.insert(b.begin(), diff, '0');         //  str1.insert(0, diff, '$'); 
	return;
}
 
int main() {
	string b = "1";
	chrono::system_clock::time_point start, end;
 
 
	// first method
	start = chrono::system_clock::now();
	add1(b);
	end = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << "add1: " << duration.count() << endl;
 
 
	b = "1";
 
	// second method
	start = chrono::system_clock::now();
	add2(b);
	end = chrono::system_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << "add2: " << duration.count() << endl;
 
	return 0;
}