class Solution {
public:
     
    int n,m;
  
    int minPathCost(vector<vector<int>>&mat, vector<vector<int>>& move) 
    {
        int ans=1e8;
        n=mat.size();
        m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e8));
        dp[0]=mat[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(int k=0;k<m;k++)
                {
                    dp[i][j]=min(dp[i][j],mat[i][j]+dp[i-1][k]+move[mat[i-1][k]][j]);
                }
                if(i==n-1)
                {
                  ans=min(ans,dp[i][j]);
                }
            }
        }
        return ans;
        
    }
};