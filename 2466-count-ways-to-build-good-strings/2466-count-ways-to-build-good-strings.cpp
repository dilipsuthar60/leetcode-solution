class Solution {
public:
    long long dp[100005];
    int mod=1e9+7;
    int find(int n,int index,int z,int o)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index]%mod;
        }
        long long ans1=0;
        if(index+z<=n)
        ans1=1+find(n,index+z,z,o);
        long long ans2=0;
        if(index+o<=n)
        ans2=1+find(n,index+o,z,o);
        return dp[index]=(ans1+ans2)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        long long ans=0;
        memset(dp,-1,sizeof(dp));
        long long first=find(low-1,0,zero,one);
        memset(dp,-1,sizeof(dp));
        long long second=find(high,0,zero,one);
        // cout<<first<<"  "<<second<<endl;
        return (second-first+mod)%mod;
    }
};