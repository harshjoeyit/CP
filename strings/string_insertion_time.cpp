#include <iostream>
#include <string>
#include <chrono>
using namespace std;
 
const int N = 100000;
 
void add1() {
	string b = "";
	for (int i = 0; i < N; ++i) {
		b = '0' + b;
	}       
	return;
}
 
void add2() {
	string b = "";
    	// function signature -                 
    	// str.insert(start, no_of_times, char);
	b.insert(b.begin(), N, '0');         //  str1.insert(0, diff, '$'); 
	return;
}

void add3() {
	string b;
	for(int i=0; i<N; i++) {
		b.push_back('a');
	}
}
 
int main() 
	chrono::system_clock::time_point start, end;
 
 
	// first method
	start = chrono::system_clock::now();
	add1();
	end = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << "add1: " << duration.count() << endl;
 

	// second method
	start = chrono::system_clock::now();
	add2();
	end = chrono::system_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << "add2: " << duration.count() << endl;

	// third method
	start = chrono::system_clock::now();
	add3();
	end = chrono::system_clock::now();
	duration = chrono::duration_cast<chrono::microseconds>(end-start);
	cout << "add3: " << duration.count() << endl;
 
	return 0;
}