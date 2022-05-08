class Solution {
public:
    int n,m;
    bool hasValidPath(vector<vector<char>>& mat) 
    {
        vector<pair<int,int>>d={{0,1},{1,0}};
        n=mat.size();
        m=mat[0].size();
        queue<tuple<int,int,int>>q;
        if(mat[0][0]=='(')
        {
        q.push({0,0,1});
        }
        else
        {
            return false;
        }
        int dp[111][111][311];
        memset(dp,-1,sizeof(dp));
        dp[0][0][1]=1;
        while(q.size())
        {
            auto [x,y,b]=q.front();
            q.pop();
            if(b<0)
            {
                continue;
            }
            if(x==n-1&&y==m-1)
            {
                if(b==0)
                {
                    return true;
                }
            }
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(b<0)
                {
                    continue;
                }
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&dp[nx][ny][b]==-1)
                {
                    if(b>=0)
                    dp[nx][ny][b]=1;
                    if(mat[nx][ny]=='(')
                    {
                        q.push({nx,ny,b+1});
                    }
                    else
                    {
                        q.push({nx,ny,b-1});
                    }
                }
            }
        }
        return false;
    }
};