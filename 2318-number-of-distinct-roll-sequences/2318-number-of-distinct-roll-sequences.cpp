class Solution {
public:
    int dp[10004][7][7];
    int mod=1e9+7;
    int find(int n,int index,int prev1,int prev2)
    {
        if(index==n)
        {
            return 1;
        }
        if(dp[index][prev1][prev2]!=-1)
        {
            return dp[index][prev1][prev2]%mod;
        }
        int ans=0;
        for(int i=1;i<=6;i++)
        {
            if(prev1!=i&&prev2!=i&&(prev1==0||(__gcd(i,prev1)==1)))
            {
                ans=(ans+find(n,index+1,i,prev1))%mod;
            }
        }
        return dp[index][prev1][prev2]=ans%mod;
    }
    int distinctSequences(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return find(n,0,0,0);
    }
};