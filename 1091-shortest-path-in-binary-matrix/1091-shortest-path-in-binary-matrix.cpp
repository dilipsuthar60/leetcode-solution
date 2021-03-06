class Solution {
public:
    vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<int>q;
        q.push(0);
        int level=1;
        if(mat[0][0]==1||mat[n-1][m-1]==1)
        {
            return -1;
        }
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
                if(x==n-1&&y==m-1)
                {
                    return level;
                }
                for(auto &it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(is_safe(nx,ny))
                    {
                        mat[nx][ny]=-1;
                        q.push(nx*m+ny);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};