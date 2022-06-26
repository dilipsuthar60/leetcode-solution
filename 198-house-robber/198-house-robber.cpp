class Solution {
public:
    int rob(vector<int>& nums)    
    {
        int n=nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                dp[i]=nums[i];
            }
            else if(i==1)
            {
                dp[i]=max(nums[i],nums[i-1]);
            }
            else
            {
                dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            }
        }
        return dp[n-1];
    }
};