class Solution {
public:
    long long dp[31][1001];
    int mod=1e9+7;
    long long find(int n,int k,int target)
    {
        if(n==0)
        {
            return target==0;
        }
        if(target<0)
        {
            return 0;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target]%mod;
        }
        long long ans=0;
        for(int i=1;i<=k;i++)
        {
            ans+=find(n-1,k,target-i);
        }
        return dp[n][target]= ans%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
       memset(dp,-1,sizeof(dp));
        return (int)find(n,k,target)%mod;
    }
};