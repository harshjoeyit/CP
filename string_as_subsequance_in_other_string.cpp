#include <bits/stdc++.h> 
using namespace std; 

bool isSubSequence(string sub, string str)  { 
	int m = sub.length(), n = str.length(); 
	int j = 0; 
    // ex-  str -"abpcplea" , sub - "apple" 
	for (int i=0; i<n && j<m; i++) 
		if (sub[j] == str[i]) 
			j++;                        // inc if matched, else inc in str only

	return (j==m);     // sub found in str
} 

int main() 
{ 
	cout << isSubSequence("apple", "abpcplea") << "\n";
    cout << isSubSequence("orange", "sporauungtte") << "\n";
    cout << isSubSequence("pie", "plea") << "\n";
	return 0; 
} 
