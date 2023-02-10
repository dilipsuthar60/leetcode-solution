class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                {
                    q.push(i*m+j);
                }
            }
        }
        int level=1;
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=-1;
        int size,x,y,nx,ny;
        while(q.size())
        {
             size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                x=temp/m;
                y=temp%m;
                q.pop();
                for(const auto &it:d)
                {
                     nx=x+it.first;
                     ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]==0)
                    {
                        mat[nx][ny]=1;
                        ans=max(ans,level);
                        q.push(nx*m+ny);
                    }
                }
            }
            level++;
        }
        return ans;
    }
};