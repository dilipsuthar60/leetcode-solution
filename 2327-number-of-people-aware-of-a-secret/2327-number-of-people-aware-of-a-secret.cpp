class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) 
    {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(i-j>=d&&i-j<f)
                {
                    dp[i]=(dp[i]+dp[j])%mod;
                }
            }
        }
        int count=0;
        for(int i=max(0,n-f+1);i<=n;i++)
        {
            count=(count+dp[i])%mod;
        }
        return count;
    }
};