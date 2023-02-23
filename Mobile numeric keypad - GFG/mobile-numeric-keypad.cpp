//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long dp[26][11];
	vector<vector<int>>b={{0,8},{1,2,4},{2,1,3,5},{3,2,6},{1,4,5,7},{5,2,4,6,8},{6,3,9,5},{7,4,8},{8,0,7,9,5},{9,8,6}};
	long long find(int index,int prev,int n)
	{
	    if(index==n)
	    {
	        return 1;
	    }
	    if(dp[index][prev]!=-1)
	    {
	        return dp[index][prev];
	    }
	   long long ans=0;
	    for(auto it:b[prev])
	    {
	        ans+=find(index+1,it,n);
	    }
	    return dp[index][prev]= ans;
	}
	long long getCount(int N)
	{
	    memset(dp,-1,sizeof(dp));
	    long long ans=0;
	    for(int i=0;i<=9;i++)
	    {
	        ans+=find(1,i,N);
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends