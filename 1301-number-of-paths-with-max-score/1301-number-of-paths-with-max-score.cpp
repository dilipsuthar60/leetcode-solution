class Solution {
public:
    int mod=1e9+7;
    vector<int> pathsWithMaxScore(vector<string>&mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        vector<vector<int>>path(n,vector<int>(m,0));
        path[n-1][m-1]=1;
        dp[n-1][m-1]=0;
        vector<pair<int,int>>dir={{-1,0},{0,-1},{-1,-1}};
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                
                for(auto it:dir)
                {
                    int nx=i+it.first;
                    int ny=j+it.second;
                    int val=dp[i][j];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]!='X')
                    {
                        val+=(mat[nx][ny]!='E')?mat[nx][ny]-'0':0;
                        if(val>dp[nx][ny])
                        {
                            dp[nx][ny]=val;
                            path[nx][ny]=path[i][j];
                        }
                        else if(val==dp[nx][ny])
                        {
                            path[nx][ny]=(path[nx][ny]+path[i][j])%mod;
                        }
                    }
                }
            }
        }
        return {path[0][0]==0?0:dp[0][0],path[0][0]};
    }
};