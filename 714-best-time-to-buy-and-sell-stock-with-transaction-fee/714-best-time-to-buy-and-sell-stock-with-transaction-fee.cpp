class Solution {
public:
    int dp[60000][2];
    int find(vector<int>&nums,int index,int fee,int buy)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int ans=0;
        if(buy)
        {
            ans=max(-nums[index]+find(nums,index+1,fee,0),find(nums,index+1,fee,1));
        }
        else
        {
            ans=max(nums[index]-fee+find(nums,index+1,fee,1),find(nums,index+1,fee,0));
        }
        return dp[index][buy]=ans;
    }
    int maxProfit(vector<int>& nums, int fee) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,fee,1);
    }
};