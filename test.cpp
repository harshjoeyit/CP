
 Source
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void  merge(vector<int>&v,vector<int >&leftV,vector<int >&rightV,vector<int >&col,vector<int >&leftcol,vector<int >&rightcol)
{
    int i,j,k;
    i=j=k=0;
    int ll = leftV.size();
    int rl = rightV.size();
    while(i<ll&&j<rl)
    {
        if(leftV[i] <= rightV[j])
        {
            col[k] = leftcol[i]; 
            v[k++] = leftV[i++];
        }
        else
        {
            col[k] = rightcol[j];
            v[k++] = rightV[j++];
        }
    }
    while(i<ll)
    {
        col[k] = leftcol[i]; 
        v[k++] = leftV[i++];
    }
    while(j<rl)
    {
        col[k] = rightcol[j];
        v[k++] = rightV[j++];
    }
 
}
 void merge_sort(vector<int>&v,vector<int>&col)
 {
	        int n = v.size();
	        if(n<2)
	            return;
	        int mid = n/2;
	        // for values
	        vector<int>leftV(mid);
	        vector<int>rightV(n-mid);
	        //for colour
	        vector<int>leftcol(mid);
	        vector<int>rightcol(n-mid);
	        //breaking 
	        for(int i =0;i<mid;i++)
	        {
	            leftV[i] = v[i];
	            leftcol[i] = col[i];
	        }
	        for(int i = mid;i<n;i++ )
	        {
	            rightV[i-mid] = v[i];
	            rightcol[i-mid] = col[i];
	        }
	        merge_sort(leftV,leftcol);
	        merge_sort(rightV,rightcol);
	        merge(v,leftV,rightV,col,leftcol,rightcol);
 
 }
 
signed main() 
{
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<int>v(n);w
	    vector<int>colour(n);
	    int colour_count[m];
	    int total = n/m;
	    int remain = n - total * m;
	    for(int i = 0;i<m;i++)
	    {
	    	if(i<remain)
	    		colour_count[i] = n/m + 1;
	    	else
	    		colour_count[i] = n/m;
	    }
	    //for(int i =0;i<m;i++)
	    //	cout<<colour_count[i]<<"  ";
 
	    unordered_map<int,int>particular_colour_count_map;
	    unordered_map<int,int>umap;
	    for(int i = 0;i<n;i++)
	    {
	        cin>>v[i];
	        colour[i] = i%m;
	    }
	    //sort(v.begin(),v.end());
	    merge_sort(v,colour);
	   // for(int i=0;i<n;i++)
		//	cout<<v[i]<<"   "<<colour[i]<<endl;
		//vector<vector<int>>store(m);
		int min = INT_MAX;
		int max_kaha_tak_jana_h = n;
		int one_time_move = 1;
		for(int i = 0;i<max_kaha_tak_jana_h;i++)
		{
			int j = i;
			int total_colour_count = 0;
			while(total_colour_count != m&&j<n)
			{
				if(umap[colour[j]] == 0)
					total_colour_count++;
				particular_colour_count_map[colour[j]]++;
				if(particular_colour_count_map[colour[j]] == colour_count[colour[j]]&&one_time_move)
				{
					max_kaha_tak_jana_h = j + 1;
					one_time_move = 0;
				}
				umap[colour[j]]++;
				j++;
			}
			int diff = v[j-1] - v[i];
			if(min>diff)
				min = diff;
			umap.clear();
		}
		cout<<min<<endl;
	}
	return 0;
}
 
