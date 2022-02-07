class Solution {
public:
      
    int knightDialer(int n) 
    {
        vector<vector<int>>dir={{4,6},{8,6},{9,7},{4,8},{3,9,0},{},{0,1,7},{2,6},{1,3},{2,4}};
        vector<vector<int>>dp(n+1,vector<int>(10,0));
        for(int i=0;i<10;i++)
        {
            dp[1][i]=1;
        }
        int mod=1e9+7;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<10;j++)
            {
                for(auto it:dir[j])
                {
                    dp[i][j]=(dp[i][j]+dp[i-1][it])%mod;
                }
            }
        }
        int sum=0;
        for(int i=0;i<10;i++)
        {
            sum=(sum+dp[n][i])%mod;
        }
        return sum;
    }
};