class Solution {
public:
    int shortestPath(vector<vector<int>>& mat, int k) 
    {
        vector<pair<int,int>>d={{-1,0},{0,1},{1,0},{0,-1}};
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        dp[0][0]=0;
        int level=0;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                if(x==n-1&&y==m-1)
                {
                    return level;
                }
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&dp[x][y]+mat[nx][ny]<=k&&dp[x][y]+mat[nx][ny]<dp[nx][ny])
                    {
                        dp[nx][ny]=dp[x][y]+mat[nx][ny];
                         q.push({nx,ny});
                    }
                }
            }
            level++;
        }
        return -1;
    }
};