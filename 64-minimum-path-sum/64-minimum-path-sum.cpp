class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        dp[n][m-1]=0;
        dp[n-1][m]=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=grid[i][j]+min({dp[i+1][j],dp[i][j+1]});
                // if(i==n-1&&j==m-1)
                //     dp[i][j]=grid[i][j];
                // else if(i==n-1)
                // {
                //     dp[i][j]=dp[i][j+1]+grid[i][j];
                // }
                // else if(j==m-1)
                // {
                //     dp[i][j]=dp[i+1][j]+grid[i][j];
                // }
                // else
                //     dp[i][j]=min(dp[i+1][j],dp[i][j+1])+grid[i][j];
            }
        }
        return dp[0][0];
    }
};