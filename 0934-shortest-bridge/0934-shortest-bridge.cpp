class Solution {
public:
    void find(vector<vector<int>>&mat,int i,int j,int p)
    {
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]==0||mat[i][j]==p)
        {
            return ;
        }
        mat[i][j]=p;
        // v.push_back({i,j});
        find(mat,i-1,j,p);
        find(mat,i+1,j,p);
        find(mat,i,j-1,p);
        find(mat,i,j+1,p);
    }
    int shortestBridge(vector<vector<int>>& mat)
    {
        if(mat.empty())
        {
            return 0;
        }
        int f=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1&&f)
                {
                    find(mat,i,j,2);
                    f=0;
                }
            }
        }
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int level=0;
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
                if(mat[x][y]==2)
                {
                    return level-1;
                }
                for(auto it:dir)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==0)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};