class Solution {
public:
    int n,m;
    int mod=1e9+7;
    vector<vector<vector<int>>>dp;
 long long  find(vector<vector<int>>&mat,int i,int j,int sum,int &k)
    {
     if(i>=n||j>=m)
        {
            return 0;
        }
         if(i==n-1&&j==m-1)
        {
            return ((sum+mat[i][j])%k==0);
        }
     if(dp[i][j][sum]!=-1)
     {
         return dp[i][j][sum];
     }
        long long first=find(mat,i+1,j,(sum+mat[i][j])%k,k);
        long long second=find(mat,i,j+1,(sum+mat[i][j])%k,k);
        return dp[i][j][sum] =(first+second)%mod;;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        return find(grid,0,0,0,k)%mod;
    }
};