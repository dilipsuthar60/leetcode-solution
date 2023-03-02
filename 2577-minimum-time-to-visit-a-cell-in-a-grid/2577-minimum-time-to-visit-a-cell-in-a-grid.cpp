class Solution {
public:
    int minimumTime(vector<vector<int>>& mat) 
    {
        if(mat[0][1]>1&&mat[1][0]>1)
        {
            return -1;
        }
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int vis[n][m];
        memset(vis,0,sizeof(vis));
        while(pq.size())
        {
            auto [time,xy]=pq.top();
            pq.pop();
            int x=xy/m;
            int y=xy%m;
            if(x==n-1&&y==m-1)
            {
                return time;
            }
            if(vis[x][y])
            {
                continue;
            }
            vis[x][y]=1;
            for(auto &it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m)
                {
                    if(mat[nx][ny]<=time+1)
                    {
                        pq.push({time+1,nx*m+ny});
                    }
                    else
                    {
                        int diff=(mat[nx][ny]-time);
                        if(diff%2==0)
                        {
                            pq.push({mat[nx][ny]+1,nx*m+ny});
                        }
                        else
                        {
                            pq.push({mat[nx][ny],nx*m+ny});
                        }
                    }
                }
            }
        }
        return -1;
    }
};