
#include<bits/stdc++.h> 
using namespace std; 
 
string multiply(string s1, string s2) 
{ 
	int n1 = s1.length(); 
	int n2 = s2.length(); 

	vector<int> result(n1 + n2, 0); 

	int i_n1 = 0; 
	int i_n2 = 0; 
	
	for (int i=n1-1; i>=0; i--) 
	{ 
		int carry = 0; 
		int n1 = s1[i] - '0'; 

		i_n2 = 0; 

		for (int j=n2-1; j>=0; j--) 
		{ 
			int n2 = s2[j] - '0'; 

			int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

			carry = sum/10; 

			result[i_n1 + i_n2] = sum % 10; 

			i_n2++; 
		} 

		if (carry > 0) 
			result[i_n1 + i_n2] += carry; 
		i_n1++; 
	} 

	// ignore '0's from the right 
	int i = result.size() - 1; 
	while (i>=0 && result[i] == 0) 
	i--; 

	// If all were '0's - means either both or 
	// one of s1 or s2 were '0' 
	if (i == -1) 
	return "0"; 

	// generate the result string 
	string s = ""; 
	
	while (i >= 0) 
		s += std::to_string(result[i--]); 

	return s; 
} 

string multiplyStrings(string s1, string s2) {
    
	if(s1.length() == 0 || s2.length() == 0)
		return 0;

    if(s1 == "0" || s2 == "0")
        return "0";
    
    if(s1[0] == '-' && s2[0] == '-')
        return multiply(s1.substr(1), s2.substr(1));
    else if(s1[0] == '-') 
        return ('-' + multiply(s1.substr(1), s2));
    else if(s2[0] == '-') 
        return ('-' + multiply(s1, s2.substr(1)));
    
    return multiply(s1, s2);
}

// Driver code 
int main() 
{ 
	string str1 = "-1235421415454545454545454544"; 
	string str2 = "1714546546546545454544548544544545"; 
	
	cout << multiplyStrings(str1, str2) << "\n";


	str1 = "0"; 
	str2 = "125"; 
	
	cout << multiplyStrings(str1, str2) << "\n";


	str1 = "-000254"; 
	str2 = "-21"; 
	
	cout << multiplyStrings(str1, str2) << "\n";
} 
