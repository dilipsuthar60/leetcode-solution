//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int dp[110][110];
	int find(int n,int m)
	{
	    if(n==m)
	    {
	        return 1;
	    }
	    if(n<0||m<0)
	    {
	        return 1e9;
	    }
	    if(dp[n][m]!=-1)
	    {
	        return dp[n][m];
	    }
	    int ans=1e9;
	    for(int i=1;i<n;i++)
	    {
	        ans=min(ans,find(i,m)+find(n-i,m));
	    }
	    for(int i=1;i<m;i++)
	    {
	        ans=min(ans,find(n,i)+find(n,m-i));
	    }
	    return dp[n][m]= ans;
	}
	int minCut(int n, int m)
	{
	    memset(dp,-1,sizeof(dp));
	    return find(n,m);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;

	    

	    Solution ob;
	    cout << ob.minCut(m, n) << "\n";

	     
    }
    return 0;
}

// } Driver Code Ends