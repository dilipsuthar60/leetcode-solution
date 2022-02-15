class Solution {
public:
    int dp[13][10005];
    int find(vector<int>&nums,int index,int target)
    {
        if(index>=nums.size())
        {
            return INT_MAX/2;
        }
        if(target<0)
        {
            return INT_MAX/2;
        }
        if(target==0)
        {
            return 0;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int ans=INT_MAX/2;
        for(int i=index;i<nums.size();i++)
        {
            if(target-nums[i]>=0)
            ans=min(ans,1+find(nums,i,target-nums[i]));
        }
        return dp[index][target]=ans;
    }
    int coinChange(vector<int>& coins, int x) 
    {
        memset(dp,-1,sizeof(dp));
        int val=find(coins,0,x);
        return (val==INT_MAX/2)?-1:val;
    }
};