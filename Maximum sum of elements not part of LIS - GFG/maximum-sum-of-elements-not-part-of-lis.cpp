// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSumLis(int arr[], int n) 
    {
        int dp[n][2];
        memset(dp,0,sizeof(dp));
        int max_lis=1;
        for(int i=0;i<n;i++)
        {
            dp[i][0]=1;
            dp[i][1]=arr[i];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            for(int j=0;j<i;j++)
            {
                if(arr[j]<arr[i])
                {
                if(dp[i][0]<dp[j][0]+1)
                {
                    dp[i][0]=dp[j][0]+1;
                    dp[i][1]=arr[i]+dp[j][1];
                }
                else if(dp[i][0]==dp[j][0]+1)
                {
                    dp[i][1]=min(dp[i][1],dp[j][1]+arr[i]);
                }
                  max_lis=max(max_lis,dp[i][0]);
                }
            }
        }
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            if(dp[i][0]==max_lis)
            {
                ans=min(dp[i][1],ans);
            }
        }
        return sum-ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int Arr[n];
        for (int i = 0; i < n; i++) cin >> Arr[i];
        Solution obj;
        cout << obj.maxSumLis(Arr, n) << endl;
    }
    return 0;
}  // } Driver Code Ends