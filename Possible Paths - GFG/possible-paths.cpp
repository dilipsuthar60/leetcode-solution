//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
	public:
	int ans=0;
	int find(vector<int>&parent,int x)
	{
	    if(x==parent[x])
	    {
	        return x;
	    }
	    return parent[x]=find(parent,parent[x]);
	}
	int merge(vector<int>&parent,vector<int>&rank,int x,int y)
	{
	    x=find(parent,x);
	    y=find(parent,y);
	    if(x==y)
	    {
	        return rank[x]*rank[y];
	    }
	     ans+=rank[x]*rank[y];
	    if(rank[x]<rank[y])
	    {
	        rank[y]+=rank[x];
	        parent[x]=y;
	    }
	    else
	    {
	        rank[x]+=rank[y];
	        parent[y]=x;
	    }
	    return ans;
	}
	vector<int> maximumWeight(int n, vector<vector<int>>nums, int Q, vector<int> &q)
	{
	    vector<int>parent(n+1),rank(n+1,1);
	    iota(parent.begin(),parent.end(),0);
	    sort(nums.begin(),nums.end(),[&](auto &a,auto &b){return a[2]<b[2];});
	    map<int,int>mp;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp[nums[i][2]]=merge(parent,rank,nums[i][0],nums[i][1]);
	    }
	    vector<int>ans;
	    for(auto val:q)
	    {
	        auto it=mp.upper_bound(val);
	        if(it==mp.begin())
	        {
	            ans.push_back(0);
	        }
	        else
	        {
	            it--;
	            ans.push_back(it->second);
	        }
	    }
	    return ans;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends