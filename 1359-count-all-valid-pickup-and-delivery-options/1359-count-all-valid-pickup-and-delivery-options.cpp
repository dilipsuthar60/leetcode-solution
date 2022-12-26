class Solution {
public:
    int mod=1e9+7;
    long long dp[501][501];
    long long find(int p,int d)
    {
        if(p==0&&d==0)
        {
            return 1;
        }
        if(p<0||d<0)
        {
            return 0;
        }
        if(dp[p][d]!=-1)
        {
            return dp[p][d]%mod;
        }
        long long first=p*find(p-1,d+1);
        long long second=d*find(p,d-1);
        return dp[p][d] = (first+second)%mod;
    }
    int countOrders(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return (int)find(n,0)%mod;
    }
};