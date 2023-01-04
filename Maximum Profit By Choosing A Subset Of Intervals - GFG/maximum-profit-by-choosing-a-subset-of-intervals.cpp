//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[1]<v2[1];
    }
    int maximum_profit(int n, vector<vector<int>> &nums) 
    {
        sort(nums.begin(),nums.end(),cmp);
        vector<int>dp(n,-1e9);
        dp[0]=nums[0][2];
        for(int i=1;i<n;i++)
        {
            int s=nums[i][0];
            int e=nums[i][1];
            int cost=nums[i][2];
            int l=0;
            int r=i-1;
            int index=-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(nums[mid][1]<=s)
                {
                    index=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            if(index!=-1)
            {
                cost+=dp[index];
            }
            dp[i]=max(dp[i-1],cost);
        }
       
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends