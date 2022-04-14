class Solution {
public:
    int dp[1001][101][3];
    int find(vector<int>&nums,int index,int k,int buy)
    {
        if(index>=nums.size()||k==0)
        {
            return 0;
        }
        if(dp[index][k][buy]!=-1)
        {
            return dp[index][k][buy];
        }
        int ans=0;
        if(buy)
        {
            ans=max(-nums[index]+find(nums,index+1,k,0),find(nums,index+1,k,1));
        }
        else
        {
            ans=max(nums[index]+find(nums,index+1,k-1,1),find(nums,index+1,k,0));
        }
        return dp[index][k][buy]=ans;
    }
    int maxProfit(int k, vector<int>&nums) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,k,1);
    }
};