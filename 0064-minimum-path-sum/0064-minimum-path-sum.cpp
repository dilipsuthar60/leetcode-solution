class Solution {
public:
    int n,m;
    int dp[202][202];
    int find(vector<vector<int>>&mat,int i,int j)
    {
        if(i==n-1&&j==m-1)
        {
            return mat[i][j];
        }
        if(i>=n||j>=m)
        {
            return 1e8;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]= min(mat[i][j]+find(mat,i+1,j),mat[i][j]+find(mat,i,j+1));
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        memset(dp,-1,sizeof(dp));
        n=grid.size();
        m=grid[0].size();
        return find(grid,0,0);
    }
};