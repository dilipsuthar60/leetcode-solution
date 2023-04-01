class Solution {
public:
    int mod=1e9+7;
    long long dp[52][1050];
    long long find(vector<vector<int>>&nums,int index,int target)
    {
        if(index>=nums.size()||target<0)
        {
            return target==0;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target]%mod;
        }
        long long ans=find(nums,index+1,target);
        for(int i=0;i<nums[index][0];i++)
        {
            if(target-(i+1)*nums[index][1]>=0)
            {
                ans+=find(nums,index+1,target-(i+1)*nums[index][1]);
            }
            else
            {
                 break;
            }
        }
        return dp[index][target]= ans%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return find(types,0,target)%mod;
    }
};