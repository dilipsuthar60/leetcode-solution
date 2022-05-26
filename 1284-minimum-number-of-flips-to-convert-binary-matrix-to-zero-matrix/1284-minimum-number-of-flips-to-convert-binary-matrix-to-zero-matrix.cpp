class Solution {
public:
    vector<pair<int,int>>d={{0,0},{0,-1},{1,0},{0,1},{-1,0}};
    int minFlips(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int m=mat[0].size();
        set<int>vis;
        queue<int>q;
        int mask=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                mask|=(mat[i][j]<<(i*m+j));
            }
        }
        q.push(mask);
        int level=0;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
            auto temp=q.front();
            q.pop();
            if(temp==0)
            {
                return level;
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                   int curr=temp;
                    for(auto it:d)
                    {
                        int nx=i+it.first;
                        int ny=j+it.second;
                        if(nx>=0&&ny>=0&&nx<n&&ny<m)
                        {
                           curr^=(1<<(nx*m+ny));
                        }
                    }
                    if(vis.find(curr)==vis.end())
                    {
                        q.push(curr);
                        vis.insert(curr);
                    }
                }
            }
            }
            level++;
        }
        return -1;
    }
};