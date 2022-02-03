class Solution {
public:
   static bool cmp(vector<int>&v1,vector<int>&v2)
   {
       if(v1[3]!=v2[3]) return v1[3]<v2[3];
       if(v1[2]!=v2[2]) return v1[2]<v2[2];
       if(v1[0]!=v2[0]) return v1[0]<v2[0];
       return v1[1]<v2[1];
   }
    vector<vector<int>> highestRankedKItems(vector<vector<int>>&mat, vector<int>& p, vector<int>& start, int k) 
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<int,int>>q;
        q.push({start[0],start[1]});
        int level=1;
        int dis[n][m];
        memset(dis,-1,sizeof(dis));
        int vis[n][m];
        memset(vis,-1,sizeof(vis));
        if(mat[start[0]][start[1]]>=p[0]&&mat[start[0]][start[1]]<=p[1])
        {
            dis[start[0]][start[1]]=0;
        }
        vis[start[0]][start[1]]=1;
        while(q.size())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                auto temp=q.front();
                q.pop();
                for(auto it:dir)
                {
                    int nx=temp.first+it.first;
                    int ny=temp.second+it.second;
                    if(nx>=0&&ny>=0&&nx<n&&ny<m&&dis[nx][ny]==-1&&vis[nx][ny]==-1&&mat[nx][ny]!=0)
                    {
                        q.push({nx,ny});
                        if(mat[nx][ny]>=p[0]&&mat[nx][ny]<=p[1])
                        dis[nx][ny]=level;
                        else
                        {
                            vis[nx][ny]=1;
                        }
                    }
                }
            }
            level++;
        }
        vector<vector<int>>ans,ans1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dis[i][j]!=-1)
                {
                    ans.push_back({i,j,mat[i][j],dis[i][j]});
                }
            }
        }
        sort(ans.begin(),ans.end(),cmp);
        for(auto it:ans)
        {
            ans1.push_back({it[0],it[1]});
            if(ans1.size()==k)
            {
                break;
            }
        }
        return ans1;
    }
};