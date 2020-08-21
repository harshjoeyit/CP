#include <bits/stdc++.h>
using namespace std;

// Method 1:
int lengthOfLongestSubstring(string s)
{
	int n = (int)s.length();
	int l = 0, maxL = 0;
	// stores the index of the char
	unordered_map<char, int> ump;

	for (int i = 0; i < n; i++)
	{
		if (ump.count(s[i]))
		{
			// if char is already in the window
			// then start of the window moves to the next index
			// of index of prev occurance of this char,
			// while moving left pointer, also check if left
			// is already greater than the new window left

			// example test case for this is
			// abbabba, l is already at 2, when second occurnace of a
			// is seen and, it moves left to 1, but the left is already at 2
			// becasue of b, so we choose the maximum one

			l = max(l, ump[s[i]] + 1);
		}
		// store the char index
		ump[s[i]] = i;
		// calc max
		maxL = max(maxL, i - l + 1);
	}

	return maxL;
}

// method 2:

int lengthOfLongestSubstring(string s)
{
	int n = (int)s.length();
	int i = 0, j = 0, maxL = 0;
	unordered_set<char> st;

	// there is a duplicate in the window 
	// so erase the starting char of window and move to next char
	// this else condition will run untill 
	// the the duplicate is erased 
	// then the if condition is true and new window is created
	// try using same example test case 

	while (i < n && j < n)
	{
		if (st.count(s[j]) == 0)
		{
			// window is [i...j]
			st.insert(s[j]);
			maxL = max(maxL, j - i + 1);
			j += 1;
		}
		else
		{ 
			st.erase(s[i]);
			i += 1;
		}
	}

	return maxL;
}