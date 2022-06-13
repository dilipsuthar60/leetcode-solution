class Solution {
public:
    int minimumTotal(vector<vector<int>>&nums) 
    {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=n-1;~i;i--)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==n-1)
                {
                    dp[j]=nums[i][j];
                }
                else
                {
                    dp[j]=nums[i][j]+min(dp[j],dp[j+1]);
                }
            }
        }
        return dp.front();
    }
};