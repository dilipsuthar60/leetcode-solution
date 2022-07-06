// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int n;
	vector<vector<long long>>dp;
	int mod=1e9+7;
	int find(int arr[],int index,int sum)
	{
	    if(index==n)
	    {
	        return sum==0;
	    }
	    if(sum<0) return 0;
	    if(dp[index][sum]!=-1)
	    {
	       return dp[index][sum]%mod;
	    }
	    return dp[index][sum]=(find(arr,index+1,sum-arr[index])%mod+find(arr,index+1,sum)%mod)%mod;
	}
	int perfectSum(int arr[], int N, int sum)
	{
	    dp=vector<vector<long long>>(N+1,vector<long long>(sum+1,-1));
	     n=N;
	    return find(arr,0,sum)%mod;
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends