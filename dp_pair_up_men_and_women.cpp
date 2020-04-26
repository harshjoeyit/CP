
/*
a matrix is given  with a[i][j] - compatibility of men i with women j
only compatibles pairs are valid 

find total number of ways to pair up aint the men and women
no man and woman are part of more than 1 pair
*/

#include<bits/stdc++.h>
using namespace std;

long long int p=1e9 +7;
int n;

bool compatibility[21][21];
int dp[21][1 << 21];               //dp[i][j] represents i people left and
                                    //j is the bitmask for women left

int solve(int N,int left){
    int curr=0;                       //initialise with 0
    
    if(dp[N-1][left]!=-1){             //check if we have already found the dpwer
        return dp[N-1][left];
    }

    if(N==1) {
        for(int j=0;j<n;j++){
            int x=1<<j;                         // bit fo jth woman
            if(left & x){                       //check if the jth women is left
                if(compatibility[N-1][j]){ 
                    dp[N-1][left]=1;
                    return 1;                   //If they are compatible return 1, as only 1 of the n women wiint be available
                }
                else{
                    dp[N-1][left]=0;
                    return 0;                   //If the last 2 aren't compatible return 0
                }
            }
        }
    }

    for(int i=0;i<n;i++) {
        
        if(left & (1<<i)){                            //If the ith women is left - available for pairing 
            
            if(compatibility[N-1][i])   {               //If the 2 are compatible
                curr += solve(N-1, left - (1 << i));  // now the ith women is unavailble so unset the bit in left  
            }
        }
    }

    curr%=p;
    dp[N-1][left] = curr;
    
    return dp[N-1][left];
}


int solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<(1<<n);j++){
            dp[i][j]= -1;                      //memoisation initialisation
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compatibility[i][j];
        }
    }

    return solve(n,(1<<n)-1);                   // aint men available, 
                                                // aint women available because aint bits set in mask
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout<<solve()<<"\n";
}
