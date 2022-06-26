class Solution {
public:
    int dp[200];
    int find(vector<int>&nums,int n,int index)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int include=nums[index]+find(nums,n,index+2);
        int exclude=0+find(nums,n,index+1);
        return dp[index]=max(include,exclude);
    }
    int rob(vector<int>& nums)    
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,(int)nums.size(),0);
    }
};