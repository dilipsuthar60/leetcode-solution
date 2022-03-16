// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:

		int DivisibleByM(vector<int>nums, int m)
		{
		    int n=nums.size();
		    int target=accumulate(nums.begin(),nums.end(),0);
		    int dp[n+1][target+1];
		    memset(dp,0,sizeof(dp));
		    for(int i=0;i<=n;i++)
		    dp[i][0]=1;
		    for(int i=1;i<=n;i++)
		    {
		        for(int j=1;j<=target;j++)
		        {
		            dp[i][j]=dp[i-1][j];
		            if(j-nums[i-1]>=0)
		            {
		                dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
		            }
		        }
		    }
		    for(int i=1;i<=target;i++)
		    {
		        if(dp[n][i]&&i%m==0)
		        {
		            return 1;
		        }
		    }
		    return 0;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.DivisibleByM(nums, m);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends