#include<bits/stdc++.h>
using namespace std;

/*
copies of m books needs to be made by k workers 
Number of pages of each book is given given a book cannot be shared among workers 
distribute the work in the workers so the maximum pages on one worker is minimum
also continuous set of books is alottted to a worker 
if more than one solution is possible the the ans is the one where the first worker has the mininmum work
Eg.
5 3
1 2 3 4 5 6 7 8 9
ans
1 2 3 4 5 / 6 7 / 8 9

5 4
1 1 1 1 1
1 / 1 / 1 / 1 1
*/

int main() {
    int n;
    cin >> n;

    while(n--) {
        int m, k, x, Max = INT_MIN, sum = 0;
        cin >> m >> k;
        vector<int> book_pages(m+2);

        for(int i = 1; i <= m; i++) {
            cin >> x;
            book_pages[i] = x;
            Max = max(x, Max);
            sum += x;
        }

        // Note: l, h
        int l = Max, h = sum, part, currsum, mid;

        while(l < h) {
            part = 1;
            currsum = 0;
            mid = l + (h-l)/2;

            for(int i = m; i >= 1; i--) {
                if(book_pages[i] + currsum > mid) {
                    ++part;
                    currsum = book_pages[i];
                }
                else
                    currsum += book_pages[i];
            }

            if(part <= k)
                h = mid;
            else
                l = mid + 1;
        }

        vector<int> slashes;
        int placed = 1;
        currsum = 0;

        for(int i = m; i >= 1; i--) {
            if( (currsum + book_pages[i] <= l) && ((i-1) > (k-1-placed)))
                currsum += book_pages[i];
            else
            {
                currsum = book_pages[i];
                ++placed;
                slashes.push_back(i);
            }
        }

        int j = slashes.size() - 1;
        for(int i = 1; i <= m; i++)
        {
            cout << book_pages[i] << " ";
            if( (j >= 0) && (i == slashes[j]) )
            {
                cout << "/ ";
                j--; 
            }
        }
        cout << endl;
    }
}