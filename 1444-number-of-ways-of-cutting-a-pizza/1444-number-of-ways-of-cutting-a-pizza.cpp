class Solution {
public:
    int n;
    int m;
    int dp[51][51][51];
    int mod=1e9+7;
    int check(vector<string>&mat,int r,int c,int br,int bc)
    {
        for(int i=r;i<br;i++)
        {
            for(int j=c;j<bc;j++)
            {
                if(mat[i][j]=='A')
                {
                    return true;
                }
            }
        }
        return false;
    }
    int find(vector<string>&mat,int r,int c,int k)
    {
        if(k==1)
        {
            return check(mat,r,c,n,m);
        }
        if(dp[r][c][k]!=-1)
        {
            return dp[r][c][k];
        }
        long long ans=0;
        for(int i=r+1;i<n;i++)
        {
            if(check(mat,r,c,i,m))
            {
               ans+=find(mat,i,c,k-1);
            }
        }
        for(int j=c+1;j<m;j++)
        {
            if(check(mat,r,c,n,j))
            {
               ans+=find(mat,r,j,k-1);
            }
        }
        return dp[r][c][k]=ans%mod;
    }
    int ways(vector<string>& mat, int k) 
    {
        memset(dp,-1,sizeof(dp));
         n=mat.size();
         m=mat[0].size();
        return find(mat,0,0,k);
    }
};