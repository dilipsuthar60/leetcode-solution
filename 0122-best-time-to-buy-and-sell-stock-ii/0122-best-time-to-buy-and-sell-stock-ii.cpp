class Solution {
public:
    int dp[100004][2];
    int find(vector<int>&nums,int index,int buy)
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
            ans=max(-nums[index]+find(nums,index+1,0),find(nums,index+1,1));
        }
        else
        {
            ans=max(+nums[index]+find(nums,index+1,1),find(nums,index+1,0));
        }
        return dp[index][buy]= ans;
    }
    int maxProfit(vector<int>& prices) 
    {
        memset(dp,-1,sizeof(dp));
        return find(prices,0,1);
    }
};