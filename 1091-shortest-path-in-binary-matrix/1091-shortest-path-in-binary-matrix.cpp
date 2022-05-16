class Solution {
public:
    vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<int>q;
        q.push(0);
        int level=2;
        vector<vector<int>>dis(n,vector<int>(m,-1));
        if(mat[0][0]==1||mat[n-1][m-1]==1)
        {
            return -1;
        }
        dis[0][0]=1;
        auto is_safe=[&](int x,int y)
        {
            return x>=0&&y>=0&&x<n&&y<m&&mat[x][y]==0;
        };
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto temp=q.front();
                q.pop();
                int x=temp/m;
                int y=temp%m;
                for(auto &it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(is_safe(nx,ny)&&dis[nx][ny]==-1)
                    {
                        dis[nx][ny]=level;
                        q.push(nx*m+ny);
                    }
                }
            }
            level++;
        }
        return dis[n-1][m-1];
    }
};