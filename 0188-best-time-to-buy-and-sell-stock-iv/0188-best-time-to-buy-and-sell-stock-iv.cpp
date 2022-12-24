class Solution {
public:
    int dp[1005][2][101];
    int find(vector<int>&nums,int index,int b,int k)
    {
        if(index>=nums.size()||k<=0)
        {
            return 0;
        }
        if(dp[index][b][k]!=-1)
        {
            return dp[index][b][k];
        }
        int ans=0;
        if(b)
        {
            int first=-nums[index]+find(nums,index+1,0,k);
            int second=find(nums,index+1,1,k);
            ans=max(first,second);
        }
        else
        {
            int first=nums[index]+find(nums,index+1,1,k-1);
            int second=find(nums,index+1,0,k);
            ans=max(first,second);
        }
        return dp[index][b][k]= ans;
    }
    int maxProfit(int k, vector<int>& prices) {
       memset(dp,-1,sizeof(dp));
        return find(prices,0,1,k);
    }
};