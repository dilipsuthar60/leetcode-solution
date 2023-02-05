class Solution {
public:
    int n,m;
    vector<vector<int>>find(vector<vector<int>>&mat,int x,int y,int top)
    {
        
        vector<pair<int,int>>d;
        if(top)
        {
            d={{1,0},{0,1}};
        }
        else
        {
            d={{-1,0},{0,-1}};
        }
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[x][y]=1;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            x=temp.first;
            y=temp.second;
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==0&&mat[nx][ny]==1)
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return vis;
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) 
    {
         n=grid.size();
         m=grid[0].size();
        vector<vector<int>>vis1=find(grid,0,0,1);
        vector<vector<int>>vis2=find(grid,n-1,m-1,0);
        vector<int>dp(n+m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis1[i][j]&&vis2[i][j])
                {
                    dp[i+j]++;
                }
            }
        }
        int min_value=1e9;
        for(int i=1;i<n+m-2;i++)
        {
            min_value=min(min_value,dp[i]);
        }
        return min_value<=1;
    }
};