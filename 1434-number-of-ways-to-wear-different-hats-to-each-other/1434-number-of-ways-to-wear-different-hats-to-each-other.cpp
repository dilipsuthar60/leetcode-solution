class Solution {
public:
    long long all;
    int mod=1e9+7;
    long long dp[41][1ll<<15];
    long long find(vector<vector<int>>&nums,int index,long long mask)
    {
        if(all==mask)
        {
            return 1ll;
        }
        if(index>=41)
        {
            return 0;
        }
        if(dp[index][mask]!=-1)
        {
            return dp[index][mask]%mod;
        }
        long long ans=find(nums,index+1,mask);
        for(auto it:nums[index])
        {
            if((mask&(1<<it))==0)
            {
                ans+=find(nums,index+1,mask|(1ll<<it));
            }
        }
        return dp[index][mask] =ans%mod;
    }
    int numberWays(vector<vector<int>>& hats) 
    {
        memset(dp,-1,sizeof(dp));
        int n=hats.size();
        vector<vector<int>>nums(41);
        for(int i=0;i<n;i++)
        {
            for(const auto &it:hats[i])
            {
                nums[it].push_back(i);
            }
        }
        all=(1ll<<n)-1;
        return find(nums,1,0ll)%mod;
    }
};