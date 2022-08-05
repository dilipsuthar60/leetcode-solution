class Solution {
public:
    int dp[1001][201];
    int f=0;
    int combinationSum4(vector<int>& nums,int target,int index=0) 
    {
        if(f==0)
        {
            memset(dp,-1,sizeof(dp));
            f=1;
        }
       if(index>=nums.size()||target<0)
       {
           return target==0;
       }
        if(dp[target][index]!=-1)
        {
            return dp[target][index];
        }
       return dp[target][index]=combinationSum4(nums,target,index+1)+combinationSum4(nums,target-nums[index],0);
    }
};