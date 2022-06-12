class Solution {
public:
    int dp[101][101];
    int n,m;
    int find(vector<vector<int>>&mat,vector<vector<int>>&move,int i,int j)
    {
        if(i==n-1)
        {
            return mat[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=1e8;
        for(int k=0;k<m;k++)
        {
            ans=min(ans,mat[i][j]+move[mat[i][j]][k]+find(mat,move,i+1,k));
        }
        return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>&mat, vector<vector<int>>& move) 
    {
        memset(dp,-1,sizeof(dp));
        int ans=1e8;
        n=mat.size();
        m=mat[0].size();
        for(int i=0;i<m;i++)
        {
         ans=min(ans,find(mat,move,0,i));
        }
        return ans;
    }
};