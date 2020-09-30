
/*
Finding the repeated elements in O(n) time, O(1) space 

number of elements = n
range of elements - [0, n-1]
*/

#include<bits/stdc++.h>
using namespace std;

/*
Approach: The basic idea is to use a HashMap to solve 
the problem. But there is a catch, the numbers in the 
array are from 0 to n-1, and the input array has length 
n. So, the input array can be used as a HashMap. While 
traversing the array, if an element a is encountered 
then increase the value of a%n‘th element by n. The 
frequency can be retrieved by dividing the a%n‘th 
element by n.
*/

void dups(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int rem = a[i] % n;
        a[rem] += n;
    }

    for (int i = 0; i < n; i++) {
        if(a[i]/n > 1) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
    dups(a);
}
