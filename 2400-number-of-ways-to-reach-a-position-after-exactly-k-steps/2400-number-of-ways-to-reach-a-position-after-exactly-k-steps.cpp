class Solution {
public:
    long long dp[4011][2011];
    int mod=1e9+7;
    long long find(int s,int e,int index,int &k)
    {
        if(index>k)
        {
            return 0;
        }
        if(index==k)
        {
            return s==e;
        }
        if(dp[s+1001][index]!=-1)
        {
            return dp[s+1001][index]%mod;
        }
        long long x=find(s+1,e,index+1,k);
        long long y=find(s-1,e,index+1,k);
        return dp[s+1001][index]=(x+y)%mod;
    }
    int numberOfWays(int s, int e, int k) 
    {
        memset(dp,-1,sizeof(dp));
        int b=(int)find(s,e,0,k);
        return b;
    }
};