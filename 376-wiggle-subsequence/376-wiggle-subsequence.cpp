class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n][2];
        //0 up
        // 1 down  
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                dp[i][0]=dp[i-1][1]+1;
                dp[i][1]=dp[i-1][1];
            }
            else if(nums[i-1]>nums[i])
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][0]+1;
            }
            else
            {
                dp[i][0]=dp[i-1][0];
                dp[i][1]=dp[i-1][1];
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};