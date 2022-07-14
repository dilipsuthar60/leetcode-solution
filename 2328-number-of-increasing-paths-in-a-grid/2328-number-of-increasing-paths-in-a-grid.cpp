class Solution {
public:
    int countPaths(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        int dp[n][m],ind[n][m];
        memset(dp,0,sizeof(dp));
        memset(ind,0,sizeof(dp));
        vector<pair<int,int>>d={{-1,0},{1,0},{0,1},{0,-1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                for(auto it:d)
                {
                    dp[i][j]=1;
                    int nx=i+it.first;
                    int ny=j+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[i][j]<mat[nx][ny])
                    {
                        ind[nx][ny]++;
                    }
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(ind[i][j]==0)
                {
                    q.push(i*m+j);
                }
            }
        }
        int mod=1e9+7;
       while(q.size())
       {
           
           int size=q.size();
           while(size--)
         { 
             auto temp=q.front();
            q.pop();
           int x=temp/m;
           int y=temp%m;
           for(auto it:d)
           {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]>mat[x][y])
                {
                    dp[nx][ny]=(dp[nx][ny]+dp[x][y])%mod;
                    --ind[nx][ny];
                    if(ind[nx][ny]==0)
                    {
                        q.push(nx*m+ny);
                    }
                }
           }
         }
       }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};