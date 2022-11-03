class Solution {
public:
    int find(vector<vector<int>>&dp,int x2,int y2,int x1,int y1)
    {
        return dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1];
        
    }
    bool possibleToStamp(vector<vector<int>>& grid, int sh, int sw) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        vector<vector<int>>arr(n+1,vector<int>(m+1,0));
        vector<vector<int>>brr(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                arr[i][j]=grid[i-1][j-1];
                dp[i][j]=arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i+sh-1<=n&&j+sw-1<=m)
                {
                    brr[i][j]=(find(dp,i+sh-1,j+sw-1,i,j)==0);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=-dp[i-1][j-1]+dp[i-1][j]+dp[i][j-1]+brr[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(arr[i][j])
                {
                    continue;
                }
                int x1=max(1,i-sh+1);
                int y1=max(1,j-sw+1);
                if(find(dp,i,j,x1,y1)==0)
                {
                    return false;
                }
            }
        }
        return true;
    }
};