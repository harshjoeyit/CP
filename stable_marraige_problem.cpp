// C++ program for stable marriage problem 
#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 

// Number of Men or Women 
#define N 4 

// This function returns true if woman 'w' prefers man 'currEng' over man 'm' 
bool wPrefersCurrEngOverNewEng(int prefer[2*N][N], int w, int newEng, int currEng) 
{ 
	// Check if w prefers m over her current engagment currEng 
	for (int i = 0; i < N; i++) 
	{ 
		/*
		If currEng comes before newEng in preference list of w, then w prefers her 
		current engagement, don't do anything 
		*/
		if (prefer[w][i] == currEng) 
			return true; 
		/*
		If newEng cmes before currEng in w's list, then free her current 
		engagement and engage her with m 
		*/
		if (prefer[w][i] == newEng) 
			return false; 
	} 
    return false;
} 

/*
Prints stable matching for N boys and N girls. Boys are numbered as 0 to 
N-1. Girls are numbereed as N to 2N-1.
*/ 
void stableMarriage(int prefer[2*N][N]) 
{ 
	/*
	Stores partner of women. This is our output array that 
	stores paing information. The value of wPartner[i] 
	indicates the partner assigned to woman N+i. Note that 
	the woman numbers between N and 2*N-1. The value -1 
	indicates that (N+i)'th woman is free 
	*/
	int wPartner[N]; 

	/*
	An array to store availability of men. If mFree[i] is 
	false, then man 'i' is free, otherwise engaged. 
	*/
	bool mFree[N]; 

	// Initialize all men and women as free 
	memset(wPartner, -1, sizeof(wPartner)); 
	memset(mFree, false, sizeof(mFree)); 
	int freeCount = N; 

	// While there are free men 
	while (freeCount > 0) 
	{ 
		// Pick the first free man (we could pick any) 
		int m; 
		for (m = 0; m < N; m++) 
			if (mFree[m] == false) 
				break; 

		/*
		One by one go to all women according to m's preferences. 
		Here m is the picked free man 
		*/
		for (int i = 0; i < N && mFree[m] == false; i++) 
		{ 
			int w = prefer[m][i]; 

			/*
			The woman of preference is free, w and m become 
			partners (Note that the partnership maybe changed 
			later). So we can say they are engaged not married :-p
			*/
			if (wPartner[w-N] == -1) 
			{ 
				wPartner[w-N] = m; 
				mFree[m] = true; 
				freeCount--; 
			} 
			else // If w is not free 
			{ 
				// Find current engagement of w 
				int currEng = wPartner[w-N]; 

				/*
				If w prefers m over her current engagement currEng, 
				then break the engagement between w and currEng and 
				engage m with w. 
				*/
				if (wPrefersCurrEngOverNewEng(prefer, w, m, currEng) == false) 
				{ 
					wPartner[w-N] = m; 
					mFree[m] = true; 
					mFree[currEng] = false; 
				} 
			}  
		} // End of the for loop that goes to all women in m's list 
	} // End of main while loop 


	// Print the Stable Arrangement 
	cout << "W  M" << endl; 
	for (int i = 0; i < N; i++) 
	cout << i+N << "  " << wPartner[i] << endl; 
} 


int main() 
{ 
	// Here 0,1,2,3, are Men
	// and  4,5,6,7 are Women
	/*
		Mens preference list 
		{7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 

		Women's Preference list 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
	*/
	int prefer[2*N][N] = { 
		{7, 5, 6, 4}, 
		{5, 4, 6, 7}, 
		{4, 5, 6, 7}, 
		{4, 5, 6, 7}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
		{0, 1, 2, 3}, 
	}; 
	stableMarriage(prefer); 

	return 0; 
} 
