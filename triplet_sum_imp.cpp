#include <bits/stdc++.h>
using namespace std;

// find maximum triplet sum (a[i] + a[j] + a[k]) satisying 
// all are distinct 
// i < j < k

int maxTripletSum(vector<int> &a) {
	int n = a.size();
	vector<int> maxRight(n);

	// store the max element from the right 
	maxRight[n-1] = a[n-1];
	for(int i=n-2; i>=0; i--) {
		maxRight[i] = max(maxRight[i+1], a[i]);		
	}

	set<int> st;
	st.insert(a[0]);
	int ans = 0;

	for(int i=1; i<n-1; i++) {
		// store the elements in the set 
		st.insert(a[i]);

		if(maxRight[i+1] <= a[i]) {
			// no element tp the right is greater
			continue;
		}

		auto it = st.lower_bound(a[i]);
		
		if(it == st.begin()) {#
			// no element smaller exist 
			continue;
		}

		// *it is the max elements just smaller than a[i]
		--it;

		// found the triplet t
		int s = *it + a[i] + maxRight[i+1];
		ans = max(ans, s);
	}

	return ans;
}

int main() {
	vector<int> a = {32225, 3197, 6850, 24024, 13913, 17724, 5715, 5372, 16809, 1621, 18982, 13157, 23299, 30150, 32146, 30498, 19467, 27444, 19449, 26393, 13532, 10205, 19696, 27295, 5451, 19150, 1952, 32582, 31599, 21846, 13676, 246, 31585, 21434, 6101, 14400, 21568, 32298, 26010, 8942, 26232, 26100, 4899, 10975, 24388, 760, 31263, 16146, 15730, 13660, 9325, 768, 4967, 3969, 15928, 2095, 10850, 31797, 29543, 17924, 27397, 5418, 15412, 17369, 12049, 15782, 23834, 10575, 24689, 21885, 7669, 10469, 2426, 6205, 31845, 30922, 14961, 31912, 23923, 19952, 26701, 10343, 631, 3426, 10431, 19452, 17721, 10199, 28528, 31481, 24406, 21383, 12426, 21615, 16613, 6205, 3193, 4010, 14939, 25006, 26867, 16667};
	cout << maxTripletSum(a) << endl;
}