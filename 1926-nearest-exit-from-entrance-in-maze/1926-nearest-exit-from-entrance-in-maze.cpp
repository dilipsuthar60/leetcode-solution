class Solution {
public:
    int nearestExit(vector<vector<char>>&mat, vector<int>& e) 
    {
        if(e.size()==0)
        {
            return -1;
        }
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e4));
        vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        dp[e[0]][e[1]]=0;
        while(q.size())
        {
                auto temp=q.front();
                q.pop();
                int x=temp.first;
                int y=temp.second;
            if(x==0||y==0||x==n-1||y==m-1)
            {
                if(x!=e[0]||y!=e[1])
                {
                    return dp[x][y];
                }
                
            }
                for(auto it:d)
                {
                    int nx=x+it.first;
                    int ny=y+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]=='.'&&dp[nx][ny]>dp[x][y]+1)
                    {
                        dp[nx][ny]=dp[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            
        }
        return -1;
    }
};