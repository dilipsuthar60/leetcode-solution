class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>v(n,vector<int>(n,0));
       vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0;
        int t=n*n;
        int count=1;
        int x,y,nx,ny;
        x=y=nx=ny=0;
        auto is_safe=[&](int x,int y)
        {
            return x>=0&&y>=0&&x<n&&y<n&&v[x][y]==0;
        };
        while(t--)
        {
            nx=x+dir[d].first;
            ny=y+dir[d].second;
            if(!is_safe(nx,ny))
            {
                d=(d+1)%4;
                nx=x+dir[d].first;
                ny=y+dir[d].second;
            }
            v[x][y]=count++;
            x=nx;
            y=ny;
        }
        return v;
    }
};