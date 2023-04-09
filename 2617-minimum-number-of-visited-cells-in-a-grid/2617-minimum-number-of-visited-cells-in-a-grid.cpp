class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>&mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<int>row(n,0),col(m,0);
        queue<pair<int,int>>q;
        q.push({0,0});
        int level=1;
        row[0]=1;
        col[0]=1;
        while(q.size())
        {
            int size=q.size();
            while(size--)
            {
                auto [x,y]=q.front();
                q.pop();
                if(x==n-1&&y==m-1)
                {
                    return level;
                }
                for(int k=max(row[x],y+1);k<=min(mat[x][y]+y,m-1);k++)
                {
                    q.push({x,k});
                }
                row[x]=max(row[x],min(mat[x][y]+y,m-1));
                for(int k=max(col[y],x+1);k<=min(mat[x][y]+x,n-1);k++)
                {
                    q.push({k,y});
                }
                col[y]=max(col[y],min(mat[x][y]+x,n-1));
            }
            level++;
        }
        return -1;
    }
};