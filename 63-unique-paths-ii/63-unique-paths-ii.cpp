class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mat[i-1][j-1]==0)
                {
                    dp[i][j]=(i==1&&j==1)?1:dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[n][m];
                      
    }
};