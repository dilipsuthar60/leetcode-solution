class Solution {
public:
    int lastStoneWeightII(vector<int>&nums)
    {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
         int ans=INT_MAX;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(j-nums[i-1]>=0)
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
                if(dp[n][j])
                ans=min(ans,abs(sum-2*j));
            }
        }
        return ans;
    }
};