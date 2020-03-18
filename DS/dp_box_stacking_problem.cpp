#include<bits/stdc++.h>
using namespace std;

struct Box
{
    int h, w, d;
};

bool comp(Box &a, Box &b)
{
    return (b.d * b.w < a.d * a.w); 
}

int maxStackHeight(Box arr[], int n)
{
    Box rot[3*n];
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        // Copy the original box 
        rot[index].h = arr[i].h; 
        rot[index].d = max(arr[i].d, arr[i].w); 
        rot[index].w = min(arr[i].d, arr[i].w); 
        index++; 

        // First rotation of box 
        rot[index].h = arr[i].w; 
        rot[index].d = max(arr[i].h, arr[i].d); 
        rot[index].w = min(arr[i].h, arr[i].d); 
        index++; 
    
        // Second rotation of box 
        rot[index].h = arr[i].d; 
        rot[index].d = max(arr[i].h, arr[i].w); 
        rot[index].w = min(arr[i].h, arr[i].w); 
        index++;
    }

    n = 3*n;

    sort(rot, rot + n, comp);

    // for (int i = 0; i < n; i++ ) 
    //     printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d); 
  
    int dp[n];
    for(int i = 0; i < n; i++)
        dp[i] = rot[i].h;

    int maxh = -1;
    for(int i = 1; i < n; i++)
    {
        int h = 0;
        for(int j = 0; j < i; j++)      // larger boxes shoould lower and smaller up
            if((rot[j].d > rot[i].d) && (rot[j].w > rot[i].w) && (dp[j] + rot[i].h > dp[i]))
                dp[i] = dp[j] + rot[i].h;
        
        if(dp[i] > maxh)
            maxh = dp[i];
    }
    
    return maxh;
}

int main() 
{ 
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
  int n = sizeof(arr)/sizeof(arr[0]); 
  
  printf("The maximum possible height of stack is %d\n", 
         maxStackHeight (arr, n) ); 
  
  return 0; 
} 