class Solution {
public:
    vector<pair<int,int>>d={{0,-1},{1,0},{0,1},{-1,0}};
    int minFlips(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        set<vector<vector<int>>>vis;
        queue<vector<vector<int>>>q;
        q.push(mat);
        int level=0;
        auto find=[&](vector<vector<int>>&mat)
        {
            int count=0;
            for(auto it:mat)
            {
                for(auto t:it)
                {
                    count+=(t==0);
                }
            }
            return count==n*m;
        };
        auto flip=[&](vector<vector<int>>&mat,int x,int y)
        {
            mat[x][y]^=1;
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m)
                {
                    mat[nx][ny]^=1;
                }
            }
        };
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
            auto temp=q.front();
            q.pop();
            if(find(temp))
            {
                return level;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    vector<vector<int>>m=temp;
                    flip(m,i,j);
                    if(vis.find(m)==vis.end())
                    {
                        q.push(m);
                        vis.insert(m);
                    }
                }
            }
            }
            level++;
        }
        return -1;
    }
};