class Solution {
public:
    int dp[10005];
    int find(int target)
    {
        if(target==0)
        {
            return 0;
        }
        if(target<0)
        {
            return 1e9;
        }
        if(dp[target]!=-1)
        {
            return dp[target];
        }
        int ans=1e9;
        for(int i=1;i*i<=target;i++)
        {
            ans=min(ans,1+find(target-i*i));
        }
        return dp[target]=ans;
    }
    int numSquares(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return find(n);
    }
};