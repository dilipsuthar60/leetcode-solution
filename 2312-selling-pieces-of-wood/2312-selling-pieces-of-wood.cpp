class Solution {
public:
    long long cost[201][201];
    long long dp[201][201];
    long long find(int n,int m)
    {
        if(dp[n][m]!=-1)
        {
            return dp[n][m];
        }
        long long ans=cost[n][m];
        for(int i=1;i<=n/2;i++)
        {
            ans=max(ans,find(i,m)+find(n-i,m));
        }
        for(int j=1;j<=m/2;j++)
        {
            ans=max(ans,find(n,j)+find(n,m-j));
        }
        return dp[n][m]=ans;
    }
    long long sellingWood(int n, int m, vector<vector<int>>& prices) 
    {
        memset(cost,0,sizeof(cost));
        memset(dp,-1,sizeof(dp));
        for(auto &it:prices)
        {
            cost[it[0]][it[1]]=it[2];
        }
        return find(n,m);
    }
};