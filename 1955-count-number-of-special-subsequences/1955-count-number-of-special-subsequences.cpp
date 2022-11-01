class Solution {
public:
    int mod=1e9+7;
    long long dp[100005][5];
    int find(vector<int>&nums,int index,int prev)
    {
        if(index>=nums.size())
        {
            return prev==2;
        }
        if(dp[index][prev+1]!=-1)
        {
            return dp[index][prev+1]%mod;
        }
        int ans=find(nums,index+1,prev);
        if(prev==nums[index])
        {
            ans+=find(nums,index+1,nums[index]);
        }
        else if(prev+1==nums[index])
        {
            ans+=find(nums,index+1,nums[index]);
        }
        return dp[index][prev+1]=ans%mod;
    }
    int countSpecialSubsequences(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,-1)%mod;
    }
};