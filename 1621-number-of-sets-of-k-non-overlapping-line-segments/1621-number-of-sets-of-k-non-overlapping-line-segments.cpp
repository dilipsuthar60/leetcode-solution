class Solution {
public:
    int mod=1e9+7;
    long long dp[1001][1001][2];
    long long find(int n,int k,int start)
    {
        if(k==0)
        {
            return 1;
        }
        if(n<=0)
        {
            return 0;
        }
        if(dp[n][k][start]!=-1)
        {
            return dp[n][k][start]%mod;
        }
        long long ans=find(n-1,k,start);
        if(start)
        {
            ans+=find(n-1,k,0);
        }
        else if(start==0)
        {
            ans+=find(n,k-1,1);
        }
        return dp[n][k][start]= ans%mod;
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return (int)find(n,k,1)%mod;
    }
};