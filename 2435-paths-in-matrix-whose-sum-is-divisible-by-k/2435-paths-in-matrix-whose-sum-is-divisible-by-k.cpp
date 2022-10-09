class Solution {
public:
    int n,m;
    int mod=1e9+7;
    long long dp[50018][51];
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
     long long hash=i*m+j;
     if(dp[hash][sum]!=-1)
     {
         return dp[hash][sum];
     }
        long long first=find(mat,i+1,j,(sum+mat[i][j])%k,k);
        long long second=find(mat,i,j+1,(sum+mat[i][j])%k,k);
        return dp[hash][sum] =(first+second)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        memset(dp,-1,sizeof(dp));
        m=grid[0].size();
        return find(grid,0,0,0,k)%mod;
    }
};